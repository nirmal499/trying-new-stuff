#include <iostream>
#include <memory>
using namespace std;

/* 
1. empty(): Returns a bool to indicate whether the queue is empty.
2. size(): Returns the queue's current size or number of elements.
3. front() and back(): Return a pointer to the first and last elements in the queue, respectively.
4. push(element) and pop(): Push an element to the end of the queue and delete the first element, respectively.
*/

/* Suppose Queue is : [Q1, Q2, Q3, Q4], _
    Brackets show the allocated memory
    first() returns a pointer which points to Q1
    back() returns a pointer which points to Q4
 */
template <class T>
class Queue
{
private:
    T *queueData;    // points to first element
    T *queueDataEnd; // points one past the last element

    // the allocator object
    allocator<T> alloc;

    T *memLimit; // one past the end of allocated memory

    /* The init functions will make use of two functions contained in the <memory> header: 
        uninitialized_fill and uninitialized_copy. Now, uninitialized_fill copies a value to an 
        uninitialized memory area defined by a range [first, last), and uninitialized_copy copies a range
        of values [first, last) to an uninitialized memory area.
    */
    void init()
    {
        queueData = queueDataEnd = memLimit = 0;
    }
    /* This second init function allocates sufficientmemory to hold numElements of our T objects */
    void init(size_t numElements, const T &initialValue)
    {
        /* From the allocate function, it returns a pointer to the first element of our data. */
        queueData = alloc.allocate(numElements);
        /* These will now both point to one past the last constructed element, which, at this point, 
        is one past the allocated memory */
        queueDataEnd = memLimit = queueData + numElements;
        /* we use uninitialized_fill to copy the initial element into the memory chunk using 
        queueData and queueDataEnd as the first and last in the range, respectively */
        uninitialized_fill(queueData, queueDataEnd, initialValue);
    }

    /* Used in Copy Constructor */
    void init(T *front, T *back)
    {
        queueData = alloc.allocate(back - front);
        memLimit = queueDataEnd = uninitialized_copy(front, back, queueData);
    }

    /* it uses the destroy allocator and deallocates functions to clean up our class */
    void destroy()
    {
        if (queueData != 0)
        {
            T *it = queueDataEnd;
            while (it != queueData)
            {
                alloc.destroy(--it);
            }
            /* This function loops backward through our queueData, calls the destructor of
                any constructed elements, and then uses the deallocate function to free the
                allocated memory. The second parameter into deallocate is the size of the memory
                we wish to free. We kept track of the first and one past the allocated memory so\
                that we can get the pointer difference and use that as the second parameter of the
                deallocate function 
            */
            alloc.deallocate(queueData, memLimit - queueData);
        }
        queueData = queueDataEnd = memLimit = 0;
    }

    /* functions that will resize our memory chunk, when needed, and construct objects in the available memory 
        As outlined previously, we are going to double the amount of allocated memory whenever the queue is resized
    */
    void resize()
    {
        /* The resize() function first calculates how much memory will need to be allocated
            and, since the queue could be empty, it uses the max function to ensure that we
            are always allocating enough space for at least one element (2 multiplied by 0 is still 0) 
        */
        /* Subtracting one pointer from another gives the number of elements
            between the locations of those two pointers; this value is of the ptrdiff_t type 
        */
        size_t newSize = max(2 * (queueDataEnd - queueData), ptrdiff_t(1));

        /* This newSize amount of memory is then allocated using the allocator, and uninitialized_copy 
            copies the existing queueData into the new memory area. The destroy function is then 
            called to delete the existing data before reassigning the new pointers to our member pointers 
        */
        T *newData = alloc.allocate(newSize);
        T *newDataEnd = uninitialized_copy(queueData, queueDataEnd, newData);
        destroy();
        queueData = newData;
        queueDataEnd = newDataEnd;
        memLimit = queueData + newSize;
        /* queueData points to the first element 
           queuDataEnd points to one past the last element
           memLimit points to the one past the end of allocated memory
        */
    }
    void append(const T &newValue)
    {
        /* append() uses the construct function of the allocator to construct an element in the first available space in the allocated memory, after the constructed elements */
        alloc.construct(queueDataEnd++, newValue);
    }

public:
    Queue() { init(); }
    /*  The explicit keyword is also used to ensure that the
        compiler cannot implicitly construct this type to convert from one type to another if
        passed as a parameter 
    */
    explicit Queue(size_t numElements, const T &initialValue = T())
    {
        init(numElements, initialValue);
    }
    ~Queue() { destroy(); }

    /* Queue q1 = q2; */
    Queue(const Queue &q) { init(q.front(), q.back()); }

    /*  Queue q1;
        Queue q2;
        q2 = q1;
     */
    Queue &operator=(const Queue &rhs)
    {
        if (this != &rhs)
        {
            destroy();
            init(rhs.front(), rhs.back());
        }
    }

    /* Notice that there are const and non-const versions of the front() and back()
        member functions. This allows us to use both const and non-const queues */
    T *front() { return queueData; }
    //const T *front() { return queueData; }

    T *back() { return queueDataEnd - 1; }
    //const T *back() const { return queueDataEnd - 1; }

    bool empty() const { return size() == 0; }

    size_t size() const { return queueDataEnd - queueData; }
    size_t allocatedSize() const { return queueData - memLimit; }

    /* when pop is called, the first element that was pushed into the container will be the first to be 
        removed. What this means is that we need to destroy
        the first element in our queue and then shift all the remaining elements across and also
        decrement the pointer to the last element (queueDataEnd) 
    */
    void pop()
    {
        if (queueData != 0)
        {
            alloc.destroy(queueData);
            for (int i = 0; i < size(); i++)
            {
                queueData[i] = queueData[i + 1];
                //cout << queueData[i] << "\n";
            }
            queueDataEnd -= 1;
        }
    }

    /* If there is sufficient space in our allocated memory, then the queue will not be resized.
        Either way, an element will be appended to the queue. Calling append after a call to
        resize (if needed) ensures that we will have enough space to do the append without
        checking first 
    */
    void push(const T &element)
    {
        if (queueDataEnd == memLimit)
        {
            resize();
        }
        append(element);
    }
};

int main()
{
    Queue<int> testQueue;
    testQueue.push(1);
    testQueue.push(2);
    testQueue.push(3);
    testQueue.push(4);

    testQueue.pop();
    cout << "Size is : " << testQueue.size() << endl;
    cout << "Allocated Size is : " << testQueue.allocatedSize() << endl;

    cout << "queue contains values: ";
    for (auto it = testQueue.front(); it != testQueue.back() + 1; ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "Is the Queue empty: " << (testQueue.empty() == 1 ? "YES" : "NO") << endl;
    cout << "value of first element is: " << *testQueue.front() << endl;
    //cout << "value of last element is: " << *(testQueue.back() + 2) << endl;
    cout << "value of last element is: " << *testQueue.back() << endl;

    return 0;
}
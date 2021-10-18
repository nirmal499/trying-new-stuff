/* printarray() also takes as an argument a reference to int that is set by
printarray() to a count of those strings that are not nullptr. Also, printarray()
outputs strings that are not nullptr to the console, one string per line. printarray()
returns 1 if it runs successfully, and 0 if it detects a problem with the arguments. The
array has a maximum size of 26 elements */

#include <iostream>
using namespace std;

/* printarray() takes as an argument a reference to int that is set by printarray() to a count of those strings that are not nullptr */
int printarray(char const **begin, char const **end, int &count)
{
    if (begin == nullptr || end == nullptr || begin > end || end - begin > 26)
    {
        return 0;
    }
    for (count = 0; begin < end; ++begin)
    {
        if (*begin != nullptr)
        {
            ++count;
            cout << *begin << endl;
        }
    }
    return 1;
}

int main()
{
    /* The array has a maximum size of 26 elements */
    /* All the remaining elements in the array are nullptr */
    char const *array[26]{"alpha", "bravo", "charlie", "delta", "echo"};
    int count;

    if (printarray(nullptr, nullptr, count) == 0 || count != 0)
    {
        cout << "error in printarray() call 1" << endl;
    }
    else
    {
        cout << "count = " << count << endl;
    }

    if (printarray(array, &array[4], count) == 0 || count != 4)
    {
        cout << "error in printarray() call 2" << endl;
    }
    else
    {
        cout << "count = " << count << endl;
    }

    if (printarray(&array[4], &array[3], count) == 0 || count != 0)
    {
        cout << "error in printarray() call 3" << endl;
    }
    else
    {
        cout << "count = " << count << endl;
    }

    if (printarray(&array[4], &array[10], count) == 0 || count != 1)
    {
        cout << "error in printarray() call 4" << endl;
    }
    else
    {
        cout << "count = " << count << endl;
    }

    if (printarray(&array[0], &array[100], count) == 0 || count != 0)
    {
        cout << "error in printarray() call 5" << endl;
    }
    else
    {
        cout << "count = " << count << endl;
    }
    return 0;
}
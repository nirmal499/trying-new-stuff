#include <iostream>
#include <algorithm> // std::find
#include <vector>

using namespace std;

// long contains(const int value, const vector<int> &vec)
// {
//     /*  If no element matches the criteria, then an iterator to the end of the vector is returned. */
//     vector<int>::const_iterator it = find(vec.begin(), vec.end(), value);
//     if (it != vec.end())
//     {
//         // we found the element
//         return distance(vec.begin(), it);
//         /* we can use the std::distance function to return the index of the
//             element within the vector by getting the offset from the beginning of the vector to
//             the found element
//         */
//     }
//     return -1;
// }

template <typename T>
long contains(const T &value, const vector<T> &vec)
{
    /* Here, we replaced the int iterator with the auto keyword. This means we will be
        given the correct type of iterator even though it is not explicitly typed
     */
    auto it = find(vec.begin(), vec.end(), value);
    if (it != vec.end()) // we found the element
        return distance(vec.begin(), it);
    return -1;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int numToCheck = 9;
    long index = contains(numToCheck, vec);
    cout << "Vector contains " << numToCheck << " "
         << (index != -1 ? "YES" : "NO");
    if (index != -1)
        cout << " and its index is " << index;
    cout << endl;
    return 0;
}
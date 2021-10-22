#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool noSpacePredicate(const char &c)
{
    return ispunct(c) || isspace(c);
}

int main()
{
    string str = "Never odd or even";
    string str1 = "Never odd or even";
    string str2 = "Never odd or even";

    // string::iterator it1 = str.begin(); // Returns iterator points to first element
    // string::iterator it2 = str.end(); // Returns iterator points location next to last element
    // cout << *it1 << endl; // -> 'N'
    // cout << *it2 << endl; // -> nothing

    /* The remove_if algorithm shifts any elements that do not satisfy the predicate 
        to the end of the container, and leaves the elements that do in a range at the
        start of the container. It then returns an iterator we can use that points to the last
        element in the range we want[ iterator which points to the end of the desired part]
        e.g "Never odd or even" -> "Neveroddoreven   "
        returned iterator will point to the memory location after 'n'
    */
    string::iterator itend = remove_if(str.begin(), str.end(), noSpacePredicate);

    /* Here the we passing the predicate as lambda function */
    // string::iterator itend = remove_if(str.begin(), str.end(), [](const char &c)
    //                                    { return ispunct(c) || isspace(c); });
    for (string::iterator it = str.begin(); it != itend; it++)
    {
        cout << *it;
    }

    cout << endl;

    str1.erase(str1.begin() + 7, str1.end());
    cout << str1 << endl;

    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    cout << str2 << endl;

    return 0;
}
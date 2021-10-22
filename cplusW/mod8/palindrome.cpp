#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(const string &str)
{
    // make a copy of the string
    string s(str.begin(), str.end());

    /*  remove_if returns an iterator we can use that points to the last
        element in the range we want. We can use this iterator as the first parameter into
        the string's erase function to delete all the elements past the range we care about 
    */
    // remove any spaces or punctuation
    s.erase(remove_if(s.begin(), s.end(), [](const char &c)
                      { return ispunct(c) || isspace(c); }),
            s.end());
    /* In remove_if we are passing a predicate using lambda */

    // lower case what's left
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    // create a reversed version of the string
    string sr(s.rbegin(), s.rend());

    // compare them
    return (s == sr);
}

int main()
{
    string str = "Never odd or even";
    cout << "'" << str << "'"
         << " is a palindrome? "
         << (isPalindrome(str) ? "YES" : "NO") << endl;
    return 0;
}
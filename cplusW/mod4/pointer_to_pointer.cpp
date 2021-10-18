#include <iostream>

int main()
{
    /* In C++, a literal string is of type pointer to const char. An array of literal strings,
       therefore, has type pointer to pointer to const char.

       The declarator const char means that the program may not change the pointed-to
       characters. In C, literal strings were of type pointer to char. C++ was originally that way
       as well, but C++ was updated to make these strings pointers to const char instead

   */
    char const *alphabet[26]{
        "alpha",
        "bravo",
        "charlie",
        "delta",
        "echo",
        "foxtrot"};
    /* However, only the first six array entries are initialized; the compiler sets the remaining 20 entries to nullptr.
        Making the last entry in an array of pointers nullptr is another way to provide
        a loop termination condition. */
    for (char const **p = alphabet; *p != nullptr; ++p)
    {
        std::cout << *p << " ";
    }
    /* At first iteration of loop, **p points to "a" ; *p points to "alpha" */
    std::cout << "\n";

    return 0;
}
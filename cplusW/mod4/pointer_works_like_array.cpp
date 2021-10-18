/* If p points to
a[2], then the expression p[3] fetches the sixth entry in the array (that is, the one
at a[5]). */

#include <iostream>

int main()
{
    int a[7]{1, 3, 5, 4, 2, 9, -1};
    int *p = nullptr;

    p = &a[2];
    /* Now p points to -> [5, 4, 2, 9, -1] */
    std::cout << "*p = " << *p << ", a[2] = " << a[2] << "\n";
    std::cout << "p[3] = " << p[3] << ", a[5] = " << a[5] << "\n";

    /* Incrementig pointers */
    /* 1st way */
    for (p = &a[0]; p < &a[7]; p = p + 1)
    {
        std::cout << *p << " ";
    }
    std::cout << "\n";

    /* 2nd way */
    for (p = &a[0]; p <= &a[6]; p = p + 1)
    {
        std::cout << *p << " ";
    }
    std::cout << "\n";

    /* 3rd way When we not know the size of the array*/
    for (p = &a[0]; p < a + (sizeof(a) / sizeof(a[0])); ++p)
    {
        std::cout << *p << " ";
    }
    std::cout << "\n";

    return 0;
}
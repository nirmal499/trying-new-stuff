#include <iostream>

int main()
{
    int numbers[5]{0, 100, 200, 300, 400};
    int *pint = numbers;
    int *p2 = &numbers[3];
    std::cout << "pint = " << pint << ", pint+1 = " << pint + 1 << ", sizeof(int) =  " << sizeof(int) << "\n";
    std::cout << "*(pint+1) = " << *(pint + 1) << ", pint[1] = " << pint[1] << "\n";
    std::cout << "*(pint+4) = " << *(pint + 4) << ", pint[4] = " << pint[4] << "\n";
    std::cout << "p2 - pint = " << p2 - pint << "\n";
    /* The output manipulator boolalpha causes expressions of type bool to print as true or false.  */
    std::cout << "p2 == pint = " << std::boolalpha << (p2 == pint) << "\n";
    std::cout << "p2 > pint = " << std::boolalpha << (p2 > pint) << "\n";

        return 0;
}
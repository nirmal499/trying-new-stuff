#include <iostream>

int main()
{
    int i = 10;
    int &ir = i;
    i = i + 10;
    ir = ir * 10;

    std::cout << "i = " << i << "\n";

    int *ip = &ir;
    *ip = 33;

    std::cout << "i = " << i << ", *ip = " << *ip << ", ir = " << ir << "\n";
}
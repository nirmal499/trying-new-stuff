#include <iostream>

void modify(int &a)
{
    a = a - 1;
}

int main()
{
    int a = 10;
    modify(a);
    std::cout << a << "\n";
    return 0;
}
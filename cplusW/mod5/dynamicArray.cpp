#include <iostream>
#include <cstring>

int main()
{
    char const *s = "Hello";
    char *buffer = new char[strlen(s) + 1];
    strcpy(buffer, s);
    std::cout << "Buffer = " << buffer << "\n";
    delete[] buffer;

    return 0;
}
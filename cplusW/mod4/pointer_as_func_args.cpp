#include <iostream>

void copychars(char *from, char *to, int count)
{
    if (from == nullptr || to == nullptr)
    {
        return;
    }

    /* count :- 7,6,5,4,3,2,1 */
    while (count-- > 0)
    {
        *to++ = *from++;
    }
}

int main()
{
    char string[]{"uvwxyz"};
    char buffer[10];

    copychars(string, buffer, 7);
    std::cout << buffer << "\n";
    return 0;
}
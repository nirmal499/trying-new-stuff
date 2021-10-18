#include <iostream>
#include <string>
#include <bitset>

int main()
{
    int myInt1 = 6;  // 00110 when expressed in binary
    int myInt2 = 12; // 01100 when expressed in binary

    /* Binary AND or Bitwise AND */
    std::cout << std::bitset<5>(myInt1 & myInt2) << "\n";

    std::cout << std::bitset<5>(myInt1 | myInt2) << "\n";

    std::cout << std::bitset<5>(~myInt1) << "\n";

    std::cout << std::bitset<5>(myInt1 << 2) << "\n";

    std::cout << std::bitset<5>(myInt1 >> 2) << "\n";

    /* Odd no.of ones outputs 1 
        00 -> 0
        11 -> 0
        01 -> 1
        10 -> 1
    */
    std::cout << std::bitset<5>(myInt1 ^ myInt2) << "\n";

    /* The value of 5 in std::bitset<5> denotes the number of bits in the bitset */
}
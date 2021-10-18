/* Write a program that will output the numbers 1 to 100. For multiples of 3, print the word "Fizz" instead of the number,
and for multiples of 5, print the word "Buzz */

/* Output:
1, 2, Fizz, 4, Buzz, Fizz, 7, 8, Fizz, Buzz, 11, Fizz, 13, 14, FizzBuzz, 16, 17 ... 
 */

#include <iostream>
#include <string>

int main()
{
    // std::string fizz = "Fizz";
    // std::string buzz = "Buzz";
    // std::string fizzbuzz = "FizzBuzz";
    for (int i = 1; i <= 100; i++)
    {
        bool multiple = false;
        if (i % 3 == 0)
        {
            std::cout << "Fizz";
            multiple = true;
        }
        if (i % 5 == 0)
        {
            std::cout << "Buzz";
            multiple = true;
        }
        if (!multiple)
        {
            std::cout << i;
        }

        if (i != 100)
        {
            std::cout << ", ";
        }
    }
    std::cout << "\n";

    return 0;
}

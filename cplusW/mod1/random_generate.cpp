#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

int main()
{
    bool isRunning = true;
    std::string input = "";
    int count = 0;
    std::cout << "****Random Number generator****\n";
    while (isRunning)
    {
        std::cout << "Enter amount of numbers to be generated or 0 to exit: ";
        getline(std::cin, input);
        count = std::stoi(input);

        if (count == 0)
        {
            break;
        }

        /* Generate and output random numbers */
        srand((unsigned)time(0));
        for (int i = 0; i < count; i++)
        {
            /* generating random numbers between 0 to 9 */
            std::cout << rand() % 10;
            if (i == count - 1)
            {
                continue;
            }
            std::cout << ", ";
        }

        std::cout << "\n\n";
    }
    return 0;
}
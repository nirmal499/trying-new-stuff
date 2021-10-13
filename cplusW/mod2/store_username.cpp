#include <iostream>
#include <string>
#include <array>

#define NAME_COUNT 5

int main()
{
    //std::string names[NAME_COUNT][2]{""};
    std::array<std::array<std::string, 2>, NAME_COUNT> names{""};
    /* rows is NAME_COUNT
        cols is 2
     */
    std::cout << "Please input usernames. \n";
    for (int i = 0; i < NAME_COUNT; i++)
    {
        std::cout << "\n***********ENTER NAME FOR INDEX"
                  << "[ " << i << " ]"
                  << "*************\n";
        std::cout << "User " << i + 1 << " Forename: ";
        std::getline(std::cin, names[i][0]);
        std::cout << "User " << i + 1 << " Surname: ";
        std::getline(std::cin, names[i][1]);
    }

    bool isRunning = true;
    while (isRunning)
    {
        int userIndex = 0;
        std::string inputString = "";
        std::cout << "Enter user-id of user to fetch or -1 to quit: ";
        std::getline(std::cin, inputString);
        userIndex = std::stoi(inputString);

        if (userIndex == -1)
        {
            isRunning = false;
        }
        else
        {
            if (userIndex >= 0 && userIndex < NAME_COUNT)
            {
                std::cout << "User " << userIndex << " = " << names[userIndex][0] << " "
                          << names[userIndex][1] << "\n";
            }
            else
            {
                std::cout << "Invalid user index\n";
            }
        }
    }

    return 0;
}
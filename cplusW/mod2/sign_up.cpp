
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

struct Person
{
    int age = 0;
    std::string name = "";
};

/* Instead of struct we could have used class also in that case
    we would not have to pass records vector in the corresponding functions
 */

void AddRecord(std::vector<Person> &records, std::string newName, int newAge)
{
    Person newRecord;
    newRecord.name = newName;
    newRecord.age = newAge;
    records.push_back(newRecord);
    std::cout << "\nUser record added successfully.\n\n";
};

Person FetchRecord(std::vector<Person> &records, int userID)
{
    /* userID starts from 0 
        We could have used records[userID].
        But the key difference here is that if we pass an out-of-bounds index to the at function, 
        instead of undefined behavior, the function will throw an exception
    */
    return records.at(userID);
    /* Exceptions allow us to catch and handle errors in a safe way without causing our applications to crash */
};

int main()
{
    std::vector<Person> records;

    std::cout << "User SignUp Application\n";
    bool isRunning = true;
    while (isRunning)
    {
        std::cout << "\n\n*******Please select an option:**********\n";
        std::cout << "1: Add Record\n";
        std::cout << "2: Fetch Record\n";
        std::cout << "3: Quit\n\n";
        std::cout << "Enter option: ";
        std::string inputString;
        std::getline(std::cin, inputString);
        //Determine user selection.
        switch (std::stoi(inputString))
        {
        case 1:
        {
            std::string name = "";
            int age = 0;
            std::cout << "\nAdd User. Please enter user name and age:\n";
            std::cout << "Name: ";
            std::getline(std::cin, name);
            std::cout << "Age: ";
            std::getline(std::cin, inputString);
            age = std::stoi(inputString);
            AddRecord(records, name, age);
        }
        break;
        case 2:
        {
            int userID = 0;
            std::cout << "\nPlease enter user ID:\n";
            std::cout << "User ID: ";
            std::getline(std::cin, inputString);
            userID = std::stoi(inputString);
            Person person;
            try
            {
                person = FetchRecord(records, userID);
            }
            catch (const std::out_of_range &oor)
            {
                std::cout << "\nError: Invalid UserID.\n\n";
                /* This break will shift the flow of control
                    to the end of switch case block [label: Here]
                 */
                break;
            }
            std::cout << "User Name: " << person.name << "\n";
            std::cout << "User Age: " << person.age << "\n\n";
        }
        break;
        case 3:
            isRunning = false;
            break;
        default:
            std::cout << "\n\nError: Invalid option selection.\n\n";
            break;
        }
        /* Here */
    }
}
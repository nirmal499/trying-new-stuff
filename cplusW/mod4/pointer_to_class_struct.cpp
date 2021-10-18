#include <iostream>

struct mydata
{
    char const *name;
    bool hero;
};

void printdata(mydata *p)
{
    std::cout << "Hello. I am " << (*p).name << ". ";
    if (p->hero)
    {
        std::cout << "I am a hero."
                  << "\n";
    }
    else
    {
        std::cout << "I am a villain."
                  << "\n";
    }
}

int main()
{
    mydata heroes[]{

        {"Spider Man", true},
        {"The Joker", false},
        {"Doctor Octopus", false},
        {"Thor", true},
        {"Batman", true},
        {"Loki", false}

    };

    std::cout << sizeof(mydata) << " " << sizeof(mydata *) << "\n";
    for (mydata *p = heroes; p < heroes + (sizeof(heroes) / sizeof(heroes[0])); ++p)
    {
        printdata(p);
        std::cout << "---------------------------------------------------------"
                  << "\n";
    }
    return 0;
}
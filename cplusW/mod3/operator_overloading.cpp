#include <iostream>
#include <string>

class Person
{

    float age = 0;
    std::string name = "";

public:
    Person(int age, std::string name) : age(age), name(name){};
    /* Constructor is placed under public access specifier */

    bool operator==(Person const &other)
    {
        return ((age == other.age) && (name == other.name));
    }
};

int main()
{
    Person PersonA = Person(27, "Lucy");
    Person PersonB = Person(27, "Lucy");
    Person PersonC = Person(27, "Susan");
    std::cout << ((PersonA == PersonB) ? "True" : "False") << "\n";
    std::cout << ((PersonB == PersonC) ? "True" : "False") << "\n";
    return 0;
}
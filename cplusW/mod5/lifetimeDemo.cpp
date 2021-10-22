#include <iostream>

class Noise
{
    char const *s_;

public:
    Noise(char const *s) : s_(s)
    {
        std::cout << "Constructing " << s_ << "\n";
    }
    ~Noise()
    {
        std::cout << "Destructing " << s_ << "\n";
    }
};

void func(char const *s)
{
    Noise obj(s);
}

Noise obj("Global 1");
Noise obj1("Global 2");

int main()
{
    Noise obj2("Main() function local 1");
    func("Function local 2");
    {
        Noise obj3("Block Local 3");
        func("Function Local 3");
    }
    return 0;
}
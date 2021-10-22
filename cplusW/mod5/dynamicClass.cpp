#include <iostream>

class Noise
{
    int i_;

public:
    Noise(int i) : i_(i)
    {
        std::cout << "Constructing Noise " << i_ << "\n";
    }
    ~Noise()
    {
        std::cout << "Destructing Noise " << i_ << "\n";
    }
};

int main()
{
    Noise N(1);
    Noise *p = new Noise(2);
    delete p;
    return 0;
}
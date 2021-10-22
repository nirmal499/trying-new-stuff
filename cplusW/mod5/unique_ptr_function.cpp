#include <iostream>
#include <memory>

struct Noise
{
    Noise() { std::cout << "constructing Noise" << std::endl; }
    ~Noise() { std::cout << "destroying Noise" << std::endl; }
};

/* unique_ptr<> can be used when a function returns to indicate that the caller must
    take ownership of the returned dynamic variable
*/
std::unique_ptr<Noise> func()
{
    return std::make_unique<Noise>();
}

int main()
{
    auto u1 = func();
    return 0;
}
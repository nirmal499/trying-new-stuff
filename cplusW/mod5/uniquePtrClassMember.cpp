#include <iostream>
#include <memory>
#include <cstring>

struct Noise
{
    Noise()
    {
        std::cout << "Constructing Noise\n";
    }
    ~Noise()
    {
        std::cout << "Destructing Noise\n";
    }
};

class Autobuf
{
    std::unique_ptr<Noise> np_;
    std::unique_ptr<char[]> ptr_;

public:
    Autobuf(char const *str);
    char *get();
};

Autobuf::Autobuf(char const *str) : np_(std::make_unique<Noise>()), ptr_(std::make_unique<char[]>(strlen(str) + 1))
{
    strcpy(ptr_.get(), str);
}

char *Autobuf::get()
{
    return ptr_.get();
}

int main()
{
    Autobuf buffer("My favorite test string");
    std::cout << "Hello World! " << buffer.get() << "\n";
    return 0;
}
#include <iostream>
#include <cstring>

struct Noise
{
    char big_buffer_[10000];
    Noise()
    {
        std::cout << "Constructing Noise\n";
    }
    ~Noise()
    {
        std::cout << "Destructing Noise\n";
    }
};

Noise *get_noisy_and_big(char const *s)
{
    Noise *ownedp = new Noise;
    strcpy(ownedp->big_buffer_, s);
    return ownedp;
}

int main()
{
    Noise *newownedp = get_noisy_and_big("A big Buffer");
    std::cout << "Noise: " << newownedp->big_buffer_ << "\n";
    delete newownedp;
    return 0;
}
#include <iostream>

#define HELLO_WORLD "Hello World"
#define LEVEL 3

int main()
{
#ifdef HELLO_WORLD
    std::cout << HELLO_WORLD << "\n";
#endif

#undef HELLO_WORLD

#ifdef HELLO_WORLD
    std::cout << HELLO_WORLD << "\n";
#endif

#if LEVEL == 0
#define SCORE 0
#elif LEVEL == 1
#define SCORE 15
#elif LEVEL == 2
#define SCORE 30
#elif LEVEL == 3
#define SCORE 45
#endif

#ifdef SCORE
    std::cout << SCORE << "\n";
#endif

    return 0;
}
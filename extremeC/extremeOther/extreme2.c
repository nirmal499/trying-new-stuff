#include <stdio.h>

struct sample_t
{
    char first;
    char second;
    char third;
    short fourth;
};

int main(int argc, char const *argv[])
{
    printf("%zu is the size\n", sizeof(short));
    return 0;
}

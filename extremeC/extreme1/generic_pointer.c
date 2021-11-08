#include <stdio.h>

int main(int argc, char **argv)
{
    int var = 9;
    // int *ptr = &var;
    void *gptr = &var;
    printf("%d\n", *(int *)gptr);
    int *int_ptr = gptr;
    printf("%d\n", *int_ptr);
    return 0;
}
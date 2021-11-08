#include <stdio.h>

int main(int argc, char **argv)
{
    int var = 1;
    int *int_ptr = NULL; // nullify the pointer
    int_ptr = &var;

    char *char_ptr = NULL;
    char_ptr = (char *)&var;

    printf("Before arithmetic: int_ptr: %u, char_ptr: %u\n",
           (unsigned int)int_ptr, (unsigned int)char_ptr);
    int_ptr++;
    char_ptr++;
    // Arithmetic step is usually 4 bytes
    // Arithmetic step in 1 byte
    printf("After arithmetic: int_ptr: %u, char_ptr: %u\n",
           (unsigned int)int_ptr, (unsigned int)char_ptr);
    return 0;
}
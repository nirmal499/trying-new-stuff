#include <stdio.h>
#include <string.h>
#include <assert.h>

char const *skip(char const *x);
void runlength_encode(char const *restrict input, char *restrict output);

int main(void)
{
    char const *x = "aaaabbbbbbbaabbbcbbccccccccc";
    char buffer[2 * strlen(x) + 1];

    runlength_encode(x, buffer);
    printf("%s\n", buffer);
    return 0;
}

char const *skip(char const *x)
{
    assert(*x != '\0');
    char c = *x;
    while (*x == c)
        x++;
    return x;
}
void runlength_encode(char const *restrict input, char *restrict output)
{
    while (*input)
    {
        char c = *input;
        char const *next = skip(input);
        unsigned int len = next - input;
        /* sprintf() returns the number of characters excluding the zero terminal (it does terminate the string, but
            the return value is excluding it) */

        /* We need to move output past the encoded run, however, and here we exploit that sprintf() will return the number of characters it 
            wrote into the buffer. If we increase output by this amount, it points at the first character */
        output += sprintf(output, "%d%c", len, c);
        input = next;
    }
}

#include <stdio.h>
#include <string.h>

/* reverse: reverse string 3 in place */
void reverse(char s[]);
/* itoa: convert n to characters in s */
void itoa(int n, char s[]);

int main()
{
    // char s[] = "Frying";
    // reverse(s);
    // printf("%s\n", s);

    char s1[10];
    int n = -8976;
    itoa(n, s1);
    printf("%s\n", s1);

    return 0;
}

/* reverse: reverse string 3 in place */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, --j)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itoa: convert n to characters in s 
    s should be large enough please make sure
*/
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)
    {
        n = -n; /* make n positive */
    }
    i = 0;
    do
    { /* generate digits in reverse order */
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

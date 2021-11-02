#include <stdio.h>

int myatoi(char s[]);
/* atof: convert string to double */
double atof(char s[]);
int mylower(int c);
int myisdigit(int c);
int myisspace(int c);
void mystrcat(char s[], char t[]);
int binsearch(int x, int v[], int n);

int main()
{
    // int n = atoi("3e4");
    // printf("%d\n", n);

    // int ch1 = lower('&');
    // int ch2 = lower('E');
    // printf("%c %c\n", ch1, ch2);

    // if (myisdigit('0'))
    // {
    //     printf("It is digit\n");
    // }
    // else
    // {
    //     printf("Not a digit\n");
    // }

    int arr[] = {2, 4, 6, 7, 9, 29, 45, 46, 49, 50, 51};
    unsigned n = sizeof(arr) / sizeof(arr[0]);
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%6d%c", arr[i], ((i % 10 == 9) || (i == n - 1)) ? '\n' : ' ');
    // }

    printf("%d\n", binsearch(9, arr, n));

    return 0;
}

int myisspace(int c)
{
    return (c == ' ');
}

int myatoi(char s[])
{
    int i, n, sign;
    for (i = 0; myisspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }

    for (n = 0; myisdigit(s[i]); i++)
    {
        n = 10 * n + (s[i] - '0');
        /* s[i] - '0' gives the numeric value of the character stored in s[i] */
    }
    return sign * n;

    /* 
        return (int) atof(s); 
    */
}

/* atof: convert string to double */
double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; myisspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    return sign * val / power;
}

int mylower(int c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + 'a' - 'A';
    }
    else
    {
        return c;
    }
}

int myisdigit(int c)
{
    return (c >= '0' && c <= '9');
}

/* strcat: concatenate t to end of s; 5 must be big enough */
void mystrcat(char s[], char t[])
{
    /* s should be large enough to store t */
    int i = 0, j = 0;
    while (s[i] != '\0')
        i++; /* find end of s */

    while ((s[i++] = t[j++]) != '\0') /* copy t */
        ;
}

/*
    Our binary search makes two tests inside the loop, when one
    would suffice (at the price of more tests outside). Write a version with only one
    test inside the loop and measure the difference in run-time
*/
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;

    mid = (low + high) / 2;

    while (low < high && x != v[mid])
    {
        if (x > v[mid])
            low = mid + 1;
        else
            high = mid - 1;

        mid = (low + high) / 2;
    }

    if (x == v[mid])
        return mid; /* returns index */
    else
        return -1;
}

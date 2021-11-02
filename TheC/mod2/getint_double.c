#include <stdio.h>
#include <ctype.h>

#define SIZE 1000
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

/*  ungetch function returns the character read to buf while getch tries to 
    read that character to our program and if no character is present,
    it uses getchar to get the character 
*/
int getch(void);

void ungetch(int c);

/* getint: get next integer from input into *pn */
int getint(int *pn);

int getfloat(double *pn);

int main()
{
    int n, array[SIZE] = {0};
    //printf("%d\n", array[89]);

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
    {
        printf("storing in n = %d, getint %d\n", n, array[n]);
    }
    printf("storing in n = %d, getint %d\n", n, array[n]);

    for (int s = 0; s <= n; s++)
        printf("%d ", array[s]);
    return 0;
}

/*  ungetch function returns the character read to buf while getch tries to 
    read that character to our program and if no character is present,
    it uses getchar to get the character 
*/
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;
    /* FYI '\n' can be considered as space */
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); /* it’s not a number */
        //printf("Not a number");
        return -1; /* -1 will end the program directly */
        /* In my system -1 represents EOF */
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getch();
    }

    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * (*pn) + (c - '0');
    }
    *pn *= sign;

    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
}

/* getfloat: get next float from input into *pn */
int getfloat(double *pn)
{
    int c, sign;
    double power;
    /* FYI '\n' can be considered as space */
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); /* it’s not a number */
        //printf("Not a number");
        return -1; /* -1 will end the program directly */
        /* In my system -1 represents EOF */
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getch();
    }

    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10.0 * (*pn) + (c - '0');
    }
    if (c == '.')
        c = getch();
    for (power = 1.0; isdigit(c); c = getch())
    {
        *pn = 10.0 * (*pn) + (c - '0');
        power *= 10.0;
    }
    *pn *= sign / power;

    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
}

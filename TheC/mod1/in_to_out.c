#include <stdio.h>

void way1()
{
    int c;
    c = getchar();
    while (c != EOF)
    {
        putchar(c);
        c = getchar();
    }
}

void way2()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }
}

/* To enter EOF in the terminal enter CTRL+D */
void count_chars1()
{
    long nc = 0;
    while (getchar() != EOF)
    {
        ++nc;
    }
    printf("%ld\n", nc);
}

void count_chars2()
{
    double nc;
    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
}

void count_lines()
{
    int c;
    int nl = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            ++nl;
        }
    }
    printf("%d\n", nl);
}

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */
void word_count()
{
    int c, nl, nw, nc, state;
    /* The variable state records whether the program is currently
        in a word or not; initially it is “not in a word,” which is assigned the value OUT 
    */
    state = OUT;
    nl = nw = nc = 0;
    /* nl = (nw = (nc = 0)); */
    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
        {
            ++nl;
        }

        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}

/* count digits, whitespaces, others */
void count()
{
    int c, nwhite, nothers;
    int ndigit[10]; /* covering 0 to 9 */
    nwhite = nothers = 0;
    for (int i = 0; i < 10; i++)
    {
        ndigit[i] = 0;
    }
    /* '0' in decimal is 48 and '9' in decimal is 57 */
    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
        {
            ++ndigit[c - '0'];
        }
        else if (c == ' ' || c == '\n' || c == '\t')
        {
            ++nwhite;
        }
        else
        {
            ++nothers;
        }
    }
    printf("Digits:= ");
    for (int i = 0; i < 10; i++)
    {
        printf(" %d", ndigit[i]);
    }

    printf(", white spaces = %d, other = %d\n", nwhite, nothers);
}

int main()
{
    //way1();
    //way2();
    //count_chars1();
    //count_chars2();
    //count_lines();
    //word_count();
    count();
    return 0;
}
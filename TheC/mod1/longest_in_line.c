#include <stdio.h>
#define MAXLINE 100

/* . At the minimum, getline has to return a signal about possible end of file; a more
    useful design would be to return the length of the line, or zero if end of file is
    encountered. Zero is an acceptable EOF return because it is never a valid
    line length. Every text line has at least one character; even a line containing
    only a newline has length 1 
*/
int myGetline(char s[], int limit);
/* myGetline: read a line into s, return length */
void copy(char to[], char from[]);
/* Copy: [Copy ’from’ into ’to’; assume to is big enough */

/* print longest input line */
int main()
{
    int len;               /* current line length */
    int max = 0;           /* maximum length seen so far */
    char line[MAXLINE];    /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    while ((len = myGetline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            //printf("\nThe length is : %d", len);
            copy(longest, line);
        }
    }
    if (max > 0)
    {
        printf("The Line is : %s\n", longest);
    }
    return 0;
}

/* myGetline: read a line into s, return length */
int myGetline(char s[], int limit)
{
    int c, i;
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

/* Copy: [Copy ’from’ into ’to’; assume to is big enough */
void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}
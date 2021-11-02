#include <stdio.h>

#define ALLOCSIZE 10000 /* size of available space */
static char allocbuf[ALLOCSIZE];
/* This array is private to alloc
    and afree. Since they deal in pointers, not array indices, 
    no other routine need know the name of the array, which can be declared static in the source
    file containing alloc and afree, and thus be invisible outside it.  
*/
static char *allocp = allocbuf; /* next free position */

char *alloc(int n);  /* return pointer to n characters */
void afree(char *p); /* free storage pointed to by p */
/* -------------------------------------------------------------------------------------------------- */
#define MAXLINES 5000 /* max #lines */
#define MAXLEN 1000   /* max length of any input line */

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int maxlines);
/* mygetline: read a line into s, return length */
int mygetline(char s[], int limit);
/* strcpy: copy t to s */
void mystrcpy(char *s, char *t);

int main()
{
    int nlines; /* number of input lines read */
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        printf("\nYou have written: ");
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }

    // char s[50];
    // int len = mygetline(s, 25);
    // printf("%s => %d\n", s, len);
    /* Last entered '\n' is counted in len */
}

/* The alloc(n), returns a pointer p to n consecutive
    character positions, which can be used by the caller of a1loc for storing characters.
    The second, afree(p), releases the storage thus acquired so it can be
    re-used later. 
*/
char *alloc(int n) /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    }
    else
    {
        return 0;
    }
}

void afree(char *p) /* free storage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    {
        /* We are not actually clearing out. We will just replace the old data
            with new data
        */
        allocp = p;
    }
}

/* mygetline: read a line into s, return length */
int mygetline(char s[], int limit)
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

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines = 0;
    char *p, line[MAXLEN];

    while ((len = mygetline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || ((p = alloc(len)) == NULL))
        {
            return -1;
        }
        else
        {
            line[len - 1] = '\0'; /* delete newline */
            mystrcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* strcpy: copy t to s */
void mystrcpy(char *s, char *t)
{

    /* Since '\0' results to false */
    while ((*s++ = *t++))
        ;
}
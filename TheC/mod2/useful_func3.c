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

/* strlen: return length Of string */
int mystrlen(char *s);

/* strcpy: copy t to s */
void mystrcpy(char *s, char *t);

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int mystrcmp(char *s, char *t);

int main()
{
    char array[] = {'H', 'e', 'l', 'l', 'o'};
    char *ptr = "Hello";
    printf("%d\n", mystrlen("Hello"));
    printf("%d\n", mystrlen(array));
    printf("%d\n", mystrlen(ptr));

    char *space = alloc(mystrlen(ptr) + 1);
    // space[0] = 'H';
    // space[1] = 'e';
    // space[2] = 'l';
    // space[3] = 'l';
    // space[4] = 'o';
    // space[5] = '\0';
    mystrcpy(space, "Hello");

    printf("%s\n", allocbuf);
    printf("%s\n", space);

    return 0;
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int mystrcmp(char *s, char *t)
{
    /* 
        int i;
        for( i=0; s[i]==t[i] ;i++){
            if(s[i]=='\0'){
                return 0;
            }
        }
     */

    for (; *s == *t; s++, t++)
    {
        if (*s == '\0')
        {
            return 0;
        }
    }
    return *s - *t;
}

/* strlen: return length Of string */
int mystrlen(char *s)
{
    /*  What actually is happening is that
        char *s is local variable to this function
        char *s = whatever_variable_passed_to_function

        whatever_variable_passed_to_function which contains 
        address in now stored in this local variable 's'
        whatever_variable_passed_to_function is not getting modified
     */

    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;

    /*char *p;
    for (p = s; *p != '\0'; p++)
        ;

    return p - s;
    */
}

/* strcpy: copy t to s */
void mystrcpy(char *s, char *t)
{

    /* Make sure that s is large enough to hold t */

    /*
        int i = 0;
        while(s[i]=t[i]){
            i++;
        }
    */

    /* Since '\0' results to false */
    while ((*s++ = *t++))
        ;

    /*while ((*s++ = *t++) != '\0')
        ;
    */
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

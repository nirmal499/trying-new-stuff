#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    while (--argc > 0)
    {
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
    }
    printf("\n");

    return 0;
}

/* echo hello, world

    In the example above, argc is 3, and argv[0], argv[1],
    and argv[2] are "echo", "hello,", and "world" respectively. The first
    optional argument is argv[1] and the last is argv[argc-1]; additionally,
    the standard requires that argv[argc] be a null pointer.

 */
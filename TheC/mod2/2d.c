#include <stdio.h>
#include <stdint.h>

//void print(int daytab[2][13]);
//void print(int daytab[][13]);
void print(int rows, int cols, int (*daytab)[cols]);
/* Here parameter is a pointer to an array of 13 integers. The parentheses are necessary 
    since brackets [] have higher precedence than *.
    Without parentheses, the declaration int *daytab[13]
    is an array of 13 pointers to integers.  
*/

/*  If a two-dimensional array is to be passed to a function, the parameter
    declaration in the function must include the number of columns; the number of
    rows is irrelevant, since what is passed is, as before, a pointer to an array of
    rows, where each row is an array of 13 ints. In this particular case, it is a
    pointer to objects that are arrays of 13 ints. 
*/

char *month_name(int n);

int main()
{
    // char daytab[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    //                       {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

    int daytab1[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                          {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    print(2, 13, daytab1);

    /*  print(2, 13, (int(*)[13])daytab);

        This will cause in printing weird values of daytab. Since daytab is structured
        as each element is of size char[1 byte]. But when we type cast it as int and passed it to
        the print. Therefore in that function,since daytab passed is int so, each time we are 
        about to show each element from daytab, it extracts int[4 byte] which cause in weird values
     */

    printf("%s\n", month_name(0));
    printf("%s\n", month_name(12));

    return 0;
}

/* In the print we are ensuring that the way we  */
void print(int rows, int cols, int (*daytab)[cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%i\t", daytab[i][j]);
        }
        printf("\n");
    }
}

/* month_name: return name of n-th month */
char *month_name(int n)
{
    // static char name[][15] = {
    //     "Illegal month",
    //     "January", "February", "March",
    //     "April", "May", "June", "July",
    //     "August", "September",
    //     "October", "November", "December"};
    static char *name[] = {
        "Illegal month",
        "January", "February", "March",
        "April", "May", "June", "July",
        "August", "September",
        "October", "November", "December"};
    return (n < 1 || n > 12) ? name[0] : name[n];
}

/* 

    int a[10][20];
    int *b[10];

    then a[3] [4] and b[ 3][4] are both syntactically legal references to a single
    int. But 'a' is a true two-dimensional array: 200 int-sized locations have been
    set aside, and the conventional rectangular subscript calculation 20*row+col is
    used to find the element a[row][col]. For b, however, the definition only allocates 
    10 pointers and does not initialize them; initialization must be done explicitly, either 
    statically or with code. Assuming that each element of b does point
    to a twenty-element array, then there will be 200 ints set aside, plus ten cells
    for the pointers. The important advantage of the pointer array is that the rows
    of the array may be of different lengths. That is, each element of b need not
    point to a twenty-element vector; some may point to two elements, some to fifty,
    and some to none at all.

 */
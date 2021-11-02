#include <stdio.h>

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n);
/* bitcount: count 1 bits in x */
int bitcount(unsigned x);

int main()
{
    printf("%d\n", getbits(69, 4, 3));
    printf("%d\n", bitcount(17));

    return 0;
}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
    /* As an illustration of some of the bit operators, consider the function
        getbits(x,p,n) that returns the (right adjusted) n-bit field of x that begins
        at position p. We assume that bit position 0 is at the right end and that n and
        p are sensible positive values. For example, getbits(x,4,3) returns the
        three bits in bit positions 4, 3 and 2, right adjusted 
    */

    return (x >> (p + 1 - n) & ~(~0 << n));
    /* The expression x >> (p+1-n) moves the desired field to the right end of the
        word. ~0 is all l-bits; shifting it left n bit positions with ~0<<n places zeros in
        the rightmost n bits; complementing that with ~ makes a mask with ones in the
        rightmost n bits
    */

    /* 69 :         0100 0101
       69 >> 2 :    0001 0001
       ~(~0<<3):    0000 0111
    */
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
    int c = 0;
    while (x)
    {
        /* In a two’s complement number system, x &= (x—1) deletes the rightmost 1-bit in x */
        x &= (x - 1);
        c++;
    }
    return c;

    /* for(c=0; c!=0 ; c&=(c-1)) c++; */
}
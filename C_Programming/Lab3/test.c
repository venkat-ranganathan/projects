#include <stdio.h>

void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
}

int main(void)
{
    bin(7);
    printf("\n");
    bin(4);
    printf("\n");
}

/* #include <stdio.h>

// C Program for the binary
// representation of a given number

void bin(unsigned n)
{

if (n > 1)
    bin(n / 2);


printf("%d", n % 2);
}

// Driver Code
int main(void)
{
    bin(7);
    printf("\n");
    bin(4);
    printf("\n");
}
*/
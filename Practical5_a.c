#include <stdio.h>
#include "misc.h"
void main()
{
    int a=234;
    printf("Sum of Digits: %d\n",sum_of_digits(a));

    printf("\nReverse of %d: %d\n",a,rev(a));

    printf("\nIs 121 Palindrome: \n");
    palin(121);

    printf("\nIs 234 palindrome: \n");
    palin(a);
}

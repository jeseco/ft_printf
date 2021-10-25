#include "../include/ft_printf.h"
#include <stdio.h>

#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define LONG_MAX 4294967295
#define LONG_MIN 0
#define ULONG_MAX 4294967295


/*
args:      [" %p %p ", 0, 0]
printf:    [ 0x0 0x0 ] = 9
ft_printf: [ 0x10324ec41 0x10324ec41 ] = 35
*/

int main(void)
{
    int i;
    int j;
    char    *args = " \%x , 16";

    printf("testing... \n");
    printf("\n");
    printf("args = %s\n", args);
    printf("\n");
    ft_printf("ft_printf:");
    i = ft_printf("%%p is how you print a pointer in printf");
    printf("\n");
    printf("   printf:");
    j = printf("%%p is how you print a pointer in printf");
    printf("\n");
    printf("returns :\n     mine = %i\n     printf = %i", i, j);
    printf("\n");
    return (0);
}
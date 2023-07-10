#include "ft_printf.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 0;
    ft_printf("%p\n", &a);
    printf("%p\n", &a);
    ft_printf("%d\n", a);
    printf("%d\n", a);
    ft_printf("%d\n", -2147483648);
    printf("%d\n", (int)-2147483648);
    ft_printf("%s\n", "");
    printf("%s\n", "");
    return 0;
}

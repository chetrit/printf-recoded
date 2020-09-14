/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** prints the number passed as parameter
*/

#include <stdarg.h>
#include <unistd.h>
#include "my_printf.h"

void my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return (0);
    }
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10)
        my_put_nbr(nb/10);
    my_putchar((nb % 10) + 48);
    return (0);
}

int my_put_nbr_pf(va_list ap, UNUSED char const *format)
{
    int nb = va_arg(ap, int);

    my_put_nbr(nb);
    return (0);
}

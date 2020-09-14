/*
** EPITECH PROJECT, 2019
** my_put_nbr_hexadecimal_P
** File description:
** just an extent of my_put_nbr_hexadecimal
*/

#include <stdarg.h>
#include "my.h"
#include "my_printf.h"

int my_put_nbr_hexadecimal_cobama(long long nb)
{
    if (nb >= 16)
        my_put_nbr_hexadecimal_cobama(nb / 16);
    if (nb % 16 < 10)
        my_putchar(nb % 16 + 48);
    if (nb % 16 >= 10)
        my_putchar(nb % 16 + 'a' - 10);
    return (0);
}

int my_put_nbr_p(va_list ap, UNUSED char const *format)
{
    my_printf("0x");
    return (my_put_nbr_hexadecimal_cobama((long long) va_arg(ap, void *)));
}

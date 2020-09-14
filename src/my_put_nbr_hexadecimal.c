/*
** EPITECH PROJECT, 2019
** my_put_nbr_hexadecimal
** File description:
** prints a number in a given base
*/

#include "my_printf.h"
#include <unistd.h>
#include <stdarg.h>

void my_putchar(char c);

int my_put_nbr_hexadecimal_co(unsigned int nb)
{
    if (nb >= 16)
        my_put_nbr_hexadecimal_co(nb / 16);
    if (nb % 16 < 10)
        my_putchar(nb % 16 + 48);
    if (nb % 16 >= 10)
        my_putchar(nb % 16 + 'a' - 10);
    return (0);
}

int my_put_nbr_hexadecimal(va_list ap, UNUSED char const *format)
{
    return (my_put_nbr_hexadecimal_co(va_arg(ap, unsigned int)));
}

int my_put_nbr_hexadecimal_x_maj_co(unsigned int nb)
{
    if (nb >= 16)
        my_put_nbr_hexadecimal_x_maj_co(nb / 16);
    if (nb % 16 < 10)
        my_putchar(nb % 16 + 48);
    if (nb % 16 >= 10) {
        my_putchar(nb % 16 + 'A' - 10);
    }
    return (0);
}

int my_put_nbr_hexadecimal_x_maj(va_list ap, UNUSED char const *format)
{
    return (my_put_nbr_hexadecimal_x_maj_co(va_arg(ap, unsigned int)));
}

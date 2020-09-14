/*
** EPITECH PROJECT, 2019
** my_put_nbr_base
** File description:
** prints a number in a given base
*/

#include <stdarg.h>
#include <unistd.h>
#include "my_printf.h"

void my_putchar(char c);

int my_put_nbr_base(unsigned int nb, unsigned int const base)
{
    if (nb >= base)
        my_put_nbr_base(nb / base, base);
    my_putchar((nb % base) + 48);
    return (0);
}

int my_put_nbr_o_pf(va_list ap, UNUSED char const *format)
{
    return (my_put_nbr_base(va_arg(ap, unsigned int), 8));
}

int my_put_nbr_u_pf(va_list ap, UNUSED char const *format)
{
    return (my_put_nbr_base(va_arg(ap, unsigned int), 10));
}

int my_put_nbr_b_pf(va_list ap, UNUSED char const *format)
{
    return (my_put_nbr_base(va_arg(ap, unsigned int), 2));
}

int my_put_s_maj(va_list ap, UNUSED char const *format)
{
    int i = 0;
    char *str = va_arg(ap, char *);

    while (str[i] != '\0') {
        if (str[i] > 31 && str[i] < 127)
            my_putchar(str[i]);
        else if (str[i] >= 0 && str[i] <= 7) {
            my_putchar('\\');
            my_putstr("00");
            my_put_nbr_base(str[i], 8);
        } else {
            my_putchar('\\');
            my_putstr("0");
            my_put_nbr_base(str[i], 8);
        }
        i += 1;
    }
    return (0);
}

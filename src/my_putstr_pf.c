/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** prints a string
*/

#include <stdarg.h>
#include "my_printf.h"

void my_putchar(char c);

int my_putstr_pf(va_list ap, UNUSED char const *format)
{
    int i = 0;
    char *str = va_arg(ap, char *);

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
    return (0);
}

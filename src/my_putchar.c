/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** prints a character
*/

#include "my_printf.h"
#include <unistd.h>
#include <stdarg.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
    return (0);
}

int print_percent(UNUSED va_list ap, UNUSED char const *format)
{
    my_putchar('%');
    return (0);
}

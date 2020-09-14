/*
** EPITECH PROJECT, 2019
** my_putchar_pf
** File description:
** my_putchar for my_printf
*/

#include <stdarg.h>
#include <unistd.h>
#include "my_printf.h"

void get_bool_array(int bool_array[9], char *str)
{
    int i = 0;
    int j = 0;
    char modif[9] = {'#', '+', '-', ' ', '0', 'o', 'x', 'X', 'd'};

    for (int k = 0; k != 9; k++)
        bool_array[k] = 0;
    for (i = 0; i != 9; i += 1) {
        for (j = 0; str[j] != '\0'; j += 1) {
            if (str[j] == modif[i])
                bool_array[i] = 1;
            if (str[j] == 'i')
                bool_array[8] = 1;
        }
    }
}

int my_putchar_pf(va_list ap, UNUSED char const *format)
{
    char c = (char) va_arg(ap, int);

    write(1, &c, 1);
    return (0);
}

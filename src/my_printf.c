/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** prints everything you would need to
*/

#include <stdarg.h>
#include "my.h"
#include "my_printf.h"

char *get_str(char *str);

const avoid_ifs_t arg_struct[18] = {
    {'c', &my_putchar_pf},
    {'d', &my_put_nbr_pf},
    {'i', &my_put_nbr_pf},
    {'s', &my_putstr_pf},
    {'o', &my_put_nbr_o_pf},
    {'u', &my_put_nbr_u_pf},
    {'x', &my_put_nbr_hexadecimal},
    {'X', &my_put_nbr_hexadecimal_x_maj},
    {'b', &my_put_nbr_b_pf},
    {'p', &my_put_nbr_p},
    {'S', &my_put_s_maj},
    {'z', &print_percent},
    {'#', &format_hub},
    {'0', &format_hub},
    {'-', &format_hub},
    {'+', &format_hub},
    {' ', &format_hub},
    {'r', &my_putstr_pf}
};

void my_printf_extend(int *i, char const *str, int *b_two)
{
    if (str[*i] == '%' && str[*i + 1] != 'z' && str[*i + 1] != 'c'
        && str[*i + 1] != 's' && str[*i + 1] != 'p')
        *b_two = 1;
    if ((str[*i] == 'o' || str[*i] == 'x' || str[*i] == 'X'
        || str[*i] == 'u' || str[*i] == 'd' || str[*i] == 'i') && *b_two == 1) {
        *b_two = 0;
        return;
    }
    if (str[*i - 1] != '%' && (str[*i] != '%')) {
        my_putchar(str[*i]);
    }
}

char *get_format(const char *format)
{
    char *s_format = my_strdup(format);

    for (int i = 0; format[i] != '\0'; i++)
        if (s_format[i] == '%' && s_format[i - 1] == '%')
            s_format[i] = 'z';
    return (s_format);
}

int my_printf(const char *format, ...)
{
    va_list ap;
    int cond = 0;
    char *s_format;

    va_start(ap, format);
    s_format = get_format(format);
    for (int i = 0; s_format[i] != '\0'; i += 1) {
        for (int j = 0; arg_struct[j].c != 'r'; j += 1) {
            if (s_format[i] == arg_struct[j].c && (s_format[i - 1] == '%'))
                arg_struct[j].ptr(ap, &s_format[i]);
        }
        my_printf_extend(&i, s_format, &cond);
    }
    va_end(ap);
    return (0);
}

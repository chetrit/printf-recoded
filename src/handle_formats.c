/*
** EPITECH PROJECT, 2019
** handle_formats
** File description:
** handles formats for my_printf
*/

#include <stdarg.h>
#include "my_printf.h"
#include "my.h"

void get_bool_array(int bool_array[9], char *str);

const avoid_ifs_t arg_struct_f[17] = {
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
    {'#', &format_hub},
    {'0', &format_hub},
    {'-', &format_hub},
    {'+', &format_hub},
    {' ', &format_hub},
    {'r', &my_putstr_pf}
};

void get_str(char *str)
{
    int i;
    int j;

    for (i = 0; str[i] != '\0'; i += 1) {
        for (j = 0; j < 11; j += 1) {
            if (str[i] == arg_struct_f[j].c)
                str[i + 1] = '\0';
        }
    }
}

int handle_format_third(va_list ap, int bool[9])
{
    if ((bool[4] == 1 || bool[2] == 1) && bool[7] == 1)
        my_put_nbr_hexadecimal_x_maj(ap, "\0");
    return (0);
}

int handle_format_second(va_list ap, int bool[9])
{
    int nb = 0;

    if (bool[1] == 1 && bool[8] == 1) {
        nb = va_arg(ap, int);
        if (nb >= 0)
            my_putstr("+");
        my_put_nbr(nb);
    }
    if ((bool[4] == 1 || bool[2] == 1) && bool[8] == 1)
        my_put_nbr(va_arg(ap, int));
    if ((bool[4] == 1 || bool[2] == 1) && bool[5] == 1)
        my_put_nbr_o_pf(ap, "\0");
    if ((bool[4] == 1 || bool[2] == 1) && bool[6] == 1)
        my_put_nbr_hexadecimal(ap, "\0");
    handle_format_third(ap, bool);
    return (0);
}

int handle_format_first(va_list ap, int bool[9])
{
    if (bool[0] == 1 && bool[5] == 1) {
        my_putchar('0');
        my_put_nbr_o_pf(ap, "\0");
    }
    if (bool[0] == 1 && bool[6] == 1) {
        my_putstr("0x");
        my_put_nbr_hexadecimal(ap, "\0");
    }
    if (bool[0] == 1 && bool[7] == 1) {
        my_putstr("0X");
        my_put_nbr_hexadecimal_x_maj(ap, "\0");
    }
    if (bool[3] == 1 && bool[1] == 0) {
        my_putstr(" ");
        my_put_nbr_base(va_arg(ap, unsigned int), 10);
    }
    handle_format_second(ap, bool);
    return (0);
}

int format_hub(va_list ap, char const *format)
{
    char *str = my_strdup(format);
    int bool_array[9];

    get_str(&str[0]);
    get_bool_array(&bool_array[0], str);
    handle_format_first(ap, bool_array);
    return (0);
}

/*
** EPITECH PROJECT, 2019
** header my_printf
** File description:
** header of my_printf
*/

#include <stdarg.h>
#include "my.h"

#define UNUSED __attribute__((unused))

typedef struct avoid_ifs {
    char c;
    int (*ptr)(va_list ap, char const *);
} avoid_ifs_t;

char *my_strdup(char const *src);
int my_putchar_pf(va_list ap, char const *format);
int my_put_nbr_pf(va_list ap, char const *format);
int my_putstr_pf(va_list ap, char const *format);
int my_put_nbr_hexadecimal_x_maj(va_list ap, char const *format);
int my_put_nbr_hexadecimal(va_list ap, char const *format);
int my_put_nbr_b_pf(va_list ap, char const *format);
int format_hub(va_list ap, char const *format);

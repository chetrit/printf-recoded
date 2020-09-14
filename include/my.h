/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my header
*/

void my_putchar (char c);
int my_put_nbr (int nb);
int my_putstr (char const *str);
int my_strlen (char const *str);
char *my_revstr(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_put_nbr_o_pf(va_list ap, char const *format);
int my_put_nbr_u_pf(va_list ap, char const *format);
int my_put_nbr_x_pf(va_list ap, char const *format);
int my_put_nbr_x_maj_pf(va_list ap, char const *format);
int my_put_nbr_base(unsigned int nb, unsigned int const base);
int my_put_nbr_p(va_list ap, char const *format);
int my_put_s_maj(va_list ap, char const *format);
int print_percent(va_list ap, char const *format);
int my_put_nbr_hexadecimal(va_list ap, char const *format);
int my_printf(char const *format, ...);

/*
** EPITECH PROJECT, 2019
** test_my_printf
** File description:
** tests my_printf function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    my_printf("hello");
    cr_assert_stdout_eq_str("hello worldhello");
}

Test(my_printf, one_parameter, .init = redirect_all_std)
{
    my_printf("%d\n", 12);
    my_printf("%i\n", 12);
    my_printf("%s\n", "fafzfzaf");
    cr_assert_stdout_eq_str("12\n12\nfafzfzaf\n");
}

Test(my_printf, special_flag, .init = redirect_all_std)
{
    my_printf("%S\n", "hey\n ca va ?");
    my_printf("%p\n", 909123456);
    cr_assert_stdout_eq_str("hey\\012 ca va ?\n0x36301f80\n");
}

Test(my_printf, hard_test, .init = redirect_all_std)
{
    my_printf("array[%d]: %c, i = %d\n, unsigned i : %u\n", 2, 'a', 12, 12);
    cr_assert_stdout_eq_str("array[2]: a, i = 12\n, unsigned i : 12\n");
}

Test(my_printf, hard_test_2, .init = redirect_all_std)
{
    my_printf("special shit: %%%S\n%%%d\n", "\b\a", 12);
    cr_assert_stdout_eq_str("special shit: %\\010\\007\n%12\n");
}

Test(my_printf, double_percent_test, .init = redirect_all_std)
{
    my_printf("%d\n%%heyyy%%\n", 12);
    my_printf("astek%%%dmoulinett\n", 42);
    my_printf("astek%%d%dmouli\n", 42);
    cr_assert_stdout_eq_str("12\n%heyyy%\nastek%42moulinett\nastek%d42mouli\n");
}

Test(my_printf, base_parameters, .init = redirect_all_std)
{
    my_printf("%o,%i,%u,%x,%X,%d,%b%x\n", 12, 12, 12, 12, 12, 12, 12, 31337);
    cr_assert_stdout_eq_str("14,12,12,c,C,12,11007a69\n");
}

Test(my_printf, special_numbers, .init = redirect_all_std)
{
    my_printf("%d%d%d%%\n", -12, -2147483648, -312);
    cr_assert_stdout_eq_str("-12-2147483648-312%\n");
}

Test(my_printf, simple_formats, .init = redirect_all_std)
{
    my_printf("%#x\n", 12);
    my_printf("%#X\n", 12);
    my_printf("% d\n", 32);
    my_printf("%+d\n", 32);
    my_printf("%+i\n", -32);
    my_printf("%0d\n", 32);
    my_printf("%0x", 32);
    my_printf("%0X", 32);
    my_printf("%-d", 32);
    my_printf("%-x", 32);
    my_printf("%-X", 32);
    my_printf("%#o", 12);
    my_printf("%0o", 12);
    cr_assert_stdout_eq_str("0xc\n0XC\n 32\n+32\n-32\n32\n202032202001414");
}

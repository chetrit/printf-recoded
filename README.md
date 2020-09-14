# printf-recoded

> This project is a refactoring and recoding of ``printf`` function from standard libC for learning purposes. It does not include all the advanced flags and complete formating flags of the original function, but It handle most of the usecases of this function, such as printing of combined strings, with integers, pointer values, and theire hex representation ...

# Installation and compilation
#### Installation
After cloning the repository, you have nothing else to installed since it is in C and without external libraries !
    
#### Compilation
This programs compilate a library named "libmy.a" which can be used in your programs.

Compilation of library using makefile:
```
make
```
Run the unit tests using the rule ``tests_run``: (criterion lib is required)
```
make tests_run
```

To use it on your programs, compile with  ``-L {PATH_TO_LIB} -lmy`` flag.
Don't forget to include the prototype of the function, which is ``int my_printf(const char *format, ...);``, 

# Examples

```
my_printf("hello world");

my_printf("astek%%%dmoulinett\n", 42);

my_printf("%#X\n", 12);

my_printf("%d%d%d%%\n", -12, -2147483648, -312);

my_printf("array[%d]: %c, i = %d\n, unsigned i : %u\n", 2, 'a', 12, 12);
```

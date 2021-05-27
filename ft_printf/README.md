# FT_printf
```C
int ft_printf( const char *, ... );
```
Ft_printf imitates the behavior of the printf function ( for more information about **Printf** I recommand this doc: [Microsoft documentation](https://docs.microsoft.com/en-us/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions) ). Rewriting printf is an interesting exercise to discover kwargs and force yourself to adopt a clear and logic structure within your code.

## Ft_printf conversioins

### Type conversion specifier

| Format specifier | Desired type | Output format |
| --- | --- | --- |
| `c` | `char` | Charcater (ex: `'h'`). | 
| `s` | `char *` | String (ex: `"Hello World\n"`). |
| `p` | `void *` | Address in hexadecimal digits (ex: `0xfffe69d479c`). |
| `d / i` | `int` | Signed decimal integer (ex: `19`). |
| `u` | `unsigned int` | Unsigned decimal integer (base: `0123456789`). |
| `x` | `unsigned int` | Unsigned hexadecimal integers (base: `0123456789abcdef`). |
| `X` | `unsigned int` | Unsigned hexadecimal integers (base: `0123456789ABCDEF`). |
| `%` | `NONE` | Display the `%` character |

### Flags

| Flag | Description |
| --- | --- |
| `-` | Left justify for width. |
| `0` | Add leading zeros until the minimum width is reached. </br>Flag `0` is ignored when flag `-` is present. |

## Instalation
:warning: **Before cloning this repo, please make sure that there are no files/folders called Cursus19 or ft_printf in the destination folder!!** :warning:

If you want to use this library please run:
```
git clone https://github.com/TimourP/Cursus19.git Cursus19 && cp -r Cursus19/ft_printf ./ && rm -rf Cursus19
```
## Usage
**In the printf repo**, run ```make``` or ```make re```, it will generate a libftprintf.a file. Use this file when compiling your code to use ft_printf.

To remove objects files, run ```make clean```

To remove objects files and the libftprintf.a file, run ```make fclean```

*This project has been created as part of the 42 curriculum by zchauve.*

# ft_printf

> Because `ft_putnbr()` and `ft_putstr()` aren't enough.

## Description

`ft_printf` is a reimplementation of the C standard library function `printf()`.
The goal of the project is to learn how **variadic functions** work in C (`va_start`, `va_arg`, `va_copy`, `va_end`) and to write well-structured, extensible code that can later be added to my `libft` and reused in future 42 projects.

The project builds a static library, `libftprintf.a`, which provides:

```c
int ft_printf(const char *format, ...);
```

Like the original, `ft_printf` writes the formatted output to the standard output and returns the number of characters printed (or `-1` on a write error).

### Supported conversions

| Conversion | Description |
|------------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string (`(null)` if the pointer is `NULL`) |
| `%p` | Prints a `void *` pointer in hexadecimal, prefixed with `0x` |
| `%d` | Prints a signed decimal (base 10) number |
| `%i` | Prints a signed integer in base 10 |
| `%u` | Prints an unsigned decimal (base 10) number |
| `%x` | Prints a number in lowercase hexadecimal (base 16) |
| `%X` | Prints a number in uppercase hexadecimal (base 16) |
| `%%` | Prints a percent sign |

<!-- If you did the bonus, add a section here listing the flags you handle:
     '-', '0', '.', minimum field width, '#', ' ' and '+'. -->

As required by the subject, the buffer management of the original `printf()` is **not** implemented: output is written directly with `write()`.

## Instructions

### Requirements

- A Unix-like system (Linux or macOS)
- `cc` and `make`

### Compilation

At the root of the repository:

```bash
make        # builds libftprintf.a
make clean  # removes object files
make fclean # removes object files and libftprintf.a
make re     # fclean + all
```

The code is compiled with `-Wall -Wextra -Werror`, and the library is created with `ar` (not `libtool`).

### Usage

Include the header and link the library when compiling your program:

```c
#include "ft_printf.h"

int main(void)
{
    int len;

    len = ft_printf("Hello %s, you are %d years old (%x in hex)\n", "Marvin", 42, 42);
    ft_printf("That line was %d characters long.\n", len);
    ft_printf("Pointer: %p | Percent: %%\n", &len);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
./test
```

## Algorithm and data structure

<!-- Adjust this section so it matches YOUR actual implementation —
     evaluators will ask you to explain it. -->

### Algorithm

`ft_printf` makes a single left-to-right pass over the format string:

1. Initialise a `va_list` with `va_start`.
2. Read the format string character by character:
   - if the character is not `%`, write it directly and increment the counter;
   - if it is `%`, look at the next character (the conversion specifier) and call the matching handler, which fetches the right type with `va_arg` and returns how many characters it wrote.
3. Add each handler's return value to a running total.
4. Call `va_end` and return the total.

Number conversions (`%d`, `%i`, `%u`, `%x`, `%X`, `%p`) share one generic routine that prints an unsigned value in any base given a base string (`"0123456789"`, `"0123456789abcdef"`, `"0123456789ABCDEF"`). Signed values are handled by printing the `-` sign first and converting to a wider/unsigned type, so that `INT_MIN` is printed correctly without overflow. Pointers are cast to `unsigned long` and printed in base 16 after the `0x` prefix.

**Why this approach:**

- **Single pass, O(n)** in the length of the format string, with no intermediate allocation — so there is nothing to free and no risk of memory leaks.
- **Writing directly** with `write()` matches the subject's rule of not reimplementing `printf`'s buffering.
- **One handler per conversion** keeps each function short (Norm-friendly) and makes it easy to add a new conversion: write a new handler and add one case to the dispatcher.
- **A shared base-conversion function** avoids duplicating almost identical code for decimal, hexadecimal and pointer output.

### Data structure

The mandatory part does not need a complex data structure: the only state carried through the program is the `va_list` and an `int` counter of printed characters. Keeping the state this small makes the code simple to read and to debug.

<!-- If you did the bonus, describe your flags structure here, e.g. a
     `t_format` struct holding minus, zero, precision, width, hash, space and
     plus — parsed once per conversion and passed to the handlers — and
     explain why grouping them in a struct beats passing many parameters. -->

## Resources

### Documentation and references

- [`man 3 printf`](https://man7.org/linux/man-pages/man3/printf.3.html) — the reference behaviour `ft_printf` is compared against
- [`man 3 stdarg`](https://man7.org/linux/man-pages/man3/stdarg.3.html) — `va_start`, `va_arg`, `va_copy`, `va_end`
- [cppreference — `printf`](https://en.cppreference.com/w/c/io/fprintf) — conversion specifiers, flags and edge cases
- [cppreference — Variadic functions](https://en.cppreference.com/w/c/variadic)
- The 42 Norm (available on the intranet)

### Use of AI

<!-- Be honest and specific here — the subject requires it. Example: -->

- AI was used to help draft and structure this `README.md` file.
- <!-- List any other use, e.g. "to explain how va_arg handles type promotion",
       or "No AI was used to write the source code." -->

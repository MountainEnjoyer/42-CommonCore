*This project has been created as part of the 42 curriculum by zchauve.*

# get_next_line

## Description

**get_next_line** is a C function that returns one line at a time from a file descriptor.

```c
char *get_next_line(int fd);
```

Each call returns the next line from `fd`, **including** the terminating `\n`, except for the last line if the file does not end with one. When nothing is left to read, or when an error occurs, the function returns `NULL`.

The main goal of the project is to learn how **static variables** work in C: a static variable keeps its value between calls. Here it holds the data that was read but not yet returned.

The function works with regular files, standard input, and any other readable file descriptor (pipes, etc.). It only uses `read`, `malloc` and `free`. `lseek`, global variables and libft are not allowed.

### Files

| File | Content |
|------|---------|
| `get_next_line.c` | Main function and line extraction logic |
| `get_next_line_utils.c` | Helper functions (string length, search, join, etc.) |
| `get_next_line.h` | Prototype, includes, and default `BUFFER_SIZE` |
| `get_next_line_bonus.c` | Bonus version: multiple file descriptors at once |
| `get_next_line_utils_bonus.c` | Bonus helper functions |
| `get_next_line_bonus.h` | Bonus header |

## Instructions

### Compilation

The function is meant to be compiled with your own program (e.g. a `main.c`). The read buffer size is set at compile time with `-D BUFFER_SIZE=n`:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

`BUFFER_SIZE` is optional: if it is not given, the default value defined in `get_next_line.h` is used.

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c
```

Bonus version:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c
```

### Usage example

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int   fd;
    char  *line;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    line = get_next_line(fd);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (0);
}
```

To read from standard input, call `get_next_line(0)`.

### Testing

Things worth testing:

- very small and very large buffer sizes (`1`, `42`, `9999`, `10000000`)
- empty files, files with only `\n`, files with no final `\n`
- very long lines and very short lines
- standard input and pipes
- invalid file descriptors (`-1`, a closed fd)
- (bonus) alternating reads between several file descriptors
- memory leaks, e.g. with `valgrind --leak-check=full`

## Algorithm

### Overview

The function keeps a **stash** in a static variable: the bytes that were read from the file but not returned yet. Each call works in three steps:

1. **Read until a line is complete.**
   While the stash contains no `\n`, call `read(fd, buffer, BUFFER_SIZE)` and append the buffer to the stash. Stop when a `\n` is found, when `read` returns `0` (end of file), or when it returns `-1` (error).

2. **Extract the line.**
   Copy everything from the start of the stash up to and including the first `\n` (or the whole stash if there is no `\n` left at end of file) into a newly allocated string. This string is returned to the caller.

3. **Keep the rest.**
   Replace the stash with what comes after the extracted line, so the next call starts from there. If nothing is left, the stash is freed and set to `NULL`.

On error, or when the stash is empty at end of file, everything is freed and the function returns `NULL`.

### Example (BUFFER_SIZE = 4, file content `"ab\ncd\nef"`)

| Call | Reads | Stash before extraction | Returned | Stash after |
|------|-------|------------------------|----------|-------------|
| 1 | `"ab\nc"` | `"ab\nc"` | `"ab\n"` | `"c"` |
| 2 | `"d\nef"` | `"cd\nef"` | `"cd\n"` | `"ef"` |
| 3 | EOF | `"ef"` | `"ef"` | `NULL` |
| 4 | EOF | `NULL` | `NULL` | `NULL` |

### Why this approach

- **Reads as little as possible.** It stops reading as soon as a full line is available, as the subject asks, instead of loading the whole file into memory. This also makes it work with standard input and pipes, where the "end" of the input is not known in advance.
- **Works with any `BUFFER_SIZE`.** A line can be shorter than the buffer (several lines in one read: the extra data stays in the stash) or longer (several reads are joined before extraction). Very large buffer sizes are handled by allocating the read buffer on the heap rather than the stack, which avoids a stack overflow.
- **Static variable instead of global.** The stash must survive between calls, and globals are forbidden. A static local variable is only visible inside the function, which is exactly what is needed.
- **No memory leaks.** The returned line is owned by the caller, who must `free` it. Everything else (read buffer, old stash) is freed inside the function, including on errors.

### Bonus: multiple file descriptors

The bonus version uses **a single static variable**: an array of stashes indexed by file descriptor (for example `static char *stash[OPEN_MAX]`). Each fd has its own independent stash, so reading from fd 3, then 4, then 3 again continues each file exactly where it stopped. Invalid fds (negative or `>= OPEN_MAX`) return `NULL` right away.

## Resources

### References

- `man 2 read`, `man 3 malloc`, `man 3 free`
- [Static variables in C – GeeksforGeeks](https://www.geeksforgeeks.org/static-variables-in-c/)
- [File descriptor – Wikipedia](https://en.wikipedia.org/wiki/File_descriptor)
- [Valgrind quick start guide](https://valgrind.org/docs/manual/quick-start.html)
- Discussions with peers at 42

### Use of AI

- AI (Claude) was used to help draft and structure this README.md.

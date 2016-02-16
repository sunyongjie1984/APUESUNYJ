// 1.4CopyStandardInputToStandardOutput.cpp
#include "../lib/apuesunyj.h"

#define BUFFSIZE 4096

int main()
{
    int n;
    char buf[BUFFSIZE];

    // By convention, all shells open three descriptors whenever a new program is run:
    // standard input, standard output, and standard error.
    // STDIN_FILENO specify the file descriptor for standard input
    // Unbuffered I/O is provided by the functions open, read, write, lseek, and close.
    // These functions all work with file descriptors.
    // The read function returns the number of bytes that are read, and this value is used
    // as the number of bytes to write. When the end of the input file is encountered, read
    // returns 0 and the program stops. If a read error occurs, read returns -1.
    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
    {
        if (write(STDOUT_FILENO, buf, n) != n)
        {
            err_sys("write error");
        }
    }

    // usually n is bigger than 0, if input ctrl + d
    // then n is equal to 0
    if (n < 0)
    {
        err_sys("read error");
    }

    return 0;
}
// The standard I/O functions provide a buffered interface to the unbuffered I/O
// functions. Using standard I/O relieves us from having to choose optimal buffer sizes,
// such as the BUFFSIZE constant in Figure 1.4. The standard I/O functions also simplify
// dealing with lines of input (a common occurrence in UNIX applications). The fgets
// function, for example, reads an entire line. The read function, in contrast, reads a
// specified number of bytes. As we shall see in Section 5.4, the standard I/O library
// provides functions that let us control the style of buffering used by the library.
// The most common standard I/O function is printf. In programs that call
// printf, we'll always include <stdio.h> normally by including apue.h as this
// header contains the function prototypes for all the standard I/O functions.

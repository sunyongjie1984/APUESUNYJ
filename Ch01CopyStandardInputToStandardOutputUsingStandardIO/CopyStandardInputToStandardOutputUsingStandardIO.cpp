/*
 * 1.5CopyStandardInputToStandardOutputUsingStandardIO.cpp
 *
 *  Created on: Feb 10, 2015
 *      Author: sunyj
 */
#include "../lib/apuesunyj.h"

/*
The standard I/O functions provide a buffered interface to the unbuffered I/O
functions. Using standard I/O relieves us from having to choose optimal buffer sizes,
such as the BUFFSIZE constant in Figure 1.4. The standard I/O functions also simplify
dealing with lines of input (a common occurrence in UNIX applications). The fgets
function, for example, reads an entire line. The read function, in contrast, reads a
specified number of bytes. As we shall see in Section 5.4, the standard I/O library
provides functions that let us control the style of buffering used by the library.
The most common standard I/O function is printf. In programs that call
printf, we will always include <stdio.h> normally by including apue.h as this
header contains the function prototypes for all the standard I/O functions.

The function getc reads one character at a time, and this character is written by putc.
After the last byte of input has been read, getc returns the constant EOF (defined in
<stdio.h>). The standard I/O constants stdin and stdout are also defined in the
<stdio.h> header and refer to the standard input and standard output.
 */
int main()
{
	int c;

	while ((c = getc(stdin)) != EOF)
	{
		if (putc(c, stdout) == EOF)
		{
			err_sys("output error");
		}
	}

	if (ferror(stdin))
	{
		err_sys("input error");
	}

	return 0;
}

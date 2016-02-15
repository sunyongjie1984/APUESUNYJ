/*
 * 1.8DemonstrateStrerrorAndPerror.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: sunyj
 */

#include "../lib/apuesunyj.h"

int main(int argc, char *argv[])
{
	fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
	errno = ENOENT;
	perror(argv[0]);
	return 0;
}

/*
 * 1.6PrintTheProcessID.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: sunyj
 */

#include "../lib/apuesunyj.h"

int main(void)
{
	printf("hello world from process ID %ld\n", static_cast<long>(getpid()));
	return 0;
}

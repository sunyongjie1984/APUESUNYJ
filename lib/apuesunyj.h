// apuesunyj.h
#ifndef APUE_SUNYJ
#define APUE_SUNYJ

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

int64_t const MAXLINE = 4096; // max line length
int64_t const ARG_MAX = 4096;

void err_quit(const char *fmt, ...);
void err_sys(const char *fmt, ...);
void err_ret(const char *fmt, ...);

#endif

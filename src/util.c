/**
 * @file util.c
 * @author Vladyslav Aviedov <vladaviedov@protonmail.com>
 * @brief Utility package
 * @date 2022-05-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "util.h"

#include <stdlib.h>
#include <stdarg.h>
#include <ncurses.h>

/**
 * @brief Close ncurses and exit.
 * 
 * @param value 
 */
void quit(int value) {
	endwin();
	exit(value);
}

/**
 * @brief Print message to stderr and exit
 * 
 * @param code exit code
 * @param format printf style format
 * @param ... printf arguments
 */
void fatal(int code, char *format, ...) {
	endwin();

	va_list args;
	va_start(args, format);
	vfprintf(stderr, format, args);
	
	va_end(args);
	exit(code);
}

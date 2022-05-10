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

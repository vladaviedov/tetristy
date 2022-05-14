/**
 * @file colors.c
 * @author Vladyslav Aviedov (vladaviedov@protonmail.com)
 * @brief ncurses color settings.
 * @date 2022-05-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "colors.h"

#include <ncurses.h>

void make_colors() {
	init_pair(CLR_I, COLOR_WHITE, COLOR_CYAN);
	init_pair(CLR_J, COLOR_WHITE, COLOR_BLUE);
	init_pair(CLR_L, COLOR_WHITE, COLOR_WHITE);
	init_pair(CLR_O, COLOR_WHITE, COLOR_YELLOW);
	init_pair(CLR_S, COLOR_WHITE, COLOR_GREEN);
	init_pair(CLR_T, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(CLR_Z, COLOR_WHITE, COLOR_RED);
}

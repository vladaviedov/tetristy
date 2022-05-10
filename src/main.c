/**
 * @file main.c
 * @author Vladyslav Aviedov <vladaviedov@protonmail.com>
 * @brief Entry point
 * @version 0.1
 * @date 2022-05-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <ncurses.h>

#include "board.h"

int main(void) {
	initscr();
	refresh();
	
	BOARD *board = new_board(16, 16, 5, 5);
	getch();
	
	del_board(board);
	endwin();

	return 0;
}

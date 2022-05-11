/**
 * @file main.c
 * @author Vladyslav Aviedov <vladaviedov@protonmail.com>
 * @brief Entry point
 * @version 0.1.0
 * @date 2022-05-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <ncurses.h>

#include "board.h"
#include "util.h"

int main(void) {
	initscr();
	refresh();

	signal(SIGINT, &quit);
	
	BOARD *board = new_board(16, 16, 5, 5);
	if (board == NULL) {
		fatal(1, "Failed to create board", strerror(errno));
	}

	getch();
	
	del_board(board);
	endwin();

	return 0;
}

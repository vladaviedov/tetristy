/**
 * @file main.c
 * @author Vladyslav Aviedov (vladaviedov@protonmail.com)
 * @brief Entry point.
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
#include "colors.h"
#include "util.h"

int main(void) {
	initscr();
	start_color();
	make_colors();
	refresh();

	signal(SIGINT, &quit);
	
	BOARD *board = new_board(16, 16, 5, 5);
	if (board == NULL) {
		fatal(1, "Failed to create board: %s\n", strerror(errno));
	}

	board->cells[0][0].color = 1;
	board->cells[0][0].touched = 1;

	draw_board(board);
	getch();
	
	del_board(board);
	endwin();

	return 0;
}

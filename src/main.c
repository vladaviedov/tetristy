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
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <ncurses.h>

#include "board.h"
#include "colors.h"
#include "game.h"
#include "util.h"

int main(void) {
	initscr();
	start_color();
	curs_set(0);
	refresh();

	srand(getpid());
	signal(SIGINT, &quit);
	
	make_colors();

	board *board = brd_new(24, 10, 5, 5);
	if (board == NULL) {
		fatal(1, "Failed to create board: %s\n", strerror(errno));
	}

	start_game(board);
	getch();
	
	brd_del(board);
	endwin();

	return 0;
}

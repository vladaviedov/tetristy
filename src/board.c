/**
 * @file board.c
 * @author Vladyslav Aviedov <vladaviedov@protonmail.com>
 * @brief Tetris board
 * @version 0.1
 * @date 2022-05-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "board.h"

#include <stdlib.h>
#include <ncurses.h>

BOARD *new_board(int lines, int cols, int starty, int startx) {
	BOARD *brd = malloc(sizeof(BOARD));
	// todo: proper error checking
	if (brd == NULL) {
		return NULL;
	}

	brd->lines = lines;
	brd->cols = cols;

	brd->border_win = newwin(lines + 2, (cols + 2) * 2, starty, startx);
	box(brd->border_win, ACS_VLINE, ACS_HLINE);
	wrefresh(brd->border_win);
	brd->inner_win = derwin(brd->border_win, lines, cols * 2, 1, 1);
	wrefresh(brd->inner_win);
	
	return brd;
}

void del_board(BOARD *board) {
	if (board == NULL) return;

	delwin(board->border_win);
	delwin(board->inner_win);
	free(board);
}

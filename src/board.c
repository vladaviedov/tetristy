/**
 * @file board.c
 * @author Vladyslav Aviedov <vladaviedov@protonmail.com>
 * @brief Tetris board
 * @date 2022-05-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "board.h"

#include <stdlib.h>
#include <ncurses.h>

/**
 * @brief Create a border window and inner window for the board.
 * 
 * @param lines count of rows
 * @param cols count of columns
 * @param starty start y coordinate
 * @param startx start x coordinate
 * @return BOARD* - new board object
 */
BOARD *new_board(int lines, int cols, int starty, int startx) {
	BOARD *brd = malloc(sizeof(BOARD));
	// todo: proper error checking
	if (brd == NULL) {
		return NULL;
	}

	brd->lines = lines;
	brd->cols = cols;

	// Create border window
	brd->border_win = newwin(lines + 2, (cols + 2) * 2, starty, startx);
	box(brd->border_win, ACS_VLINE, ACS_HLINE);
	wrefresh(brd->border_win);

	// Create inner window
	brd->inner_win = derwin(brd->border_win, lines, cols * 2, 1, 1);
	wrefresh(brd->inner_win);
	
	return brd;
}

/**
 * @brief Free board object and delete windows.
 * 
 * @param board existing board object
 */
void del_board(BOARD *board) {
	if (board == NULL) return;

	delwin(board->border_win);
	delwin(board->inner_win);
	free(board);
}

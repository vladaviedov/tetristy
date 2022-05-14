/**
 * @file board.c
 * @author Vladyslav Aviedov (vladaviedov@protonmail.com)
 * @brief Tetris board.
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
BOARD *new_board(uint32_t lines, uint32_t cols, uint32_t starty, uint32_t startx) {
	BOARD *brd = malloc(sizeof(BOARD));
	if (brd == NULL) {
		return NULL;
	}

	brd->lines = lines;
	brd->cols = cols;

	// Create border window
	brd->border_win = newwin(lines + 2, (cols + 2) * 2, starty, startx);
	if (brd->border_win == NULL) {
		return NULL;
	}
	box(brd->border_win, ACS_VLINE, ACS_HLINE);
	wrefresh(brd->border_win);

	// Create inner window
	brd->inner_win = derwin(brd->border_win, lines, cols * 2, 1, 1);
	if (brd->inner_win == NULL) {
		return NULL;
	}
	wrefresh(brd->inner_win);
	
	// Create board data
	brd->board = malloc(sizeof(cell *) * lines);
	if (brd->board == NULL) {
		return NULL;
	}

	for (uint32_t i = 0; i < lines; i++) {
		brd->board[i] = calloc(sizeof(cell), cols);
		if (brd->board[i] == NULL) {
			return NULL;
		}
	}

	return brd;
}

/**
 * @brief Free board object and delete windows.
 * 
 * @param board existing board object
 */
void del_board(BOARD *board) {
	if (board == NULL) return;

	// Remove windows
	delwin(board->inner_win);
	delwin(board->border_win);

	// Free data
	for (uint32_t i = 0; i < board->lines; i++) {
		free(board->board[i]);
	}
	free(board->board);

	free(board);
}

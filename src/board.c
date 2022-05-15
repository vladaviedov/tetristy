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
#include <string.h>
#include <ncurses.h>

/**
 * @brief Create a border window and inner window for the board.
 * 
 * @param lines count of rows
 * @param cols count of columns
 * @param starty start y coordinate
 * @param startx start x coordinate
 * @return board* - new board object
 */
board *brd_new(int lines, int cols, int starty, int startx) {
	board *brd = malloc(sizeof(board));
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
	brd->cells = malloc(sizeof(cell *) * lines);
	if (brd->cells == NULL) {
		return NULL;
	}

	for (int i = 0; i < lines; i++) {
		brd->cells[i] = calloc(sizeof(cell), cols);
		if (brd->cells[i] == NULL) {
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
void brd_del(board *board) {
	if (board == NULL) return;

	// Remove windows
	delwin(board->inner_win);
	delwin(board->border_win);

	// Free data
	for (int i = 0; i < board->lines; i++) {
		free(board->cells[i]);
	}
	free(board->cells);

	free(board);
}

/**
 * @brief Redraw modified cells.
 * 
 * @param board board
 */
void brd_draw(board *board) {
	for (int i = 0; i < board->lines; i++) {
		for (int j = 0; j < board->cols; j++) {
			cell *cell = &board->cells[i][j];
			if (!cell->touched)
				continue;

			wattr_on(board->inner_win, COLOR_PAIR(cell->color), A_NORMAL);
			mvwaddch(board->inner_win, i, j * 2, ' ');
			waddch(board->inner_win, ' ');
			cell->touched = false;
		}
	}

	wrefresh(board->inner_win);
}

/**
 * @brief Update cell and flag it as touched.
 * 
 * @param board board
 * @param y y-coordinate
 * @param x x-coordinate
 * @param color color pair
 * @returns int - 0 if not modified, 1 if modified
 */
int brd_touch(board *board, int y, int x, int color) {
	if (y < 0 || y >= board->lines)
		return 0;
	if (x < 0 || y >= board->cols)
		return 0;

	cell *c = &board->cells[y][x];
	if (c->solid)
		return 0;

	c->color = color;
	c->touched = true;
	return 1;
}

/**
 * @brief Zero cells and clear the screen.
 * 
 * @param board board
 */
void brd_clear(board *board) {
	if (board == NULL)
		return;

	for (int i = 0; i < board->lines; i++) {
		memset(board->cells[i], 0, sizeof(cell) * board->cols);
	}

	wclear(board->inner_win);
	wrefresh(board->inner_win);
}

/**
 * @file board.h
 * @author Vladyslav Aviedov (vladaviedov@protonmail.com)
 * @brief Tetris board.
 * @date 2022-05-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TETRISTY_BOARD_H
#define TETRISTY_BOARD_H

#include <ncurses.h>
#include <stdbool.h>

typedef struct {
	bool solid;
	bool touched;
	int color;
} cell;

typedef struct {
	// Dimensions
	int lines;
	int cols;

	// Board state
	cell **cells;

	// Ncurses windoes
	WINDOW *border_win;
	WINDOW *inner_win;
} board;

/**
 * @brief Create new tetris board.
 * 
 * @param lines count of rows
 * @param cols count of columns
 * @param starty start y coordinate
 * @param startx start x coordinate
 * @return BOARD* - new board object
 */
board *brd_new(int lines, int cols, int starty, int startx);

/**
 * @brief Delete a board object.
 * 
 * @param board board
 */
void brd_del(board *board);

/**
 * @brief Draw the current board state.
 * 
 * @param board board
 */
void brd_draw(board *board);

/**
 * @brief Change one cell in the board.
 * 
 * @param board board
 * @param y y-coordinate
 * @param x x-coordinate
 * @param color color pair
 * @returns int - 0 if no change, 1 if changed
 */
int brd_touch(board *board, int y, int x, int color);

/**
 * @brief Clear board.
 * 
 * @param board board
 */
void brd_clear(board *board);

#endif // TETRISTY_BOARD_H

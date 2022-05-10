/**
 * @file board.h
 * @author Vladyslav Aviedov <vladaviedov@protonmail.com>
 * @brief Tetris board
 * @date 2022-05-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TETRISTY_BOARD_H
#define TETRISTY_BOARD_H

#include <ncurses.h>

/**
 * @brief Tetris board
 * 
 */
typedef struct {
	int lines;
	int cols;

	WINDOW *border_win;
	WINDOW *inner_win;
} BOARD;

/**
 * @brief Create new tetris board.
 * 
 * @param lines count of rows
 * @param cols count of columns
 * @param starty start y coordinate
 * @param startx start x coordinate
 * @return BOARD* - new board object
 */
BOARD *new_board(int lines, int cols, int starty, int startx);

/**
 * @brief Delete a board object.
 * 
 * @param board existing board object
 */
void del_board(BOARD *board);

#endif // TETRISTY_BOARD_H

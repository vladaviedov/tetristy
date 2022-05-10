/**
 * @file board.h
 * @author Vladyslav Aviedov <vladaviedov@protonmail.com>
 * @brief Tetris board
 * @version 0.1
 * @date 2022-05-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TETRISTY_BOARD_H
#define TETRISTY_BOARD_H

#include <ncurses.h>

typedef struct {
	int lines;
	int cols;

	WINDOW *border_win;
	WINDOW *inner_win;
} BOARD;

BOARD *new_board(int lines, int cols, int starty, int startx);
void del_board(BOARD *board);

#endif

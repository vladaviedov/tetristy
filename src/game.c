/**
 * @file game.c
 * @author Vladyslav Aviedov (vladaviedov@protonmail.com)
 * @brief 
 * @date 2022-05-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "game.h"

#include "board.h"
#include "blocks.h"

static board *gamebrd = NULL;

int start_game(board *brd) {
	if (gamebrd != NULL) {
		return -1;
	}

	gamebrd = brd;
	brd_clear(gamebrd);

	block bl = bl_make(0, 2);
	for (int i = 0; i < 4; i++) {
		brd_touch(gamebrd, bl.y[i], bl.x[i], bl.color);
	}

	brd_draw(gamebrd);
	return 0;
}



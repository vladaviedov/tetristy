/**
 * @file blocks.c
 * @author Vladyslav Aviedov (vladaviedov@protonmail.com)
 * @brief 
 * @date 2022-05-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "blocks.h"

#include <stdlib.h>
#include <string.h>

#include "colors.h"

#define BLOCK_TYPES 7

struct block_func {
	block_type type;
	void (*func)(block *);
};

// Initializers
void init_i(block *bl);

// Rotaters
void rotate_i(block *bl);

static struct block_func init_table[BLOCK_TYPES] = {
	{ BT_I, &init_i }
};

static struct block_func rotate_table[BLOCK_TYPES] = {
	{ BT_I, &rotate_i }
};

/**
 * @brief Init a random type of block.
 * 
 * @param y starting y
 * @param x starting x
 * @return block - produced block
 */
block bl_make(int y, int x) {
	block bl;
	// bl.type = rand() * BLOCK_TYPES;
	bl.type = BT_I;
	bl.color = bl.type + 1;
	bl.y[0] = y;
	bl.x[0] = x;

	init_table[bl.type].func(&bl);
	return bl;
}

void bl_rotate(block *bl) {
	rotate_table[bl->type].func(bl);
}

void bl_up(block *bl) {
	for (int i = 0; i < 4; i++) {
		bl->y[i]++;
	}
}

void bl_down(block *bl) {
	for (int i = 0; i < 4; i++) {
		bl->y[i]--;
	}
}

void bl_left(block *bl) {
	for (int i = 0; i < 4; i++) {
		bl->x[i]--;
	}
}

void bl_right(block *bl) {
	for (int i = 0; i < 4; i++) {
		bl->x[i]++;
	}
}

/* Initializers */

void init_i(block *bl) {
	for (int i = 1; i < 4; i++) {
		bl->y[i] = bl->y[0];
	}
	for (int i = 1; i < 4; i++) {
		bl->x[i] = bl->x[0] + i;
	}
}

/* Rotaters */

void rotate_i(block *bl) {
	// One down, one right
	bl->y[0]--;
	bl->x[0]++;

	// One up, one left
	bl->y[2]++;
	bl->x[2]--;

	// Two up, one left
	bl->y[3] += 2;
	bl->x[3]--;
}

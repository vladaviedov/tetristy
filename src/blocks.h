/**
 * @file blocks.h
 * @author Vladyslav Aviedov (vladaviedov@protonmail.com)
 * @brief 
 * @date 2022-05-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TETRISTY_BLOCKS_H
#define TETRISTY_BLOCKS_H

typedef enum {
	BT_I,
	BT_J,
	BT_L,
	BT_O,
	BT_S,
	BT_T,
	BT_Z
} block_type;

typedef struct {
	block_type type;
	int color;
	int y[4];
	int x[4];
} block;

/**
 * @brief Create a new random block.
 * 
 * @param y top right y-coordinate
 * @param x top right x-coordinate
 * @return block - new block
 */
block bl_make(int y, int x);

/**
 * @brief Rotate a block in place.
 * 
 * @param bl block
 */
void bl_rotate(block *bl);

/**
 * @brief Move block up.
 * 
 * @param bl block
 */
void bl_up(block *bl);

/**
 * @brief Move block down.
 * 
 * @param bl block
 */
void bl_down(block *bl);

/**
 * @brief Move block left.
 * 
 * @param bl block
 */
void bl_left(block *bl);

/**
 * @brief Move block right.
 * 
 * @param bl block 
 */
void bl_right(block *bl);

#endif // TETRISTY_BLOCKS_H

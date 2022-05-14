/**
 * @file colors.h
 * @author Vladyslav Aviedov (vladaviedov@protonmail.com)
 * @brief ncurses color settings.
 * @date 2022-05-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TETRISTY_COLORS_H
#define TETRISTY_COLORS_H

#define CLR_DEFAULT 0
#define CLR_I 1
#define CLR_J 2
#define CLR_L 3
#define CLR_O 4
#define CLR_S 5
#define CLR_T 6
#define CLR_Z 7

/**
 * @brief Create color pairs.
 * 
 */
void make_colors();

#endif // TETRISTY_COLORS_H

/**
 * @file util.h
 * @author Vladyslav Aviedov (vladaviedov@protonmail.com)
 * @brief Utility package.
 * @date 2022-05-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TETRISTY_UTIL_H
#define TETRISTY_UTIL_H

/**
 * @brief Quit the program gracefully.
 * 
 * @param value exit value
 */
void quit(int value);

/**
 * @brief Report fatal error.
 * 
 * @param code exit code
 * @param format printf style format
 * @param ... printf arguments
 */
void fatal(int code, char *format, ...);

#endif // TETRISTY_UTIL_H

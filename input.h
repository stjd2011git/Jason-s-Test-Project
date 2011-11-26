/*
 * input.h
 *
 *  Created on: Oct 14, 2011
 *      Author: Jason Jun Deng
 *
 *  Functions for reading the input text files.
 *
 *  Quick Summary:
 *  	read_board_config  - inputs data on board size, letter point values, and
 *  						 location of premium squares
 *  	read_player_config - inputs data on the rack and current letters on the board
 *  	read_wordlist 	   - inputs the word list
 *  	count_wild 		   - counts the number of wild cards in our rack
 */

#ifndef INPUT_H_
#define INPUT_H_

/*
 * file names
 */
#define BOARD_FILE_NAME 	"Data\\board_config.txt"
#define PLAYER_FILE_NAME 	"Data\\player_config.txt"
#define WORDLIST_FILE_NAME	"Data\\wordlist.txt"

/*
 * Read the board configuration data in the following order
 * 1. Dimension of the square board: N
 * 2. Point value of each letter
 * 3. NxN matrix of premium score square locations
 *
 * Reads from board_config.txt
 */
int read_board_config(void);

/*
 * Read the player configuration data in the following order
 * 1. 7 letters on the rack (a-z) with possibly up to 2 wild cards (8)
 * 2. NxN matrix indicative of current letters already placed on the board
 *
 * Reads from player_config.txt
 */
int read_player_config(void);

/*
 * Input the word list while filtering out words that are too long for the board dimensions
 * Reads from wordlist.txt
 */
int read_wordlist(void);

/*
 * Count the number of wild cards in the rack
 */
int count_wild(void);

#endif /* INPUT_H_ */

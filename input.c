/*
 * input.c
 *
 *  Created on: Oct 14, 2011
 *      Author: Jason Jun Deng
 * 	
 *	Read input data from text files
 *	Now also notifies OnTime
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "globals.h"
#include "place.h"

int read_board_config(void){
	FILE *board_file;
	char temp[4];
	int i;

	board_file = fopen(BOARD_FILE_NAME,"r");
	if (board_file == NULL){
		printf("%s not found\n", BOARD_FILE_NAME);
		return 1;
	}

	/* read the board size */
	fscanf(board_file, "%d", &board_size);

	/* read the alphabet letter point values */
	for (i=0; i<ALPHABET_SIZE; i++){
		fscanf(board_file, "%s", temp);
		letter[i].alpha = temp[0];

		fscanf(board_file, "%s", temp);
		letter[i].pt_value = atoi(temp);
	}

	/* input the location of premium score squares */
	for (i=0; i<board_size; i++){
		fscanf(board_file, "%s", prem_sqr[i]);
	}

	fclose(board_file);
	return 0;
}

int read_player_config(void){
	FILE *player_file;
	int i;

	player_file = fopen(PLAYER_FILE_NAME,"r");
	if (player_file == NULL){
		printf("%s file not found\n", PLAYER_FILE_NAME);
		return 1;
	}

	/* read player rack */
	fscanf(player_file, "%s", rack);

	/* input the current location of words/letters on the board */
	for (i=0; i<board_size; i++){
		fscanf(player_file, "%s", board_letters[i]);
	}

	fclose(player_file);
	return 0;
}

int read_wordlist(void){
	FILE *wordlist_file;
	int i, j;

	wordlist_file = fopen(WORDLIST_FILE_NAME,"r");
	if (wordlist_file == NULL){
		printf("%s file not found\n", WORDLIST_FILE_NAME);
		return 1;
	}

	/* only input the words that fit onto the board */
	j = 0;
	for (i=0; i<MAX_WORDLIST_SIZE; i++){
		fscanf(wordlist_file, "%s", wordlist[j]);

		if ((strlen(wordlist[j]) <= board_size) && word_filter(wordlist[j]))
			j++;

		if (feof(wordlist_file)) {
			strcpy(wordlist[j], END_OF_LIST);
			break;
		}
	}

	fclose(wordlist_file);
	return 0;
}

int count_wild(void){
	int i;

	num_wild = 0;

	/* iterate through our entire rack */
	for (i=0; i<RACK_SIZE; i++){
		if (rack[i] == WILD_CARD)
			num_wild++;
	}
	return 0;
}



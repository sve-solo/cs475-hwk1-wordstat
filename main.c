/*
 * main.c
 *
 *  Created on: Jun 15, 2015
 *      Author: dchiu
 */
#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "stats.h"
#include "menu.h"

/**
 * @brief Main function
 *
 * @param argc Ignore
 * @param argv Ignore
 * @return int
 */
int main(int argc, char *argv[]) {
	// declare and initialize the histogram
	int histogram[ALPHABET_SIZE] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	// TODO: start by getting strings from users until # is input
	// TODO: after # is input, print menu options

	//holds strings user enters
	char string[MAX_INPUT_LEN];
	//holds copy of string array
	char copy[MAX_INPUT_LEN];
	//holds info sent to hisogram
	char storage[MAX_INPUT_LEN];

	//vars to keep track of vowel/consonant frequency
	int total = 0;
	int vowels = 0;
	int consonants = 0;
	double percentVow = 0.0;
	double percentCon = 0.0;
	int i;

	//used to tokenize string
	char *pch;

	//set initial option to be 3, to ask user for strings
	int opt = 3;

	while (opt != 4){
		//if an unknown option is pushed, tell that to user
		if(opt < 0 || opt > 4){
			printf("Unknown option %d\n\n", opt);
		}

		//ask user for strings and update statistics
		if(opt == 3){
			printf("Enter strings (# to stop):\n");
			
			//clear string array
			for(int i = 0; i < MAX_INPUT_LEN; i++){
				string[i] = '\0';
			}
			
			//ask user for strings until they push '#
			while(strncmp(string, "#", 1) != 0){
				fgets(string, MAX_INPUT_LEN, stdin);
		
				//store copy into array storage
				strcat(storage, copy);

				//clear copy
				for(int i = 0; i < MAX_INPUT_LEN; i++){
					copy[i] = '\0';
				}

				//check that user enters valid chars
				for(int i = 0; i < strlen(string); i++){
					int temp = (int) string[i];
					//if the user entered '#', do not replace it
					if(temp == 35){
						string[i] = string[i];
					}
					//else replace any non-alphabet letters with space char
					else if ((temp > 90 && temp < 97) || temp > 122 || temp < 65) {
            			string[i] = ' ';
        			}
        			//change any uppercase chars to lowercase
        			if (string[i] >= 'A' && string[i] <= 'Z') {
            			string[i] += 32;
        			}
    			}

				//tokenize string user entered
				pch = strtok(string, " \n#");
    			while (pch != NULL){
					strcat(copy, pch);
       				pch = strtok(NULL, " \n#");
    			}

				//get number of vowels in the string
				for(i = 0; i < strlen(copy); i++){
					if(copy[i] == 'a' || copy[i] == 'e'|| copy[i] == 'i' || copy[i] == 'o' || copy[i] == 'u'){
					vowels++;	
					}
				}

				//calculate the vowel and consonant frequency
				total = total + i;
				consonants = (total - vowels);
				percentVow =  (vowels / (double) total) * 100;
				percentCon = (consonants / (double) total) * 100;

			}
		
		}

		//print the vowel and consonant frequency
		if(opt == 1){
			printf("Vowels = %d (%.2f%%), ", vowels, percentVow);
			printf("Consonants = %d (%.2f%%), Total = %d\n\n", consonants, percentCon, total);
		}
		
		//print the histogram
		if(opt == 2){
			printf("\n");

			//call function to make histogram
			makeHisto(storage, histogram);
			printf("\n");

			//clear storage array
			for(int i = 0; i < strlen(storage); i++){
				storage[i] = '\0';
			}

		}
		
		//ask user for option again
		opt = getMenuOption();

	}

	printf("Exiting...\n");

	return 0;
}

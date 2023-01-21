/*
 * histo.c
 */

#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "stats.h"

// TODO: function definitions for dealing with histogram below

/**
 *  Prints the letter frequencies and alphabet for the histogram
 *  @param histogram The histogram to print letter frequencies from
*/
void printHisto(int histogram[]){
    //for loop to print out alphabet
    for(int i = 97; i < 123; i++){
        //print out char
        char c = i;
        printf("%c ", c);
    }
    
    printf("\n");

    //print out frequencies of letters below the alphabet
    for(int i = 0; i < 26; i++){
        printf("%d ", histogram[i]);
    }

    printf("\n");
}

/**
 *  Creates the histogram by recording letter frequencies of user-entered strings
 *  @param storage The strings to record on the histogram
 *  @param histogram Where to put record the letter frequencies
*/
void makeHisto(char storage[], int histogram[]){
    //stores copy of histogram data
    int histoCopy[ALPHABET_SIZE];

    //get frequencies of letters
    for(int i = 0; i < strlen(storage); i++){
        //get ascii code of char
        int val = (int) storage[i];
        //store it in the histogram array
        histogram[val - 97]++;
    }

    //create copy of histogram
    for(int i = 0; i < ALPHABET_SIZE; i++){
       histoCopy[i] = histogram[i];
    }

    //get the max letter frequency in histoCopy
    //temp max value
    int max = histoCopy[0];
    for(int i = 1; i < ALPHABET_SIZE; i++){
        int temp = histogram[i];
        if(temp > max){
            max = temp;
        }
    }

    //print stars
    while(max != 0){
        for(int i = 0; i < ALPHABET_SIZE; i++){
            //if the frequency equals the max value
            if(histoCopy[i] == max){
                //print a star
                printf("* ");
                //decrease that value by one
                histoCopy[i]--;
            }
            else{
                //print a space
                printf("  ");
            }
            //move curser to new line once the end of the row is reached
            if(i == ALPHABET_SIZE - 1){
                printf("\n");
                max--;
            }
        }

    }

    //print histogram
    printHisto(histogram);
}

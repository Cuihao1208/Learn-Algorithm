/*
This program is to calculate every word appears numbers in the text.
本程序用来计算文档中每个单词出现的次数。

 */


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define TEXTLEN 10000   /* Maximum length of text */
#define BUFFERSIZE 100  /* Input buffer size */
#define MAXWORDS 500
#define WORDLEN 15


int main(void){
    char text[TEXTLEN+1];
    char buffer[BUFFERSIZE];
    char endstr[] = "*\n";   // Signals end of input
    
    const char space = ' ';
    const char quote = '\'';
    
    char words[MAXWORDS][WORDLEN+1];
    int nword[MAXWORDS];    // number of word occurrences
    char word[WORDLEN+1];   // Stores a single word
    int wordlen = 0;        // length of a word
    int wordcount = 0;      // number of words stored
    
    printf("Enter text on an arbitrary number of lines.");
    printf("\nEnter a line containing just an astersik to end input:\n\n");
    
    /* Read an arbitrary number of lines of text */
    while (true) {
        /* A string containing an asterisk followed by newline signal end of input*/
        if (!strcmp(fgets(buffer, BUFFERSIZE, stdin), endstr)) {
            break;
        }
        
        if(!strlen(text)+strlen(buffer)+1 > TEXTLEN){
            printf("Maximum capacity for text exceeded. Terminating program.");
            return 1;
        }
        strcat(text, buffer);
        
    }
    /* Replace everything except alpha and single quote characters by spaces */
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == quote || isalnum(text[i])) {
            continue;
        }
        text[i] = space;
    }
    
    /* Find unique words and store in words array */
    int index = 0;
    while (true) {
        /* Ignore any leading spaces before a word */
        while (text[index] == space) {
            ++index;
        }
        /* If we are at the end of text, we are done */
        if (text[index] == '\0') {
            break;
        }
        /* Extract a word */
        wordlen = 0;    //reset word length
        while (text[index] == quote || isalpha(text[index])) {
            /* check if word is too long*/
            if(wordlen == WORDLEN){
                printf("Maximum word length exceeded. Terminating program.");
                return 1;
            }
            word[wordlen++] = tolower(text[index++]);   // copy as lowercase
        }
        word[wordlen] = '\0';  //add string terminator
        
        /* Check for word already stored */
        bool isnew = true;
        for (int i = 0; i < wordcount; i++) {
            if (strcmp(word, words[i]) == 0) {
                ++nword[i];
                isnew = false;
                break;
            }
        }
        if (isnew) {
            /* Check if we hae space for another word */
            if (wordcount >= MAXWORDS) {
                printf("\n Maximum word count esceeded. Terminating program.");
                return 1;
            }
            strcpy(words[wordcount], word); //store the new word
            nword[wordcount++] = 1;         //set its count to 1
        }
    }
    /* Output the words and frequences */
    for (int i = 0; i < wordcount; i++) {
        if (!(i%1)) {
            printf("\n");
            printf(" %-15s%5d", words[i], nword[i]);
        }
    }
    
    /* Plus the rest of the program*/
    
    return 0;
}
/*
* WordCounter314 by Artjom Moisejev - Copyright (C) 2021 <domain_69@hotmail.de>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, version 3.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// scan first input Text and return pointer
char* scanText()
{
    char* text;
    char buf[1001];
    printf("text: ");
    fgets(buf, 1000, stdin);
    text=(char*)calloc(strlen(buf)+1, sizeof(char));
    strcpy(text, buf);
    return text;
}

// scan words, count them, update count via pointer
// and return dynamically allocated list of words.
char** scanWords(int* _counter) {
    printf("words: ");    // own code, to keep main() clean.
    char** words= (char**)calloc(1, sizeof(char*)), **tmp; // allocate memory for the list
    int i=0;
    while(1) {
        char buf[81];   // make buffer
        scanf("%80s", buf);   // scan to buffer
        if(buf[0]=='-') break;
        // allocate memory for tmp (i gets bigger every loop => size grows) and compare with NULL
        if(NULL==(tmp = (char**)realloc(words, sizeof(char*)*(i+2)))) {
            printf("out of memory");
            break;
        }
        words=tmp;      // point to newly allocated memory
        words[i] = ( char*)calloc(strlen(buf)+1, sizeof(char)); //allocate space in size of buffer
        strcpy(words[i], buf);  // copy buffer to list[i]
        i++;      // increase i for next loop
    }
    words[i]=(char*)calloc(1,sizeof(char)); // after last loop allocate empty space as last entry of list
    *_counter = i;    // own code: update word counter via pointer
    return words;
}

// free memory of all list entries and the list itself
void freeAll(char** _words, int _counter)
{
    for (int i = 0; i <= _counter; i++) {
        free(_words[i]);
    }
    free(_words);
}

// count words, while "eating" a copy of the inputtext
void countWord(char* _text, char* _word)
{
    char* temp;
    if ((temp = strchr(_text, _word[0])) == NULL) // search for the first letter of the word and
    {                                             // copy string, beginning with this letter to temp.
        printf("\n%s: 0", _word);                 // NULL pointer = no matches found
    } else {
        int counter = 0, wordLength = strlen(_word); // initialize counter and wordLength
        while(1)
        {
            if (strncmp(temp, _word, wordLength) == 0)  //compare first n bytes (n = wordLength)
            {                                           // == 0 means match
                temp = temp+wordLength; // point temp to itself, but after the found word.
                counter++;    // increase counter
            } else {
                temp = temp+1;  // if no match => point temp to itself, but after first letter
                                // (because of next line, where the first letter already matches)
                temp = strchr(temp, _word[0]);  // point temp to itself, but to first appearence of
                                                // first letter of word.
                if (temp == NULL)  // NULL pointer = no matches found
                {
                    printf("\n%s: %d", _word, counter); // end count and print it
                    break;
                }
            }
        }
    }

}

int main()
{
    int counter, *counterPtr = &counter;
    char* textPtr = scanText();
    char** words = scanWords(counterPtr);
    for (int i = 0; i < counter; i++) {
        countWord(textPtr, words[i]);
    }
    freeAll(words, counter); free(textPtr);
    return 0;
}

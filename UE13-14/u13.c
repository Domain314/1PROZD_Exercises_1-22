/*
* RecursiveScaner314 by Artjom Moisejev - Copyright (C) 2021 <domain_69@hotmail.de>
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
// Global Variables
int errorFlag = 0;
int endSentence = 1;
int *ptr;
int wordLength;

// Print end result
void endResult()
{
  for (int i = 0; i < 81; i++) {
    if (*(ptr+i) != 0){
      printf("Length %d: %d\n", i, *(ptr + i));
    }
  }
}

// Check word length and notate it, if valid.
// "word" = 4 chars = amounts[4] += 1;
// "hello" = 5 chars = amounts[5] += 1;
void endWord()
{
  if (wordLength >= 79) { errorFlag = 1; }
  else if (wordLength != 0)
  {
    *(ptr + wordLength) += 1;
    wordLength = 0;
  }
}

// Check ascii code for accepted chars and increase wordLength.
void checkChar(char _c)
{
  int ascii = _c;
  if (ascii < 65 || (ascii > 90 && ascii < 97) || ascii > 122) {
    errorFlag = 1;
  } else { wordLength++; }
}

// Check one character and invoke self, until "." or linebreak (c == 10)
void recursiveScan()
{
  char c = getchar();
  if (c == ' ') {
    endWord();
    recursiveScan();
  } else if (c == '.'){
    endSentence--;
    endWord();
  } else if (c == 10) {
    errorFlag = 1;
  } else {
    checkChar(c);
    recursiveScan();
  }
}

int main()
{
  // declare int array, set all entries to 0 and set pointer to it.
  int amounts[81];
  for (int i = 0; i < 81; i++) { amounts[i] = 0;}
  ptr = amounts;

  // await user input and begin recursiveScan();
  printf(": ");
  recursiveScan();

  // check for possible errors and "." in input. output result.
  if (errorFlag + endSentence == 0) {
    endResult();
  } else {
    printf("NOT VALID");
  }
  return 0;
}

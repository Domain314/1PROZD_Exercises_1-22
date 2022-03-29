#include <stdio.h>

int errorFlag = 0;
int endSentence = 1;
int *ptr;
int wordLength;

void endResult()
{
  for (int i = 0; i < 81; i++) {
    if (*(ptr+i) != 0){
      printf("Length %d: %d\n", i, *(ptr + i));
    }
  }
}

void endWord()
{
  if (wordLength >= 79) { errorFlag = 1; }
  else if (wordLength != 0)
  {
    *(ptr + wordLength) += 1;
    wordLength = 0;
  }
}

void checkChar(char _c)
{
  int ascii = _c;
  if (ascii < 65 || (ascii > 90 && ascii < 97) || ascii > 122) { errorFlag = 1; }
  else { wordLength++; }
}

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
  int amounts[81];
  for (int i = 0; i < 81; i++) { amounts[i] = 0; }
  ptr = amounts;
  printf(": ");
  recursiveScan();
  if (errorFlag + endSentence == 0) { endResult(); }
  else { printf("NOT VALID"); }
  return 0;
}

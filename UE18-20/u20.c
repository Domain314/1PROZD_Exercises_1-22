#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct array
{
  char* ID;
  int* arr;
}array;

void printColon()
{
  printf("\n: ");
}

array setupArray(int _length0, int _length1)
{
  printColon();
  array newArray;
  newArray.ID = (char*)malloc((_length0+_length1)*sizeof(char));
  newArray.arr = (int*)malloc((_length0+_length1)*sizeof(int));
  int counter = 0;
  for (int i = 0; i < _length0; i++) {
    scanf(" %d", &newArray.arr[counter]);
    newArray.ID[counter] = '0';
    counter++;
  }
  printColon();
  for (counter; counter < _length0+_length1; counter++) {
    scanf(" %d", &newArray.arr[counter]);
    newArray.ID[counter] = '0';
  }
  return newArray;
}

array sumupArrays();

int setupLength()
{
  int i;
  scanf(" %d", &i);
  return i;
}

void freeArrays(array* _arr)
{
  free(_arr->ID);
  free(_arr->arr);
}

void calculateSmallestDiff(array* _array0, array* _array1)
{
  int l0 = _array0->arr[0], l1 = _array1->arr[0];
  array overray, *overPtr = &overray;
  overray.ID = (char*)malloc((l0+l1)*sizeof(char));
  overray.arr = (int*)malloc((l0+l1)*sizeof(int));

  int counter = 0;
  for (int i = 1; i <= l0; i++) {
    overray.arr[counter] = _array0->arr[i];
    overray.ID[counter] = '0';
    counter++;
  }
  for (int j = 1; j <= l1; j++) {
    overray.arr[counter] = _array1->arr[j];
    overray.ID[counter] = '1';
    counter++;
  }
  for (int h = 0; h < l0+l1; h++) {
    printf("\n%d - %d", overray.arr[h], overray.ID[h]);
  }

  //printf("\n%d (%d, %d)", i, x, y);
  freeArrays(overPtr);
}



int main()
{
  printColon();
  int length0 = setupLength(), length1 = setupLength();
  array numbers0 = setupArray(length0), numbers1 = setupArray(length1);
  array* num0 = &numbers0, *num1 = &numbers1;
  calculateSmallestDiff(num0, num1);
  freeArrays(num0);
  freeArrays(num1);
  return 0;
}

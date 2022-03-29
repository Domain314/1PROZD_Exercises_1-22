#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct array
{
    int* ID;
    int* arr;
}array;

typedef struct vector3
{
    int c0;
    int c1;
    int dif;
}vector3;

array setupArray(int _length0, int _length1)
{
    array newArray;
    newArray.ID = (int*)malloc((_length0+_length1)*sizeof(int));
    newArray.arr = (int*)malloc((_length0+_length1)*sizeof(int));
    int counter = 0;
    for (int i = 0; i < _length0; i++) {
        scanf(" %d", &newArray.arr[counter]);
        newArray.ID[counter] = 0;
        counter++;
    }
    for (counter = counter; counter < _length0+_length1; counter++) {
        scanf(" %d", &newArray.arr[counter]);
        newArray.ID[counter] = 1;
    }
    return newArray;
}

int setupLength()
{
    int i;
    scanf(" %d", &i);
    return i;
}

void freeArray(array* _arr)
{
    free(_arr->ID);
    free(_arr->arr);
}

void swap(int* _a, int* _b)
{
    *_a = *_a + *_b;
    *_b = *_a - *_b;
    *_a = *_a - *_b;
}

void sortSub(array* _arr, int _length)
{
    for (int i = 0; i < _length-1; i++) {
        for (int j = 0; j < _length-i-1; j++) {
            if (_arr->arr[j] > _arr->arr[j+1])
            {
                swap(&_arr->arr[j], &_arr->arr[j+1]);
                swap(&_arr->ID[j], &_arr->ID[j+1]);
            }
        }
    }
}

void calculateSmallestDiff(array* _arr, int _length)
{
    sortSub(_arr, _length);
    vector3 smallest = {0, 999999, 999999};
    for (int i = 0; i < _length-1; i++) {
        if (_arr->ID[i] != _arr->ID[i+1])
        {

            vector3 candidate = {
                    _arr->arr[i],
                    _arr->arr[i+1],
                    abs(_arr->arr[i] - _arr->arr[i+1])
            };
            if (candidate.dif < smallest.dif)
            {
                smallest = candidate;

            }

        }
    }
    printf("%d (%d, %d)", smallest.dif, smallest.c0, smallest.c1);
}

int main()
{
    printf(": ");
    int length0 = setupLength(), length1 = setupLength();
    array newArray = setupArray(length0, length1), *nAPtr = &newArray;
    calculateSmallestDiff(nAPtr, length0+length1);
    freeArray(nAPtr);
    return 0;
}

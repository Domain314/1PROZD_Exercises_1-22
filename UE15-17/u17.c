/*
* NextPermutation314 by Artjom Moisejev - Copyright (C) 2021 <domain_69@hotmail.de>
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

// struct for sequence holding and passing
typedef struct sequence
{
    int amount;
    int* seq;
}sequence;

// print sequence
void printSeq(sequence* _seq)
{
    printf("\n");
    for (int i = (_seq->amount)-1; i >= 0; i--) {
        printf("%d ", _seq->seq[i]);
    }
}

// ask for and scan input
int scanAmount()
{
    int input;
    printf(": "); scanf(" %d", &input); printf(": ");
    return input;
}

// setup a sequence struct and return it
sequence setupSeq()
{
    sequence newSeq;
    newSeq.amount = scanAmount();
    newSeq.seq = (int*)calloc(newSeq.amount,sizeof(int)*newSeq.amount);
    for (int i = newSeq.amount -1; i >= 0 ; i--) {
        int t;
        scanf("%d", &t);
        newSeq.seq[i] = t;
    }
    return newSeq;
}

// swap to pointer
void swap(int* _a, int* _b)
{
    *_a = *_a + *_b;
    *_b = *_a - *_b;
    *_a = *_a - *_b;
}

// bubble sort
void sortSub(int _subSeq[], int _sLenght)
{
    int sLength = _sLenght;
    for (int i = 0; i < sLength-1; i++) {
        for (int j = 0; j < sLength-i-1; j++) {
            if (_subSeq[j] < _subSeq[j+1])
                swap(&_subSeq[j], &_subSeq[j+1]);
        }
    }
}

// return Length of subSequence
int subSeqLength(sequence* _seq)
{
    int counter = 1;
    for (int i = 0; i < _seq->amount; i++) {
        if(_seq->seq[i] < _seq->seq[i+1]) { counter++; }
        else break;
    }
    return counter;
}

// calculate next permutation and set sequence
void nextPermutation(sequence* _seq)
{
    // 1. make subSequence
    int sLength = subSeqLength(_seq), subSeq[sLength];
    for (int i = 0; i < sLength; i++) {
        subSeq[i] = _seq->seq[i];
    }
    // 2. get next highest after seq[sLength]
    if (sLength != _seq->amount) {
        int firstAfterSub = _seq->seq[sLength];
        for (int j = 0; j < sLength; j++) {
            if (subSeq[j] > firstAfterSub) {
                _seq->seq[sLength] = _seq->seq[j];
                subSeq[j] = firstAfterSub;
                break;
            }
        }
    }
    // 3. sort subSeq and copy to main sequence
    sortSub(subSeq, sLength);
    for (int i = 0; i < sLength; ++i) {
        _seq->seq[i] = subSeq[i];
    }
}

int main()
{
    sequence newSeq = setupSeq(), *newSeqPtr = &newSeq;
    // for 720 (6!) numbers
    for (int i = 0; i < 720; i++) {
      nextPermutation(newSeqPtr);
      printSeq(newSeqPtr);
    }

    free(newSeq.seq);
    return 0;
}

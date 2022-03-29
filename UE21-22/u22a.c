#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* scanInput(int* counter_)
{
    printf(": ");
    int buf[1025], input, counter, *nums;
    for(counter = 0; counter < 1025; counter++) {
        scanf(" %d", &input);
        if (input == 0) break;
        buf[counter] = input;
    }
    counter_[0] = counter;
    nums = (int*)malloc(sizeof(int)*counter);
    memcpy(nums, buf, counter*sizeof(int));
    return nums;
}

void printStep(int* nums_, int* countV4)
{
  printf("\nStep %d: ", countV4[2]+1);
  for (int i = 0; i < countV4[0]; i++) {

    if (i == countV4[1]) printf("[");
    if (i == countV4[2]) printf("(");
    printf("%d", nums_[i]);
    if (i == countV4[2]) printf(")");
    if (i == countV4[1]) printf("]");
    printf(" ");
  }
}

void selection_sort(int* a, int* N)
{
    int j, t, c = 0;
    for(N[2] = 0; N[2] < N[0]-1; N[2]++)
    {
        N[1] = N[2];
        for (j = N[2]+1; j < N[0]; j++) // suche kleinstes El.
        {
            c++;
            if (a[j] < a[N[1]])
                N[1] = j; // merke Position des kleinsten El.
        }
        printStep(a, N);
        t = a[N[1]]; // Tausch
        a[N[1]] = a[N[2]];
        a[N[2]] = t;
    }
    N[3] = c;
}

void printResult(int* nums, int* countV4)
{
  printf("\nResult: ");
  for (int i = 0; i < countV4[0]; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n\nNumber of comparisons: %d", countV4[3]);
  printf("\nNumber of swaps: %d", countV4[0]-1);
  free(countV4);
  free(nums);
}

int main()
{
    int* countVector3 = (int*)malloc(sizeof(int)*4), *nums = scanInput(countVector3);
    selection_sort(nums, countVector3);
    printResult(nums, countVector3);
    return 0;
}

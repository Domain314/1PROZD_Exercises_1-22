#include <stdio.h>

int largest(int nums[])
{
  int max = 0;

  for (size_t i = 0; i < 5; i++) {
    if (nums[i] > max){
      max = nums[i];
    }
  }
   return max;
}


int smallest(int nums[])
{
  int min = 99;

  for (size_t i = 0; i < 5; i++) {
    if (nums[i] < min){
      min = nums[i];
    }
  }
   return min;
}

int summe(int nums[])
{
  int sum = 0;

  for (size_t i = 0; i < 5; i++) {
    sum += nums[i];
  }

  return sum;
}

int main()
{
  printf(": ");

  int nums[5] = {};
  scanf("%d %d %d %d %d", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4]);

  int sum = summe(nums);

  printf("minimum sum: %d\n", sum - largest(nums));
  printf("maximum sum: %d", sum - smallest(nums));

  return 0;
}

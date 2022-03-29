#include <stdio.h>

double calcAvg(int _cnt, float _sum)
{
  if (_sum/_cnt > 5.5) {
    return _sum/_cnt;
  } else {
    return _sum/_cnt;
  }
}

int main()
{
  int cnt;
  double sum = 0, min = 9999, max = 0, avg = 0, userInput;
  printf(": ");
  scanf("%lf", &userInput);
  if (userInput <= 0) {
    printf("no number entered");
  } else {
    while (userInput > 0)
    {
      cnt++;
      min = userInput < min ? userInput : min;
      max = userInput > max ? userInput : max;
      sum += userInput;
      avg = calcAvg(cnt, sum);
      printf(": ");
      scanf("%lf", &userInput);
    }

    printf("cnt: %d\n", cnt);
    printf("min: %.2lf\n", min);
    printf("max: %.2lf\n", max);
    printf("avg: %.2lf\n", avg);
  }

  return 0;
}

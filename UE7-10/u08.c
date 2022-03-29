#include <stdio.h>

int main()
{
  int month, day;
  printf("number of days in month: ");
  scanf("%d\n", &month);
  printf("starting day of week (1=Monday, 7=Sunday): ");
  scanf("%d\n", &day);
  printf("\n");

  for (int d = 1; d < day; d++) {
    printf("   ");
  }

  for (int i = 1; i <= month; i++) {
    if (i <= 9) { printf(" "); }
    printf("%d ", i);
    if ((day + i - 1) % 7 == 0) { printf("\n"); }
  }

  return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hour;
    int min;
    char ampm[2] = "PM";
    printf("24h time: ");
    scanf("%d:%d", &hour, &min);


    if (hour >= 0 && hour < 12) {
      ampm[0] = 'A';
    } else if (hour == 0){
      hour = 12;
    }

      if (hour > 12) {
        hour -= 12;

        if (hour < 10) {
          printf("12h time:  %d:%02d", hour, min);
        } else {
          printf("12h time: %d:%02d", hour, min);
        }

      }else {
        if (hour < 1 || hour == 12) {
          hour = 12;
        }
        printf("12h time: %d:%02d", hour, min);
      }

      printf(" %s", ampm);


    return 0;
}

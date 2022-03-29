#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hour;
    int min;
    //char str[2] = " ";
    char ampm[2] = "AM";
    printf("24h time: ");
    scanf("%d:%d", &hour, &min);

/*
    if (hour == 0) {
      ampm[0] = 'P';
    }
*/
      if (hour > 12) {
        hour -= 12;

        if (hour < 10) {
          printf("12h time:  %d:%02d %s", hour, min, ampm);
        } else {
          printf("12h time: %d:%02d %s", hour, min, ampm);
        }

      }else {
        if (hour < 1 || hour == 12) {
          hour = 12;
        }
        printf("12h time: %d:%02d %s", hour, min, ampm);
      }


    return 0;
}



//24h time: 12h time:  \x0b9:11 PM  \x0b

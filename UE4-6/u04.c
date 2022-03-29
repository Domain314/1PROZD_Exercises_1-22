#include <stdio.h>

int main()
{
  int num, h, z, e;
  printf(": ");
  scanf("%d", &num);

  if (num > 99){
    h = num/100;
  } else {
    h = 0;
  }

  if (num > 9){
    z = (num - h*100)/10;
  } else {
    z = 0;
  }

  e = (num%10);

  num = h * 64 + z * 8 + e * 1;

  printf("dec.: %d\n", num);

  if (num > 99){
    h = num/100;
  } else {
    h = 0;
  }

  if (num > 9){
    z = (num - h*100)/10;
  } else {
    z = 0;
  }

  e = (num%10);

  printf("ZS: %d", h + z + e);

  return 0;
}

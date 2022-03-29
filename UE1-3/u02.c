#include <stdio.h>

int main()
{
    int num;
    printf(": ");
    scanf( "%i", &num);
    printf("Surface area: %d\n", 6*num*num);
    printf("Volume: %d\n", num*num*num);
    return 0;
}

#include <stdio.h>

int main()
{
    float num;
    printf(": ");
    scanf( "%f", &num);
    printf("With tax: %.02f\n", num*1.2 );
    return 0;
}

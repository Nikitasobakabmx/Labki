#include "stdio.h"
#include "math.h"

int main(){
    printf("Input x and y\n");
    float x, y;
    scanf("%f, %f", &x, &y);
    if((tan(x) >= y) && (x>= 0) && (x <= 1.5) && (y >=0))
        printf("Succesful");
    else
        printf("Ne Succesful");
    ptintf("\n");
    return 0;
}
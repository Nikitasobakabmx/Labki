#include <stdio.h>
#include <math.h>

int main(){
    float x,y;
    printf("Input x and y\n");
    scanf("%f%f",&x,&y);
    if(((exp(x)-1)<y) && (x > 0) && (x < 2.5) && (y > 0.5))
        printf("Point (%.2f,%.2f) in graphic\n",x,y);
    else 
        printf("Point (%.2f,%.2f) out of graphic\n",x,y);
    return 0;
}
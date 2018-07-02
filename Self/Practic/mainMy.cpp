#include <stdio.h>
#include <math.h>

int main(int argc, char **argv){
    printf("Program %s start\n", argv[0]);
    if(argc != 3){
        printf("Error\nNo args\n");
        return 0;
    }
    float x = atof(argv[1]), y = atof(argv[2]);
    if((y > 0) && (x > 2) && (x < 7) && ((sin(x) + 1) > y))
        printf("Point (%.2f,%.2f) in graphic\n",x,y);
    else 
        printf("Point (%.2f,%.2f) out of graphic\n",x,y);
    return 0;    
}

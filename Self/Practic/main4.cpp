#include <stdio.h>
#define BITES 10

int toBi(int value, int *biArray){
    int i = 0;
    while(value > 0){
        biArray[i] = value%2;
        value /= 2;
        i++;
    }
    return i+1;
}

bool sort(int count, int *biArray){
    int sum = 0;
    for(int i = 0; i < count; i++){
        sum += biArray[i];
    }
    if(sum-2 <= count - sum)
        return true;
    
    else
        return false;    
}

void toZero(int *biArray){
    for(int i = 0; i < BITES; i++)
        biArray[i] = 0;
}

int main(){
    int biArray[BITES];
    for(int i = 200; i < 600; i+=10){
        toZero(biArray);
        if(sort(toBi(i, biArray),biArray))
            printf("%d\t",i);
    }
    printf("\n");
    return 0;
}
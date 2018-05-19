#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int prog(float x, float y) {
	if ((((x - 3) * (x - 3) + (y + 2) * (x - 2))< 9)&&(((x - 4) * (x - 4) + (y - 3) * (y - 3))> 25))
		return 1;
	return 0; 
}

int main() {	
		float x, y;
        FILE *wFile = fopen("ress.txt", "w");
        FILE *rFile = fopen("coord.txt", "r");
        for (int i = 0; i < 5; i++){
		    printf("Type x and y for the dot\n");
		    fscanf(rFile, "%f%f", &x, &y);
            printf("%f\n%f\n", x, y);
		    if (prog(x, y)) {
		    	fprintf(wFile,"yes\n");
                printf("yes\n");
		    }
		    else {
		    	fprintf(wFile,"no\n");
                printf("no\n");
		    }
        }
    fclose(wFile);
    fclose(rFile);
	getch();
	return 0;
}
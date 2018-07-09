#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"Russian");
	printf("Программа начата!\n");
FILE *file = fopen("spisok.txt","r");
	int count = 1;
	int *list = (int*) malloc(sizeof(int)*(count));
	while(fscanf(file,"%d",&list[count-1]) != EOF){
		int *tmp = list;
		list = (int*) malloc(sizeof(int)*(++count));
		for(int i = 0; i < count-1; i++)
			list[i] = tmp[i];
		free(tmp);
	}
	count--;
	fclose(file);
	FILE *fileWrite = fopen("spisok.txt", "w");
	int i = 0;
	line1:
		i++;
		goto line2;
	line2:
		if(list[i] == 0)
			goto line1;
		else
			goto line3;
	line3:
		i--;
		goto line4;
	line4:
		list[i] = 1;
		goto line5;
	line5:
		printf("Прграма закончена!\n");
		system("pause");
	for(int j = 0; j < count; j++)
	fprintf(fileWrite, "%d\n", list[j]);
	fclose(fileWrite);
	free(list);
	return 0;
}
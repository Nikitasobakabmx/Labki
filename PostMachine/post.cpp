#include <stdio.h>
#include <fstream>

int main(){
	printf("!programm run!\n");
	std::ifstream fileRead("list.txt");
	int *list = new int;
	int count = 0;
	while(!fileRead.eof()){
		int *tmp = list;
		list = new int[++count];
		for(int i = 0; i < count-1; i++)
			list[i] = tmp[i];
		fileRead >> list[count-1];
		delete [] tmp;
	}
	fileRead.close();
	std::ofstream fileWrite("list.txt");
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
		printf("!programm complite!\n");
		system("pause");
	for(int j = 0; j < count; j++)
	fileWrite << list[j] << "\n";
	fileWrite.close();
	delete [] list;
	return 0;
}
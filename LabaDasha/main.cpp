#include "my_lab.h"
#include <stdio.h> 
#include <stdlib.h>
#include <locale.h>

int main() { 
setlocale(LC_ALL, "Russian"); 
int a1 = 0, a2 = 0;
int* result = 0;
int ress = 0;
FILE *f = fopen("digits.txt", "rt"); 
fscanf(f, "%d%d", &a1, &a2); 
fclose(f); 
printf("Число 1 = %d\nЧисло 2 = %d\n", a1, a2); 
char *a, *b;
_itoa(a1, a, 2); //запись чисел в массивы // в строку, дура
_itoa(a2, b, 2); //-||-
printf("\nМассивы перед началом работы функции: \n%s\n%s\n", a,b);
ress = my_func(a,b,result);
printf("Ответ тестирующей программы = %d\n\n", a1&a2); //Тестирующая программа 
return 0; 
}
#include <stdio.h> 
#include <cstdlib> 

int main(){
int n = 0; 
int t = 0; 
char rez; 
int buffer[256]; 
FILE *fp; 
//открываем файол на считывание 
fp = fopen("newfile.txt", "r+"); 
//проверяем, не пустой ли файл 
if (fp == NULL) { 
    puts("error"); 
    return 0; 
} 
printf("Открыт файл: newfile.txt \n"); 
printf("Введите порядковый номер искомого символа: "); 
//считываем порядковый номер искомого символа 
scanf("%i",&n); 
//курсор в начало файла 
rewind(fp); 
//бесконечный цикл, считывающий посимвольно файл, пока последующий символ существует 
while (1) { 
    buffer[t] = fgetc(fp); 
    if (buffer[t] == EOF)
        break; 
    if (t == n) 
        rez = buffer[t]; 
    printf("%c", buffer[t]); 
    t++; 
} 
printf("\n"); 
printf("Результат, занесённый в файл: %i", rez); 
//закрытие работы с файлом 
fclose(fp); 
//запись результата в новый файл 
FILE *pp; 
pp = fopen("result.txt", "w+"); 
fprintf(pp, "%i", rez); 
fclose(pp); 
return 0; 
}
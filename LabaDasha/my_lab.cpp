#include "my_lab.h"
#include <stdio.h> 
#include <math.h>
#include <iostream> 
#include <stdlib.h>
#include <string.h>

int my_func(char*a, char*b, int* result)
{
char nmas1[20] = { 0 }, nmas2[20] = { 0 };
int len = strlen(a); //длина первого числа в двоичном
int len2 = strlen(b); //длина второго
int len3 = 0, len4 = 0, q = 0, q2 = 0, s = 0, r = 0; 

if (len2 > len) //Если второе число длиннее, изменяем массив с первым числом
{ 
int raz = len2 - len; //такое количество нулей нужно добавить для поразрядного умножения 
printf("\nРазница = %d", raz); 
for (int i = 0; i <= raz; i++) //Запись нулей в новый массив 
{ 
nmas1[i] = '0'; 
} 
for (int i = 0; i <= len - 1; i++) //Перезапись числа в новый массив (где уже есть необходимые нули), с которым дальше программа будет работать 
{ 
nmas1[i + 1] = a[i];
} 
len4 = strlen(nmas1); 
} 
else 
{ 
for (int i = 0; i <= len - 1; i++) 
{ 
nmas1[i] = a[i];
} 
len4 = strlen(nmas1); 
} 

if (len > len2) //Если первое число длиннее, именяется массив со вторым числом
{ 
int raz = len - len2; //такое количество нулей нужно добавить для поразрядного умножения 
printf("\nРазница = %d символ(а)", raz); 
for (int i = 0; i <= raz; i++) //Запись нулей в новый массив 
{ 
nmas2[i] = '0'; 
} 
for (int i = 0; i <= len2 - 1; i++) //Перезапись числа в новый массив (где уже есть необходимые нули), с которым дальше программа будет работать 
{ 
nmas2[i + raz] = b[i];
} 
len3 = strlen(nmas2); 
} 
else 
{ 
for (int i = 0; i <= len2 - 1; i++) 
{ 
nmas2[i] = b[i];
} 
len3 = strlen(nmas2); 
} 

for (int i = 0; i <= len4 - 1; i++) //Поразрядное умножение; запись результата в отдельную переменную r 
{ 
for (int j = 0; j <= len3 - 1; j++) 
{ 
q = nmas1[i] - '0'; 
q2 = nmas2[j] - '0'; 
s = q*q2; 
r = r * 10 + s; 
i++; 
} 
} 
printf("\nИскомое число в 2 СС = %d\n\n", r); 
printf("Массив 1: %s\nМассив 2: %s\n", nmas1, nmas2); 
char res[20] = { 0 }; 
_itoa(r, rers, 10);
int lenr = strlen(res); 
int sum = 0;
for (int i = lenr - 1; i > -1; i--) //перевод искомого числа из двоичной системы в десятичную 
{ 
if (res[i] == '1') 
{ 
sum += pow(2, lenr - (i + 1)); 
} 
} 
return sum;
}
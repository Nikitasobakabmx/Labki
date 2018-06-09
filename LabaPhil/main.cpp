#include <iostream>
#include <locale>
#include <cstdio>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

int find_word(char* tmp, char* word)
{
bool flag = false;
int len_tmp = strlen(tmp);
int len_word = strlen(word);

for (int i = 0; i < len_tmp; i++)
{
if (tmp[i] == word[0])
{
int l = 0;
for (int j = 0; j < len_word; j++)
if (tmp[i + j] == word[j]) l++;

if (l == len_word)
{
flag = true;
break;
}
}
}

if (flag == true)

return 0;
else
return -1;

}

int main()
{
setlocale(0, "rus");

//открытие файла

FILE *f1 = fopen("E:\\text8.txt", "r"),
*fout = fopen("E:\\result2.txt", "a");
fseek(f1, 0, SEEK_END);
long size = ftell(f1);
fseek(f1, 0, SEEK_SET);
char * tmp = new char[size];

char * word = new char[10];
cout « "Введите искомое слово: " « endl;
cin.sync();
cin.getline(word, 10);
if (size == 0) cout « "Файл пустой!" « endl;

if (!f1) cout « "Файл не открыт" « endl;

else
{
int i = 0;
char ch;
do
{
ch = fgetc(f1);

if (ch != '.')
{
tmp[i] = ch;
}
else
{
tmp[i] = ch;
tmp[i + 1] = '\0';
if (find_word(tmp, word) == 0)
{
fputs(tmp, fout);
i = -1;
}
else i = -1;

}
if (ch == '\n') i = -1;
if (ch == EOF)
{
tmp[i] = '\0';
if (find_word(tmp, word) == 0) fputs(tmp, fout);
}

i++;
} while (ch != EOF);

}
fseek(fout, 0, SEEK_END);
long size1 = ftell(fout);
fseek(fout, 0, SEEK_SET);
if (size1 == 0)cout « "Искомое слово в файле не встретилось." « endl;
else cout « "Предложения записанны в файл." « endl;
system("pause");
return 0;
}
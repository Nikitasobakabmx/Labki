#include <stdlib.h>
#include <stdio.h>
#define COUNT 8


struct Date{
    int day;
    int manth;
    int year;
};

struct Name{
	char *name;
	char surname;
	char patronymic;
};

struct Student{
    Name name;
    char gendr;
    char finish;
    char adress;
    char grand;
    Date date;
    int marks[5];
    int point;
};


//void writeToStruct(Student student);
int main(){
    char *path = "C:\\", *name;
    printf("Input name of file : ");
    scanf("%s",name);
    strcat(path, name);
    printf("\tFile is open\n\tInput List\n");
    //Student students[COUNT];
    for(int i = 0; i < COUNT; i++){
        /*scanf("%s%c%c%c%c%c%c%c%i%i%i", &students[i].name.name,
            &students[i].name.surname, &students[i].name.patronymic,
            &students[i].gendr, &students[i].finish, &students[i].adress,
            &students[i].grand, &students[i].date.day, &students[i].date.manth,
            &students[i].date.year);
        for(int k = 0; k<5;k++)
            scanf("%i",&students[i].marks[k]);
        scanf("%i", &students[i].point);*/
    }
    printf("Write in file\n");
    return 0;
}

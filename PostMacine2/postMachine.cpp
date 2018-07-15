#include <stdio.h>
#include <fstream>
#include <stdlib.h> 
//функция интерпритатор, которая принимает 1 строку в коде Машины Поста и интерпритирует ее в код для языка с++, записывает полученое в файл
void transform(std::ofstream &file, char *string){
    char line[] = "line";
    file << line << string[0] <<":\n\t\t";
    switch (string[1]){
        case '-':
            file << "i++;\n\t\t" << "goto " << line << string[3] << ";\n\t";
            break;
        case '?':
            file << "if(list[i] == 0)\n\t\t\tgoto " << line <<
                string[2] << ";\n\t\telse\n\t\t\tgoto " << line << string[4] << ";\n\t";
            break;
        case '<':
            file << "i--;\n\t\tgoto " << line << string[3] << ";\n\t";
            break;
        case 'V':
            file << "list[i] = 1;\n\t\tgoto " << line << string[2] << ";\n\t";
            break;
        case '!':
            file << "printf(\"Прграма закончена!\\n\");\n\t\tsystem(\"pause\");\n\t";
            break;
        default:
            break;
    }
}
//программа принимает 2 файла: файл с кодом машины поста и лист с 0 и 1
//программа интерпретирует 1 файл в с++ файл, и добавляет нужные команды что бы код работал
int main(int argc, char **args){
    printf("Введите имна файлов с кодом на языке машины Поста и лентой из 0 и 1\n");
    char firstFile[50];
    char secondFile[50];
    gets(firstFile);
    fflush(stdin);
    gets(secondFile);
    fflush(stdin);
    printf("Программа : %s\n",args[0]);
    std::ofstream fileWrite("post.cpp");
    fileWrite << "#include <stdio.h>\n#include <stdlib.h>\n#include <locale.h>\n\nint main(){\n\tsetlocale(LC_ALL,\"Russian\");\n\tprintf(\"Программа начата!\\n\");\n" <<
        "FILE *file = fopen(\"" << secondFile << "\",\"r\");\n\tint count = 1;\n\tint *list = (int*) malloc(sizeof(int)*(count));\n\twhile(fscanf(file,\"%d\",&list[count-1]) != EOF){\n\t\t" <<
        "int *tmp = list;\n\t\tlist = (int*) malloc(sizeof(int)*(++count));\n\t\tfor(int i = 0; i < count-1; i++)\n\t\t\tlist[i] = tmp[i];\n\t\tfree(tmp);\n\t}\n\tcount--;\n\tfclose(file);\n\tFILE *fileWrite = fopen(\"" <<
        secondFile <<"\", \"w\");\n\tint i = 0;\n\t";
    std::ifstream fileRead(firstFile);
    while(!fileRead.eof()){
        char string[10];
        fileRead >> string;
        transform(fileWrite, string);
    }
    fileRead.close();
    fileWrite << "for(int j = 0; j < count; j++)\n\tfprintf(fileWrite, \"%d\\n\", list[j]);\n\tfclose(fileWrite);\n\tfree(list);\n\treturn 0;\n}";
    fileWrite.close();
    printf("Программа закончена!");
    system("g++ -lm -o post post.cpp");
    return 0;
}
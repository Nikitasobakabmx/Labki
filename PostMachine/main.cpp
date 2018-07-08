#include <stdio.h>
#include <fstream>
/*
    converts every one comand on Post's machine code to c++
    nothing return, work like procedure
*/
void toCode(std::ofstream &file, char *string){
    char *line = "line";
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
            file << "printf(\"!programm complite!\\n\");\n\t\tsystem(\"pause\");\n\t";
            break;
        default:
            break;
    }
}
/*
    input in file default code
*/
void defaultCode(std::ofstream &file, char *name){
    file << "#include <stdio.h>\n#include <fstream>\n\nint main(){\n\tprintf(\"!programm run!\\n\");\n\t" <<
        "std::ifstream fileRead(\"" << name << "\");\n\tint *list = new int;\n\tint count = 0;\n\twhile(!fileRead.eof()){\n\t\t" <<
        "int *tmp = list;\n\t\tlist = new int[++count];\n\t\tfor(int i = 0; i < count-1; i++)\n\t\t\tlist[i] = tmp[i];\n\t\t" <<
        "fileRead >> list[count-1];\n\t\tdelete [] tmp;\n\t}\n\tfileRead.close();\n\t" <<
        "std::ofstream fileWrite(\"" << name <<"\");\n\tint i = 0;\n\t";
}

/*
    input default code in the end of file
*/
void endDefaultCode(std::ofstream &file){
    file << "for(int j = 0; j < count; j++)\n\tfileWrite << list[j] << \"\\n\";\n\tfileWrite.close();\n\tdelete [] list;\n\treturn 0;\n}";
}

/*
    for main need 2 files
    1 - with Post's machine code
    2 - with list of 1 or 0
*/
int main(int argv, char **args){
    if(argv != 3){
        printf("Erorr!\nYou mast input 2 files!");
        return 0;
    }
    printf("%s\n%s\n",args[1], args[2]);
    std::ofstream fileWrite("post.cpp");
    std::ifstream fileRead(args[1]);
    defaultCode(fileWrite,args[2]);
    while(!fileRead.eof()){
        char string[10];
        fileRead >> string;
        toCode(fileWrite, string);
    }
    fileRead.close();
    endDefaultCode(fileWrite);
    fileWrite.close();
    printf("Compile successful");
    system("cl post.cpp\npost.exe");
    return 0;
}
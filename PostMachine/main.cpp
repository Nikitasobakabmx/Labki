#include <stdio.h>
#include <fstream>
/*
    converts every one comand on Post's machine code to c++
    nothing return, work like procedure
*/
void toCode(std::ofstream &file, char *string, char *name){
    char *line = "line";
    file << line << string[0] <<":\n\t\t";
    switch (string[1]){
        case '-':
            file << "i++;\n\t\t" << "goto " << line << string[3] << ";\n\t";
            break;
        case '?':
            file << ":if(list[i] == 0)\n\t\t\tgoto " << line <<
                string[2] << ";\n\t\telse\n\t\t\tgoto " << line << string[4] << ";\n\t";
            break;
        case '<':
            file << "i--;\n\n\t\tgoto " << line << string[3] << ";\n\t";
            break;
        case 'V':
            file << "list[i] = 1;\n\t\tgoto " << line << string[2] << ";\n\t";
            break;
        case '!':
            file << "system(\"pause\");\n\t";
            break;
        default:
            break;
    }
}

void defaultCode(std::ofstream &file){
    file << "#include <stdio.h>\n#include <fstream>\n\nint main(){\n\tprintf(\"!programm run!\n\");\n\t" <<
        "std::ifstream fileRead(\"list.txt\");\n\tint *list = new int;\n\tint count = 0;\n\twhile(!fileRead.eof()){\n\t\t" <<
        "int *tmp = list;\n\t\tlist = new int[++count];\n\t\tfor(int i = 0; i < count-1; i++)\n\t\t\tlist[i] = tmp[i];\n\t\t" <<
        "fileRead >> list[count-1];\n\t\tprintf(\"%d\", list[count-1]);\n\t\tdelete [] tmp;\n\t}\n\tfileRead.close();\n\t" <<
        "std::ofstream fileWrite(\"list.txt\");\n\tint i = 0;\n\t";
}

int main(int argv, char **argv){
    if(argv != 3){
        printf("Erorr!\nYou mast input 2 files!");
        return 0;
    }

    return 0;
}
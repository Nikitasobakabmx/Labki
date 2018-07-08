#include <stdio.h>
#include <fstream>
void toCode(std::ofstream &file, char *string){
    file << "#include <stdio.h>\n#include <fstream>\nint main(){\n"
    std::string line = "line" + string[0];
    file << line;
    
    switch (string[1])
    {
        case '-':
            
            break;
        case '?':
            /* code */
            break;
        case '<':
            /* code */
            break;
        case 'V':
            /* code */
            break;
        case '!':
            /* code */
            break;
        default:
            break;
    }
}

int main(int argv, char **argv){
    if(argv != 3){
        printf("Erorr!\nYou mast input 2 files!");
        return 0;
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    char keyWord[26];
    int dif;
    printf("input key word and difference : ");
    scanf("%s%d", keyWord, &dif);
    char word[100];
    int len = strlen(keyWord);
    char alpha[26];

    /*                         **
    ** alphabet of enciphering **
    **                         */
    for(int i = 0; i < len; i++)
        alpha[i + dif] = keyWord[i];
    bool chek = false;
    int count = 0;
    for(int i = 'a'; i <= 'z'; i++){
        chek = false;
        for(int k = 0; k < len; k++)
            if(i == keyWord[k]){
                chek = true;
                count++;
            }
        if(!chek)
            if((i + len + dif - count) <= 'z')
                alpha[(i + len + dif) - 'a' - count] = i;
            else    
                alpha[i + len + dif - 'a' - 26 - count] = i;
    }
            
    /*--------------------------*/

    /*for(int i = 0; i <= 26; i++)
        printf("%c\t", alpha[i]);
    printf("\n");*/
    printf("Input Word : ");
    scanf("%s", word);
    char sum = strlen(word);

    /*                      **
    **    encription        **
    **                      */
    for(int i = 0; i < sum; i++)
        word[i] = alpha[word[i] - 'a'];
    /*--------------------------*/

    printf("Encription %s\n", word);

    /*                      **
    **     discription      **
    **                      */
    for(int i = 0; i < sum; i++)
        for(int k = 0;k < 26; k++)
            if(word[i] == alpha[k]){
                word[i] = 'a' + k;
                break;
            }
    /*--------------------------*/

    printf("Discription %s\n", word);
    return 0;
}
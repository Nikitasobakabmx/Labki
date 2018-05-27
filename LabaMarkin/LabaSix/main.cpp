#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

float odin(float m){
    float x , count = 0 ;
    for(int i =  1; i <=m; i++){
        x = 1.5 + 0.1 * i;
        count += (x * x - 3 * x + 2)/sqrt(2 *x*x -1);
    }
    return count;
}

float dva(float m){
    float count = 0, x;
    int i = 1 ;
    while(i <=m){
        x = 1.5 + 0.1 * i;
        count += ((x - 3) * x + 2)/sqrt(2*x*x - 1);
        i++;
    }
    return count;
}

float three(float m){
    float count = 0, x;
    int i = 1 ;
    do{
        x = 1.5 + 0.1 * i;
        count += (x * x - 3 * x + 2)/sqrt(2 *x*x -1);
        i++;
    }while(i <= m);
    return count;
}

int main(){
    float m, S;
    cout << "Input  m : ";
    cin >> m;
    S = odin(m);
    cout << "Summa odin : " << S << endl;
    S = dva(m);
    cout << "Summa dva : " << S << endl;
    S = three(m);
    cout << "Summa three : " << S << endl;
    getch();
    return 0;
}
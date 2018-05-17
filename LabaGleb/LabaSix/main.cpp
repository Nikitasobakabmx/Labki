#include <iostream>
#include <conio.h>

using namespace std;

float first(float a , float b, float m, float x){
    float count = 0;
    for(int n = 2 ;n <=m; n++){
        count += (x-a*n)/(x+b*n);
    }
    return b*count + a;
}

float second(float a , float b, float m, float x){
    float count = 0;
    int n = 2 ;
    while(n <=m){
        count += (x-a*n)/(x+b*n);
        n++;
    }
    return b*count + a;
}

float therd(float a , float b, float m, float x){
    float count = 0;
    int n = 2 ;
    do{
        count += (x-a*n)/(x+b*n);
        n++;
    }while(n <= m);
    return b*count + a;
}

int main(){
    float A, B, m, X, S;
    cout << "Input A, B, m, X : ";
    cin >> A >> B >> m >> X;
    S = first(A, B, m, X);
    cout << "Unnswer one : " << S << endl;
    S = second(A, B, m, X);
    cout << "Unswer two : " << S << endl;
    S = therd(A, B, m, X);
    cout << "Unswer three : " << S << endl;
    getch();
    return 0;
}
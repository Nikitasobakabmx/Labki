#include <iostream>
#include <conio.h>

using namespace std;

float one(float a , float b, float n, float m, float x){
    float count = 0;
    for(n ;n <=m; n++){
        count += (x + b/n)*(x + b/n);
    }
    return count + a;
}

float two(float a , float b, float n, float m, float x){
    float count = 0;
    while(n <=m){
        count += (x + b/n)*(x + b/n);
        n++;
    }
    return count + a;
}

float three(float a , float b, float n, float m, float x){
    float count = 0;
    do{
        count += (x + b/n)*(x + b/n);
        n++;
    }while(n <= m);
    return count + a;
}

int main(){
    float A, B, n, m, X;
    cout << "Input A, B, n, m, X : ";
    cin >> A >> B >> n >> m >> X;
    cout << "otwet one : " << one(A, B, n, m, X) << endl;
    cout << "otwet two : " << two(A, B, n, m, X) << endl;
    cout << "otwet three : " << three(A, B, n, m, X) << endl;
    getch();
    return 0;
}
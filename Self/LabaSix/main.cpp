#include <iostream>
#include <cmath>
 using namespace std;
 float forFunc(float m,float Y0,float Y1,float Y2){
     float s;
     for(int i = 0; i <= m; i++){
        switch (i){
            case 1:
                s = sqrt(Y0);
                break;
            case 2:
                s += sqrt(Y1);
                break;
            case 3:
                s += sqrt(Y2);
                break;
            default :
                float tmp = log10(abs(Y2*Y2 + Y0 + 1));
                s += sqrt(tmp);
                Y0 = Y1;
                Y1 = Y2;
                Y2 = tmp;            
        }
     }
 }
 float whileFunc(float m,float Y0,float Y1,float Y2){
     float s;
     int i = 0;
     while(i <= m){
        switch (i){
            case 1:
                s = sqrt(Y0);
                break;
            case 2:
                s += sqrt(Y1);
                break;
            case 3:
                s += sqrt(Y2);
                break;
            default :
                float tmp = log10(abs(Y2*Y2 + Y0 + 1));
                s += sqrt(tmp);
                Y0 = Y1;
                Y1 = Y2;
                Y2 = tmp;            
        }
        i++;
     }
 }
 float doWhileFunc(float m,float Y0,float Y1,float Y2){
     float s;
     int i = 0;
     do{
        switch (i){
            case 1:
                s = sqrt(Y0);
                break;
            case 2:
                s += sqrt(Y1);
                break;
            case 3:
                s += sqrt(Y2);
                break;
            default :
                float tmp = log10(abs(Y2*Y2 + Y0 + 1));
                s += sqrt(tmp);
                Y0 = Y1;
                Y1 = Y2;
                Y2 = tmp;            
        }
        i++;
     }while(i <= m+1);
 }
 int main(){
    cout << "Input m, Y0, Y1, Y2" << endl;
    float m, Y0, Y1, Y2;
    cin >> m >> Y0 >> Y1 >> Y2;
    cout << "First unswer : " << forFunc(m, Y0, Y1, Y2) << endl;
    cout << "Second unswer : " << whileFunc(m, Y0, Y1, Y2) << endl;
    cout << "Therd unswer : " << doWhileFunc(m, Y0, Y1, Y2) << endl;
    return 0;
 }
//laba 7 variant 4
#include <iostream>
#include <conio.h>

using namespace std;

void sort(float *a, int n, float b){
    float max = a[0];
    int count;
    for(int i = 0; i < n; i ++)
        if(a[i] >= max){
            max = a[i];
            count = i + 1;
        }
    
    for(int i = count ; i < n; i++)
        a[i] = b;
}

int main(){
    int n;
    cout << "VVedite razmer massiva : ";
    cin >> n;
    float a[n], b;
    cout << "Vvedite massiv \n";
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Vvedite b :";
    cin >> b;
    sort(a, n, b);
    cout << " Vivod otsortirovonnogo massiva :\n";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    getch();
    return 0;
}
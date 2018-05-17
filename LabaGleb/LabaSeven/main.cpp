//laba 7 variant 4
#include <iostream>
#include <conio.h>

using namespace std;

void zeroMax(float *a, int n){
    float max = a[0];
    int count;
    for(int i = 0; i < n; i++)
        if(a[i] >= max){
            max = a[i];
            count = i;
        }
    for(int i = 0; i < count; i++)
        if(a[i] < 0)
            a[i] = 0;
}

int main(){
    int n;
    cout << "Input size of array and array : ";
    cin >> n;
    float a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    zeroMax(a, n);
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    getch();
    return 0;
}
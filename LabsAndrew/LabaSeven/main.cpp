#include <iostream>
#include <conio.h>

using namespace std;

void makeArray(float *a,float *b, int n){
    for(int i = 0; i < n; i++){
        for(int k = 0; k <= i; k++)
            b[i] += a[k];
    }

}

int main(){
    int n;
    cout << "Input size of array and array : ";
    cin >> n;
    float a[n];
    float b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = 0;
    }
    makeArray(a, b, n);
    for(int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << endl;
    getch();
    return 0;
}
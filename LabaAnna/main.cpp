#include <iostream>
#include <conio.h>

using namespace std;

void perest ( float * a, int n){
    bool b = true;
    while(b){
        b = false;
        for(int i = 0; i < n-1; i++)
            if((a[i] < 0) && (a[i+1] >0)){
                float tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
                b = true;
            }
    }
}

int main(){
    int n;
    int i;
    cout << "Vvedite n ";
    cin >> n;
    float A[n];
    for(i = 0;i < n;i++)
        cin >> A[i];
    perest(A , n);
    for(i = 0; i < n; i++)
        cout << A[i] << " ";
    getch();
    return 0;
}
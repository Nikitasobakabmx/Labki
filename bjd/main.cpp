#include <iostream>
using namespace std;
int main(){
    float Uv[] = {0.31, 0.36, 0.4, 0.46, 0.68, 1.5, 3, 6, 10.6, 21.2, 42.4, 84.8};
    const float uV = 2;
    for(int i = 0; i < 12; i++)
        cout << Uv[i]/10 << "\n";
    cout << "-------------------------------------"<< endl;
    for(int i = 0; i < 12; i++)
        cout << (uV*10)/Uv[i] << "\n";
    return 0;
}
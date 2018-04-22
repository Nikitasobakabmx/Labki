#include <iostream>

using namespace std;

bool isSequence(float *array, int size){
    for(int i = 0; i < size-1; i++)
        if(array[i] < array[i+1])
            return false;
    return true;
}
void transformation(float *array, int size){
    for(int i = 0; i < size ; i++)
        if(array[i] < 0)
            array[i] = 1;
}
int main(){
    cout << "Input size of array" << endl;
    int size;
    cin >> size;
    float *array = new float[size];
    cout << "Input array" << endl;
    for(int i = 0; i < size ; i++)
        cin >> array[i];
    if(!isSequence(array, size))
        transformation(array, size);
    for(int i = 0; i < size ; i++)
        cout << array[i] << '\t';
    cout << endl;
    return 0;
}
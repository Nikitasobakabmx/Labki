#include <iostream>
#include <fstream>

using namespace std;

int fRead(ifstream &read, float *array[2]){
    int i = 1;
    array[0] = new float[i];
    float *tmp;
    while(read >> array[0][i-1]){
        i++;
        tmp = array[0];
        array[0] = new float[i];
        for(int k = 0; k < i-1; k++)
            array[0][k] = tmp[k];
    }
    return i;
}
void fWrite(ofstream &write, float *array[2], int count){
    for(int i = 0; i < count; i++)
        write << array[0][i] << "-" << array[1][i];
}
void aCount(float **arr, int count){
    for(int i = 0; i < count; i++){
        arr[1][i] = 0;
    }
    for(int i = 0; i < count; i++){
        for(int k = 0; k < count; k++){
            if(arr[0][i] == arr[0][k]){
                float *tmp = arr[0];
                arr[0] = new float[count-1];
                int l = 0;
                for(int j = 0; j < count; j++){
                    l++;
                    if(j == k)
                        j++;
                    arr[0][l] = tmp[j];
                }
                count--;
                arr[1][i]++;
            }                
        }
    }
}

int main(){
    ifstream read("List.txt");
    ofstream write("List2.txt");
    float *array[2];
    int count = fRead(read, array);
    cout << "Success" << endl;
    aCount(array, count);
    cout << "Success" << endl;
    fWrite(write,array,count);
    cout << "Success" << endl;
    delete [] array[0];
    delete [] array[1];
    system("pause");
    return 0;
}
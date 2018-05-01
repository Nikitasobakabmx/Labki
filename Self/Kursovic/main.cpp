#include <iostream>
#define LENGTH 5

float input(float *array){
    for(int i = 0; i < LENGTH; i++)
        std::cin >> array[i];
}
void output(float *matrix){
    int start = 0;
    for(int start = 0; start < 3; start++){
        for( int i = start; i < 12; i +=3)
            std::cout << matrix[i] << "\t";
        std::cout << std::endl;
    }
}
void coeff(float *x,float *y, float *matrix){
    //first element
    matrix[0] = 5;//summ if five unit
    //second element
    matrix[1] = 0;
    for(int i = 0; i < LENGTH;i++)
        matrix[1] += 2 * x[i];
    //forth element
    matrix[3] = matrix[2];
    //therd element
    matrix[2] = 0;
    for(int i = 0; i < LENGTH; i++)
        matrix[2] += 4 * x[i] * x[i] - 2;
    //seventh element
    matrix[6] = matrix[3];
    //fifth element
    matrix[4] = 0;
    for(int i = 0; i < LENGTH;i++ )
        matrix[4] += 4 * x[i] * x[1];
    //sixth element
    matrix[5] = 0;
    for(int i = 0; i < LENGTH; i++)
        matrix[5] += 2 * x[i] * (4 * x[i] * x[i] - 2);
    //eighth element 
    matrix[7] = matrix[5];
    //ninth element
    matrix[8] = 0;
    for(int i = 0; i < LENGTH; i++)
        matrix[8] += (4 * x[i] * x[i] - 2) * (4 * x[i] * x[i] - 2);
    //tenth element
    matrix[9] = 0;
    for(int i = 0; i < LENGTH; i++)
        matrix[9] += y[i];
    //eleventh element
    matrix[10] = 0;
    for(int i = 0; i < LENGTH; i++)
        matrix[10] += 2 * x[i] * y[i]; 
    //twelfth element
    matrix[11] = 0;
    for(int i = 0; i < LENGTH; i++)
        matrix[11] += (4 * x[i] * x[i] - 2) * y[i];
}
int main(){
    float arrayOfX[LENGTH], arrayOfY[LENGTH], matrix[3*4], X, Y; 
    std::cout << "input all x and all y\n";
    input(arrayOfX);
    input(arrayOfY);
    coeff(arrayOfX, arrayOfY, matrix);
    output(matrix);
    return 0;
}
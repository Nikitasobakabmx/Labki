#include <iostream>

#define LENGTH 5

float diff(float *fucFi, float *difference, float *y);
float fi(float *fucFi, float *x, float &C1, float &C2, float &C3);
float sq(float *difference, float *sqare);
float input(float *array);
void output(float *matrix);
float abs(float &x);
void zedelMethod(float *matrix, float accuracy, float &C1 ,float &C2 ,float &C3);
void coeff(float *x,float *y, float *matrix);

int main(){
    float C1 = 0, C2 = 0, C3 = 0;
    float arrayOfX[LENGTH], arrayOfY[LENGTH], matrix[3*4], X, Y, accuracy; 
    float funcFi[LENGTH], difference[LENGTH], sqare[LENGTH];
    std::cout << "input all x and all y\n";
    input(arrayOfX);
    input(arrayOfY);
    coeff(arrayOfX, arrayOfY, matrix);
    output(matrix);
    std::cout << "input accuracy of calculation : ";
    std::cin >> accuracy;
    std::cout << std::endl;
    zedelMethod(matrix , accuracy, C1, C2, C3);
    std::cout << C1 << "\t" << C2 << "\t" << C3 << std::endl;
    fi(funcFi, arrayOfX, C1, C2, C3);
    diff(funcFi, difference, arrayOfY);
    std::cout << "unswer is : " << sq(difference, sqare) << std::endl;
    return 0;
}

float diff(float *fucFi, float *difference, float *y){
    float result = 0;
    for(int i = 0; i  < LENGTH; i++){
        difference[i] = fucFi[i] - y[i];
        result += difference[i];
    }
    return result;
}

float fi(float *fucFi, float *x, float &C1, float &C2, float &C3){
    float result = 0;
    for(int i = 0; i < LENGTH; i++){
        fucFi[i] = C1 + 2 * C2 * x[i] + (4 * x[i] * x[i] - 2) * C3;
        result += fucFi[i];
    }
    return result;
}

float sq(float *difference, float *sqare){
    float result = 0;
    for(int i = 0; i < LENGTH; i++){
        sqare[i] = difference[i] * difference[i];
        result += sqare[i];
    }
    return result;
}

float input(float *array){
    for(int i = 0; i < LENGTH; i++)
        std::cin >> array[i];
}

void output(float *matrix){
    std::cout.precision(4);
    int start = 0;
    for(int start = 0; start < 3; start++){
        for( int i = start; i < 12; i +=3)
            std::cout << matrix[i] << "\t";
        std::cout << std::endl;
    }
}

float abs(float x){
    if(x < 0)
        x = -1 * x;
    return x;
}

void zedelMethod(float *matrix, float accuracy, float &C1 ,float &C2 ,float &C3){
    float tmp1, tmp2,tmp3;
    do{
    //for(int i = 0; i < 5;i++){
        tmp1 = C1; tmp2 = C2; tmp3 = C3;
        C1 = (matrix[9] - matrix[3] * C2 - matrix[6] * C3) / matrix[0];
        C2 = (matrix[10] - matrix[1] * C1 - matrix[7] * C3) / matrix[4];
        C3 = (matrix[11] - matrix[2] * C1 - matrix[5] * C2) / matrix[8];
    }while((abs(tmp1 - C1) >= accuracy) &&
             (abs(tmp2 - C2) >= accuracy) &&
             (abs(tmp3 - C3) >= accuracy));
}

void coeff(float *x,float *y, float *matrix){
    //first element
    matrix[0] = 5;//summ if five unit
    //second element
    matrix[1] = 0;
    for(int i = 0; i < LENGTH;i++)
        matrix[1] += 2 * x[i];
    //therd element
    matrix[2] = 0;
    for(int i = 0; i < LENGTH; i++)
        matrix[2] += 4 * x[i] * x[i] - 2;
    //forth element
    matrix[3] = matrix[1];
    //fifth element
    matrix[4] = 0;
    for(int i = 0; i < LENGTH;i++ )
        matrix[4] += 4 * x[i] * x[i];
    //sixth element
    matrix[5] = 0;
    for(int i = 0; i < LENGTH; i++)
        matrix[5] += 2 * x[i] * (4 * x[i] * x[i] - 2);
    //seventh element
    matrix[6] = matrix[2];
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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define LENGTH 5
#define HIGH 3
#define WIDTH 4
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    float diff(float *fucFi, float *difference, float *y);//yes
    float fi(float *fucFi, float *x, float *C);
    float sq(float *difference, float *sqare);
    void zedelMethod(float *matrix, float accuracy, float *C);//yes
    void coeff(float *x,float *y, float *matrix);//yes
    void split(QString string, float *array);//yes
    void stringMatrix(float *matrix);//yes
    void mainWork();//yes
    float abs(float x);//yes
    float transform(float &a);
    float fi(float x,int i);
    bool convergence(float *matrix);

private slots:
    void on_calcButton_clicked();

private:
    QString output;
    float unsver;
    float C[HIGH] = {0,0,0};
    float arrayOfX[LENGTH], arrayOfY[LENGTH], matrix[3*4], X, Y, accuracy;
    float funcFi[LENGTH], difference[LENGTH], sqare[LENGTH];
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

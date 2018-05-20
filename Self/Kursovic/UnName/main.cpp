#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    window.setWindowTitle("Least-squares method");
    window.show();

    return a.exec();
}

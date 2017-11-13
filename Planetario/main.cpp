#include "mainwindow.h"
#include <QtWidgets>
#include <QApplication>
#include <QTimer>

#include "starsystemmodel.h"
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow* w = new MainWindow();
    w->show();

    return a.exec();
}




#include "mainwindow.h"

#include <QTimer>

#include "starsystemmodel.h"

QGraphicsScene* scene;
QGraphicsView* view;
StarSystemModel* model;

void MainWindow::redrawScene()
{
    scene->clear();
    scene->setBackgroundBrush(QBrush(QColor(15, 4, 30)));
    model->refreshState();
    Star* star = model->star;
    scene->addEllipse(star->position.x(), star->position.y(), star->pixelRadius,
                      star->pixelRadius, QPen(star->color), QBrush(star->color));
    foreach (Planet* planet, model->planets) {
        scene->addEllipse(planet->position.x(), planet->position.y(), planet->pixelRadius,
                          planet->pixelRadius, QPen(planet->color), QBrush(planet->color));
    }
}

MainWindow::MainWindow() : QMainWindow()
{
    this->setGeometry(100, 100, 500, 500);

    scene = new QGraphicsScene();
    view = new QGraphicsView(scene, this);
    view->setGeometry(0, 0, 500, 500);

//    scene->addEllipse(100, 100, 100, 100, QPen(QColor(220, 40, 100)), QBrush(QColor(100, 40, 220)));

    model = new StarSystemModel();

    QTimer* timer = new QTimer();
    timer->setInterval(20);
    connect(timer, SIGNAL(timeout()), this, SLOT(redrawScene()));
    timer->start();
}

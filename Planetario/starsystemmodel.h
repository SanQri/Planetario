#ifndef STARSYSTEMMODEL_H
#define STARSYSTEMMODEL_H

#include "spaceobject.h"
#include "star.h"
#include "planet.h"

#include <QTime>
#include <QVector>
#include <QVector2D>

class StarSystemModel
{
public:
    StarSystemModel();
    void refreshState();
    QVector<Planet*> planets;
    Star* star;
private:
    QTime* time;
};

#endif // STARSYSTEMMODEL_H

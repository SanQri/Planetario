#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H

#include <QVector2D>
#include <QColor>

class SpaceObject
{
public:
    SpaceObject();
    QVector2D position;
    QVector2D velocity;
    QVector2D acceleration;
    float mass;
    float pixelRadius;
    QColor color;
};

#endif // SPACEOBJECT_H

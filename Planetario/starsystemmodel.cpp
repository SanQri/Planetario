#include "starsystemmodel.h"

StarSystemModel::StarSystemModel()
{
    time = new QTime();
    time->start();

    star = new Star();
    star->position = QVector2D(100, 100);
    star->color = QColor(250, 220, 50);
    star->mass = 200;
    star->pixelRadius = 40;

    Planet* planet1 = new Planet();
    planet1->position = QVector2D(200, 100);
    planet1->velocity = QVector2D(0, 1);
    planet1->color = QColor(50, 200, 250);
    planet1->pixelRadius = 25;

    Planet* planet2 = new Planet();
    planet2->position = QVector2D(300, 100);
    planet2->velocity = QVector2D(0, 0.7);
    planet2->color = QColor(50, 220, 120);
    planet2->pixelRadius = 18;

    planets << planet1;
    planets << planet2;
}

void StarSystemModel::refreshState()
{
    float dt = time->restart() * 0.45;

    foreach (Planet* planet, planets) {
        float distance = (planet->position - star->position).lengthSquared();
        float koef = 1;
        QVector2D toStar = (star->position - planet->position).normalized();
        planet->acceleration = (toStar * koef * star->mass / distance) -
                 (toStar * planet->velocity.lengthSquared() / sqrt(distance));
        planet->velocity += planet->acceleration * dt;
        planet->position += planet->velocity * dt;
    }

}

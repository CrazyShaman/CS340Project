#ifndef ASTEROID_H
#define ASTEROID_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtGui>

class asteroid : public QGraphicsItem
{
private:
    qreal startingX;
    qreal startingY;
    int asteroidIndex;
    bool asteroidDirection;
    qreal asteroidSpeed;
    qreal currentX;
    qreal currentY;
    void DoCollision();

public:
    asteroid(int x, int y, int index, bool direction);

protected:
    QRectF boundingRect()const;
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ASTEROID_H

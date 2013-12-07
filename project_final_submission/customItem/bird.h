#ifndef BIRD_H
#define BIRD_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtGui>

class bird : public QGraphicsItem
{
private:
    qreal startingX;
    qreal startingY;
    int birdIndex;
    bool birdDirection;
    qreal currentX;
    qreal currentY;
    qreal birdSpeed;
    void DoCollision();

public:
    bird(int x, int y, int index, bool direction);

protected:
    QRectF boundingRect()const;
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BIRD_H

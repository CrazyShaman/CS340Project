#ifndef PLANE_H
#define PLANE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtGui>

class plane : public QGraphicsItem
{
private:
    qreal startingX;
    qreal startingY;
    int planeIndex;
    bool planeDirection;
    qreal currentX;
    qreal currentY;
    qreal planeSpeed;
    void DoCollision();

public:
    plane(int x, int y, int index, bool direction);

protected:
    QRectF boundingRect()const;
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PLANE_H

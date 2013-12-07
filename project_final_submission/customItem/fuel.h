#ifndef FUEL_H
#define FUEL_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtGui>

class fuel : public QGraphicsItem
{
private:
    qreal startingX;
    qreal startingY;
    int fuelIndex;
    bool fuelDirection;
    qreal currentX;
    qreal currentY;
    void DoCollision();

public:
    fuel(int x, int y, int index, bool direction);
    void respawn();

protected:
    QRectF boundingRect()const;
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // FUEL_H

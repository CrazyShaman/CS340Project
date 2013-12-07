#ifndef MINERAL_H
#define MINERAL_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtGui>

class mineral : public QGraphicsItem
{
private:
    qreal startingX;
    qreal startingY;
    int mineralIndex;
    qreal currentX;
    qreal currentY;
    void DoCollision();

public:
    bool mineralAvailable;
    mineral(int x, int y, int index, bool direction);
    void respawn();

protected:
    QRectF boundingRect()const;
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // MINERAL_H

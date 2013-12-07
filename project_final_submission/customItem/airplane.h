#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtGui>;

class airplane : public QGraphicsItem
{
private:
    qreal startingX;
    qreal startingY;
    int airplaneIndex;
    bool airplaneDirection;
    qreal currentX;
    qreal currentY;
    void DoCollision();

public:
    airplane(int x, int y, int index, bool direction);

protected:
    QRectF boundingRect()const;
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // AIRPLANE_H

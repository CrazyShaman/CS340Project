#ifndef BLACKOUT_H
#define BLACKOUT_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtGui>

class blackout : public QGraphicsItem
{
private:
    qreal startingX;
    qreal startingY;
    int blackoutIndex;
    bool blackoutDirection;
    qreal blackoutSpeed;
    qreal currentX;
    qreal currentY;
    void DoCollision();

public:
    blackout(int x, int y, int index, bool direction);
    void respawn();

protected:
    QRectF boundingRect()const;
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BLACKOUT_H

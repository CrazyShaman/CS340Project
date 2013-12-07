#ifndef NEWITEM_H
#define NEWITEM_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtGui>

class newItem : public QGraphicsItem
{

public:
    newItem();
    bool dead;
    qreal lives;
    bool invulnerability;
    qreal itemFuel;
    qreal minerals;
    qreal day;
    bool petFlying;
    qreal petBonus;
    qreal currentX;
    qreal currentY;
    bool dark;


private:

    bool t1;
    bool t2;

    void DoCollision();

protected:
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
};

#endif // NEWITEM_H

#ifndef SHIP_H
#define SHIP_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtGui>



class ship: public QGraphicsItem
{
public:
    ship();

private:
    QString str_win;
    void DoCollision();

protected:
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // SHIP_H

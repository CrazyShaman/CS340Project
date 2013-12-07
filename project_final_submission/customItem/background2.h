#ifndef BACKGROUND2_H
#define BACKGROUND2_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtGui>



class background2: public QGraphicsItem
{
public:
    background2();

private:

protected:
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // BACKGROUND2_H

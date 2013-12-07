#ifndef SCRIPT_H
#define SCRIPT_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtGui>

class script : public QGraphicsItem
{
private:
    qreal startingX;
    qreal startingY;


public:
    script(int x, int y, int o);
    qreal order;
    qreal counter;

protected:
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
};

#endif // SCRIPT_H

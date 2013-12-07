#ifndef BACKGROUND3_H
#define BACKGROUND3_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtGui>



class background3: public QGraphicsItem
{
public:
    background3();

private:

protected:
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // BACKGROUND3_H

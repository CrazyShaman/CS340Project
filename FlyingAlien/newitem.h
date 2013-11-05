#ifndef NEWITEM_H
#define NEWITEM_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtGui>;

class newItem : public QGraphicsItem
{
public:
    newItem();

private:
    qreal currentX;
    qreal currentY;
    void DoCollison();

protected:
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
};

#endif // NEWITEM_H

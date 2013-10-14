#ifndef NEWITEM_H
#define NEWITEM_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtGui>;

class newItem : public QGraphicsItem
{
public:
    newItem();

protected:
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // NEWITEM_H

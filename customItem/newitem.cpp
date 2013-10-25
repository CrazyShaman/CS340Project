#include "newitem.h"

newItem::newItem() : QGraphicsItem()
{
    setFlag(QGraphicsItem::ItemIsFocusable);
}

QRectF newItem::boundingRect() const
{
    return QRectF(0,0,30,30);
}

void newItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    //painter->drawRoundedRect(0,0,30,30,5,5);
    painter->drawPixmap(0,0,35,35,QPixmap("/Users/Christofer/Brain Boosting/Fall 2013/CS 340/QT/CS340Project/customItem/alien.jpg"));
}

void newItem::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Right:
        {
            moveBy(10,0);
            break;
        }
    case Qt::Key_Left:
        {
            moveBy(-10,0);
            break;
        }
    case Qt::Key_Up:
        {
            moveBy(0,-10);
            break;
        }
    case Qt::Key_Down:
        {
            moveBy(0,10);
            break;
        }
    }

    update();

}

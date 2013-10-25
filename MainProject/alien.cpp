#include "alien.h"

alien::alien()
{
    setFlag(QGraphicsItem::ItemIsFocusable);
}

QRectF alien::boundingRect() const
{
    return QRectF(0,0,50,50);
}

QPainterPath alien::shape() const
{
    QPainterPath path;
    path.addRect(-10, -20, 20, 40);
    return path;
}

void alien::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    //painter->drawRoundedRect(0,0,30,30,5,5);
    painter->setOpacity(0.5);
    painter->drawPixmap(0,0,35,35,QPixmap("C:/Users/Junce/Desktop/alien.jpg"));
}

void alien::keyPressEvent(QKeyEvent *event)
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


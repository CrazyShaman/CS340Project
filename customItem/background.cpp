#include "background.h"

background::background()
{
}

QRectF background::boundingRect() const
{
    return QRectF(0,0,30,30);
}

void background::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,250,250,QPixmap("/Users/Christofer/Brain Boosting/Fall 2013/CS 340/QT/CS340Project/customItem/sky.jpg"));

}

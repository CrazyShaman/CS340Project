#include "plane.h"
#include "background.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
using namespace std;

plane::plane() : QGraphicsItem()
{
}

QRectF plane::boundingRect() const
{
    return QRectF(200,20,35,35);
}

void plane::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(200,20,35,35,QPixmap(":/Pictures/plane_img.jpg"));
}

void plane::advance(int phase)
{
    if(!phase) return;

    currentX += globalX - 0.1;
    currentY += globalY;
        //scene()->setSceneRect(currentX,currentY,100,100);
    setPos(currentX, currentY);

}

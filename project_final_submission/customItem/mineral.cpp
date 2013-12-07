#include "mineral.h"
#include "background.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
using namespace std;
/**
  \param x starting horizontal position
  \param y starting vertical position
  \param index numerical index
  \param available whether or not this mineral is unlocked

 */
/// Minerals are collided with which give currency
mineral::mineral(int x, int y, int index, bool available) : QGraphicsItem()
{
    startingX = x;
    startingY = y;
    currentX = startingX;
    currentY = startingY;
    mineralIndex = index;
    mineralAvailable = available;
    if (!mineralAvailable)
        this->hide();
}

QRectF mineral::boundingRect() const
{
    return QRectF(startingX,startingY,35,35);
}

void mineral::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(startingX,startingY,35,35,QPixmap(":/Pictures/mineral.png"));
    if (this->collidesWithItem(item)){
        DoCollision();
    }
}

void mineral::advance(int phase)
{
    if(!phase) return;

    currentX += globalX ;
    currentY += globalY;

    setPos(currentX, currentY);

}

void mineral::respawn(){
    if (mineralAvailable){
        setPos(-150+(qrand()%300),50-(qrand()%1400));
        this->show();
    }
}

void mineral::DoCollision(){
    item->minerals += 5;
    this->hide();

}

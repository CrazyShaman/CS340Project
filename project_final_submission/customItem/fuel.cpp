#include "fuel.h"
#include "background.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
using namespace std;
/**
  \param x starting horizontal position
  \param y starting vertical position
  \param index numerical index
  \param direction direction of travel

 */
/// Fuel objects are collided with and give the alien fuel
fuel::fuel(int x, int y, int index, bool direction) : QGraphicsItem()
{
    startingX = x;
    startingY = y;
    currentX = startingX;
    currentY = startingY;
    fuelIndex = index;
    fuelDirection = direction;
}

QRectF fuel::boundingRect() const
{
    return QRectF(startingX,startingY,35,35);
}

void fuel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(startingX,startingY,35,35,QPixmap(":/Pictures/fuel.png"));
    if (this->collidesWithItem(item)){
        DoCollision();
    }
}

void fuel::advance(int phase)
{
    if(!phase) return;

    currentX += globalX ;
    currentY += globalY;

    setPos(currentX, currentY);

}

void fuel::respawn(){
    setPos(-150+(qrand()%300),50-(qrand()%1200));
    this->show();
}

void fuel::DoCollision(){
    item->itemFuel += 25;
    this->hide();

}

#include "pet.h"
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
/// The pet briefly accelerates the background to give the alien speed
pet::pet(int x, int y, int index, bool direction) : QGraphicsItem()
{
    startingX = x;
    startingY = y;
    currentX = startingX;
    currentY = startingY;
    petIndex = index;
    petDirection = direction;
    petSpeed = 1;
}

QRectF pet::boundingRect() const
{
    return QRectF(startingX,startingY,35,35);
}

void pet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(startingX,startingY,35,35,QPixmap(":/Pictures/pet.png"));
    if (this->collidesWithItem(item)){
        DoCollision();
    }
}

void pet::advance(int phase)
{
    if(!phase) return;
    currentX += globalX;
    currentY += globalY + petSpeed;
    if ((sky->getY() - currentY < 300)){
        currentY -= 1100;
        currentX = 0;
        currentX -= qrand()%300;
        currentX += qrand()%300;
        petSpeed = 0.7 + ((qrand()%40) * 0.01);
    }
    setPos(currentX, currentY);
}

void pet::respawn(){
    setPos(-150+(qrand()%300),50-(qrand()%1400));
    this->show();
}

void pet::DoCollision(){
    petTimer->start(500 + item->petBonus);
    item->petFlying = true;
    item->invulnerability = true;
    this->hide();
}

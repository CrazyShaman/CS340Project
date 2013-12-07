#include "blackout.h"
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
/// The blackout displays a black image over everything, disrupting play
blackout::blackout(int x, int y, int index, bool direction) : QGraphicsItem()
{
    startingX = x;
    startingY = y;
    currentX = startingX;
    currentY = startingY;
    blackoutIndex = index;
    blackoutDirection = direction;
    blackoutSpeed = 1;
}

QRectF blackout::boundingRect() const
{
    return QRectF(startingX,startingY,35,35);
}

void blackout::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(startingX,startingY,35,35,QPixmap(":/Pictures/blackout.png"));
    if (this->collidesWithItem(item)){
        DoCollision();
    }
}

void blackout::advance(int phase)
{
    if(!phase) return;
    currentX += globalX;
    currentY += globalY + blackoutSpeed;
    if ((sky->getY() - currentY < 300)){
        currentY -= 1100;
        currentX = 0;
        currentX -= qrand()%300;
        currentX += qrand()%300;
        blackoutSpeed = 0.7 + ((qrand()%40) * 0.01);
    }
    setPos(currentX, currentY);

}

void blackout::respawn(){
    setPos(-150+(qrand()%300),50-(qrand()%1400));
    this->show();
}

void blackout::DoCollision(){
    if (!item->invulnerability){
        blackedout->blackoutStart();
        this->hide();
    }
}

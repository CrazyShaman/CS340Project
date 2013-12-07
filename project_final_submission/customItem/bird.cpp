#include "bird.h"
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
/// Birds fly across the screen and collide with the alien
bird::bird(int x, int y, int index, bool direction) : QGraphicsItem()
{
    startingX = x;
    startingY = y;
    currentX = startingX;
    currentY = startingY;
    birdIndex = index;
    birdDirection = direction;
    birdSpeed = 1;
}

QRectF bird::boundingRect() const
{
    return QRectF(startingX,startingY,35,35);
}

void bird::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (birdDirection)
        painter->drawPixmap(startingX,startingY,35,35,QPixmap(":/Pictures/bird_img.png"));
    else
        painter->drawPixmap(startingX,startingY,35,35,QPixmap(":/Pictures/bird_img_left.png"));
    if (this->collidesWithItem(item)){
        DoCollision();
    }
}

void bird::advance(int phase)
{
    if(!phase) return;
    if (!birdDirection)
        currentX += globalX - birdSpeed;
    else
        currentX += globalX + birdSpeed;
    currentY += globalY;
    if ((sky->getX() - currentX) > 600 || (sky->getX() - currentX) < -600){
        if(!birdDirection)
            currentX += 1195;
        else
            currentX -= 1195;
        birdSpeed = 0.7 + ((qrand()%60) * 0.01);
    }
    setPos(currentX, currentY);

}

void bird::DoCollision(){
    if (item->invulnerability == false){
        item->invulnerability = true;
        item->lives--;
        if(item->lives < 0){
            item->lives = 0;
            item->dead = true;
        }
        else {
            invulnBlinkTimer1->start(1);
            invulnerabilityTimer->start(1500);
        }
    }

}

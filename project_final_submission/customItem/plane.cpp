#include "plane.h"
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
/// Planes collide with the alien to inflict damage
plane::plane(int x, int y, int index, bool direction) : QGraphicsItem()
{
    startingX = x;
    startingY = y;
    currentX = startingX;
    currentY = startingY;
    setPos(currentX, currentY);
    setX(150);
    planeIndex = index;
    planeDirection = direction;
    planeSpeed = 1;
}

QRectF plane::boundingRect() const
{
    return QRectF(startingX,startingY,35,35);
}

void plane::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (planeDirection)
        painter->drawPixmap(startingX,startingY,35,35,QPixmap(":/Pictures/plane_img_right.png"));
    else
        painter->drawPixmap(startingX,startingY,35,35,QPixmap(":/Pictures/plane.png"));
    if (this->collidesWithItem(item)){
        DoCollision();
    }
}

void plane::advance(int phase)
{
    if(!phase) return;
    if (!planeDirection)
        currentX += globalX - planeSpeed;
    else
        currentX += globalX + planeSpeed;
    currentY += globalY;
    if ((sky->getX() - currentX) > 600 || (sky->getX() - currentX) < -600){
        if(!planeDirection){
            currentX += 1195;
        }
        else{
            currentX -= 1195;
        }
        planeSpeed = 0.7 + ((qrand()%60) * 0.01);
    }
    if (planeIndex == 1){
    }
    setPos(currentX, currentY);

}

void plane::DoCollision(){
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

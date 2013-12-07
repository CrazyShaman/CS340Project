#include "airplane.h"
#include "background.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
using namespace std;

airplane::airplane(int x, int y, int index, bool direction) : QGraphicsItem()
{
    startingX = x;
    startingY = y;
    currentX = startingX;
    currentY = startingY;
    airplaneIndex = index;
    airplaneDirection = direction;
    //if (direction){
    //    this->setTransform(QTransform::fromScale(-1, 1));
    //}
}

QRectF airplane::boundingRect() const
{
    return QRectF(startingX,startingY,35,35);
}

void airplane::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(startingX,startingY,35,35,QPixmap(":/Pictures/plane_img.png"));
    if (this->collidesWithItem(item)){
        DoCollision();
    }
}

void airplane::advance(int phase)
{
    if(!phase) return;
    if (!airplaneDirection)
        currentX += globalX - 1;
    else
        currentX += globalX + 1;
    currentY += globalY;
    if ((sky->getX() - currentX) > 800 || (sky->getX() - currentX) < -800){
        if(!airplaneDirection)
            currentX += 1350 - startingX;
        else
            currentX -= 1595;
    }
        //scene()->setSceneRect(currentX,currentY,100,100);
    setPos(currentX, currentY);

}

void airplane::DoCollision(){
    if(item->lives <= 0){
        item->dead = true;
    }
    else if (item->invulnerability == false && item->lives > 0){
        //cout << "COLLIDING!!!" << endl;
        item->invulnerability = true;
        //invulnerabilityTimer->startTimer(3000);
        invulnerabilityTimer->start(3000);
        item->lives--;
    }

}

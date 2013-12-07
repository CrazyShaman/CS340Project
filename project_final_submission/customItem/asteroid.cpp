#include "asteroid.h"
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
/// Asteroids fall at diagonal directions and collide with alien.
asteroid::asteroid(int x, int y, int index, bool direction) : QGraphicsItem()
{
    startingX = x;
    startingY = y;
    currentX = startingX;
    currentY = startingY;
    asteroidIndex = index;
    asteroidDirection = direction;
    asteroidSpeed = 5;
    qsrand( QDateTime::currentDateTime().toTime_t() );


}

QRectF asteroid::boundingRect() const
{
    return QRectF(startingX,startingY,35,35);
}

void asteroid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(startingX,startingY,35,35,QPixmap(":/Pictures/asteroid.png"));
    if (this->collidesWithItem(item)){
        DoCollision();
    }
}

void asteroid::advance(int phase)
{
    if(!phase) return;
    if (!asteroidDirection)
        currentX += globalX - asteroidSpeed;
    else
        currentX += globalX + asteroidSpeed;
    currentY += globalY + asteroidSpeed;
    if ((sky->getY() - currentY < 300)){
        if(qrand()%2){
            asteroidDirection = true;
        }
        else{
            asteroidDirection = false;
        }
        currentY -= 1100;
        currentX = 0;
        if (asteroidDirection)
            currentX -= qrand()%500;
        else
            currentX += qrand()%500;
        asteroidSpeed = 0.7 + ((qrand()%70) * 0.01);
    }
    setPos(currentX, currentY);

}

void asteroid::DoCollision(){
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

#include "gamelabel.h"
#include "background.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
using namespace std;
/**
  \param x starting horizontal position
  \param y starting vertical position
  \param index numerical index

 */
/// These images are displayed while playing the game
gameLabel::gameLabel(int x, int y, int index) : QGraphicsItem()
{
    startingX = x;
    startingY = y;
    gameLabelIndex = index;
    thrusterOpacity = 1;
}

QRectF gameLabel::boundingRect() const
{
    return QRectF(startingX,startingY,20,20);
}

void gameLabel::advance(int phase)
{
    if(!phase) return;
    if (item->dead){
        thrusterOpacity = 0;
    }
    else if (gameLabelIndex == 4){
        if (sky->keysPressed[2] == true  && sky->currentY > 0){
            thrusterOpacity = 0.5;
            if (invulnBlinkTimer2->remainingTime() > 0){
                thrusterOpacity = 0.2;
            }
        }
        else if (thrusterOpacity > 0){
            thrusterOpacity -= 0.01;
        }
    }
    if (gameLabelIndex == 4)
        setOpacity(thrusterOpacity);
}

void gameLabel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (gameLabelIndex == 1){
        painter->drawPixmap(startingX,startingY,20,20,QPixmap(":/Pictures/mineralsmall.png"));
    }
    else if (gameLabelIndex == 2){
        painter->drawPixmap(startingX,startingY,20,20,QPixmap(":/Pictures/fuelsmall.png"));
    }
    else if (gameLabelIndex == 3){
        painter->drawPixmap(startingX,startingY,20,20,QPixmap(":/Pictures/Aliensmall.png"));
    }
    else if (gameLabelIndex == 4){
        painter->drawPixmap(startingX,startingY,20,20,QPixmap(":/Pictures/brainThruster.png"));
    }
}


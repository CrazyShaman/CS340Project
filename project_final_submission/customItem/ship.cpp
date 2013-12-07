#include "ship.h"
#include <iostream>
#include "dialog.h"
#include "ui_dialog.h"
using namespace std;
/// Colliding with the ship is the win condition for the game
ship::ship()
{
}

QRectF ship::boundingRect() const
{
    return QRectF(-500,-3740,1000,1000);
}

void ship::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-500,-3740,1000,1000,QPixmap(":/Pictures/space.png"));
    painter->drawPixmap(0,-3057,409,317,QPixmap(":/Pictures/ship2.png"));
    if (this->collidesWithItem(item)){
        DoCollision();
    }
}

void ship::DoCollision(){
    gameWin1->show();
    gameWin2->show();
    item->hide();
    str_win.setNum(item->day,'g',10);
    str_win = "...and it only took " + str_win + " days!";
    gameWin2->setPlainText(str_win);
    for (int i = 0;i < 3;i++){
        sky->keysPressed[i] = false;
    }
    globalX = 0;
    globalY = 0;
    item->invulnerability = true;
    sky->currentY = 2920;


}

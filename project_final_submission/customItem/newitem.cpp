#include "newitem.h"
#include <iostream>
#include "dialog.h"
#include "ui_dialog.h"
using namespace std;
/// This class represents the aliens attributes and graphical image
newItem::newItem() : QGraphicsItem()
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    currentX = 0;
    currentY = 0;
    lives = 3000;
    dead = false;
    invulnerability = false;
    t1 = true;
    t2 = false;
    itemFuel = 100;
    setPos(currentX,currentY);
    minerals = 0;
    day = 0;
    petFlying  = false;
    petBonus = 0;
    dark = false;
}

QRectF newItem::boundingRect() const
{
    return QRectF(100,172,50,50);
}

void newItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    if (dark)
        painter->drawPixmap(100,172,50,50,QPixmap(":/Pictures/AlienNewDark.png"));
    else
        painter->drawPixmap(100,172,50,50,QPixmap(":/Pictures/AlienNew .png"));
}

void newItem::advance(int phase)
{
    if(!phase) return;
    //cout << sky->getY() << endl;

    if(invulnerability && !item->petFlying){
        if (invulnerabilityTimer->remainingTime() <= 0){
            invulnerability = false;
        }

        else if (invulnBlinkTimer1->remainingTime() <= 0 && t1 == true){
            cout << "first" << endl;
            t1 = false;
            t2 = true;
            this->setOpacity(0.3);
            invulnBlinkTimer2->start(300);
        }
        if (invulnBlinkTimer2->remainingTime() <= 0 && t2 == true){
            cout << "second" << endl;
            t2 = false;
            t1 = true;
            this->setOpacity(1);
            invulnBlinkTimer1->start(300);
        }
    }
    else if (invulnBlinkTimer2->remainingTime() <= 0){
        this->setOpacity(1);
    }

}

void newItem::DoCollision(){

}

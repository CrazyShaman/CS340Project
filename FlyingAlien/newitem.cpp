#include "newitem.h"
#include <iostream>
#include "dialog.h"
#include "ui_dialog.h"
using namespace std;

newItem::newItem() : QGraphicsItem()
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    currentX = 0;
    currentY = 0;
}

QRectF newItem::boundingRect() const
{
    return QRectF(100,160,35,35);
}

void newItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    //painter->drawRoundedRect(0,0,30,30,5,5);
    painter->drawPixmap(100,160,35,35,QPixmap(":/Pictures/alien.jpg"));

    if(!scene()->collidingItems(this).isEmpty()){
        DoCollison();//set new position
    }
}

void newItem::advance(int phase)
{
    //cout << "Output sentence3" << endl;
    if(!phase) return;
    //if (currentX < 300){
      //  scene()->setSceneRect(currentX,currentY,100,100);
   // }
    //qApp->processEvents();
    this->setX(currentX);
    this->setY(currentY);
    //currentX += 0.1;
    //currentY += 0.1;
}

void newItem::DoCollison(){
    //cout << "COLLIDING!!!" << endl;
}

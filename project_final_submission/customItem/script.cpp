#include "script.h"
#include "background.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
using namespace std;
/**
  \param x starting horizontal position
  \param y starting vertical position
  \param o order of presentation (1 or 2)

 */
/// This class represents the text before the game starts
script::script(int x, int y, int o) : QGraphicsItem()
{
    startingX = x;
    startingY = y;
    order = o;
    counter = 0;
    setFlag(QGraphicsItem::ItemIsFocusable);
}

QRectF script::boundingRect() const
{
    return QRectF(startingX,startingY,375,265);
}

void script::advance(int phase)
{
    if(!phase) return;
    if (this->hasFocus()){
        cout << order << endl;
        counter++;
        if (order == 1){
            hide();
        }
        if (order == 2 && counter == 1){
            scriptTimer->start(200);
        }
        this->clearFocus();
    }
}

void script::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    if (order == 1)
        painter->drawPixmap(startingX,startingY,375,265,QPixmap(":/Pictures/story.png"));
    else if (order == 2){
        painter->drawPixmap(startingX,startingY,375,265,QPixmap(":/Pictures/DaveyLine.png"));
    }
}

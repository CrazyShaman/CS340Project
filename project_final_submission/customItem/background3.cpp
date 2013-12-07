#include "background3.h"
#include <iostream>
#include "dialog.h"
#include "ui_dialog.h"
using namespace std;
/// This represents outer space within the game
background3::background3()
{
}

QRectF background3::boundingRect() const
{
    return QRectF(-500,-2740,1000,1000);
}

void background3::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-500,-2740,1000,1000,QPixmap(":/Pictures/space.png"));
}




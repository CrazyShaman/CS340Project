#include "background2.h"
#include <iostream>
#include "dialog.h"
#include "ui_dialog.h"
using namespace std;
/// This is an additional layer of sky above the first
background2::background2()
{
}

QRectF background2::boundingRect() const
{
    return QRectF(-500,-1740,1000,1000);
}

void background2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-500,-1740,1000,1000,QPixmap(":/Pictures/sky3.png"));
}


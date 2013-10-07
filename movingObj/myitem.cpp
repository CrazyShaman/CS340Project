#include "myitem.h"

myItem::myItem()
{
    speed = 5;

    angle = (qrand()%360);
    setRotation(angle);

    int startx = 0;
    int starty = 0;

    if((qrand()%1)){
        startx = (qrand()%200);
        starty = (qrand()%200);
    }
    else{
        startx = (qrand()%-100);
        starty = (qrand()%-100);
    }
    setPos(mapToParent(startx,starty));
}

QRectF myItem::boundingRect() const
{
    return QRect(0,0,20,20);
}

void myItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();

    QBrush brush(Qt::gray);

    if(scene()->collidingItems(this).isEmpty()){
        brush.setColor(Qt::green);
    }
    else{
        brush.setColor(Qt::red);

        DoCollison();//set new position
    }

    painter->fillRect(rec,brush);
    painter->drawRect(rec);
}

void myItem::advance(int phase)
{
    if(!phase) return;

    QPointF location = this->pos();
    setPos(mapToParent(0,-(speed)));//maps current x,y coordinates to the scene x,y coordinates
}

void myItem::DoCollison()
{
    if((qrand()%1)){
        setRotation(rotation()+(180 + (qrand()%10)));
    }
    else{
        setRotation(rotation()+(180 + (qrand()%-10)));
    }

    QPointF newPoint = mapToParent(-(boundingRect().width()),-(boundingRect().width()+2));

    if(!scene()->sceneRect().contains(newPoint)){
        newPoint = mapFromParent(0,0);
    }
    else{
        setPos(newPoint);
    }
}

#include "background.h"
#include <iostream>
#include "dialog.h"
#include "ui_dialog.h"
using namespace std;

background::background()
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    currentX = 0;
    currentY = 0;
    for (int i = 0;i < 3;i++){
        keysPressed[i] = false;
    }
}

QRectF background::boundingRect() const
{
    return QRectF(-500,-800,1000,1000);
}

void background::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-500,-800,1000,1000,QPixmap(":/Pictures/sky.jpg"));

}

void background::advance(int phase)
{
    if(!phase) return;

    if (currentY < 0){
        globalY = 0;
        globalX = 0;
        currentY = 0;
    }
    if (currentY == 0){
        globalY = 0;
    }
    else{
        globalY -= 0.00025;
    }
    if (keysPressed[0] == true){
        globalX -= 0.00025;
    }
    if (keysPressed[1] == true){
        globalX += 0.00025;
    }
    if (keysPressed[2] == true){
        if (currentY == 0){
            currentY += 0.3;
        }
        globalY += 0.00035;
    }
    currentX += globalX;
    currentY += globalY;
        //scene()->setSceneRect(currentX,currentY,100,100);
    setPos(currentX, currentY);
   // }
    //qApp->processEvents();
    //this->setX(currentX);
   // this->setY(currentY);

     //   moveBy(currentX, currentY);
        //currentX += 0.1;
        //currentY += 0.1;
}

void background::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Right:
        {
            //moveBy(10,0);
            //xAccelerate -= 0.01;
            keysPressed[0] = true;
            cout << globalY << endl;
            //cout << "rightTrue" << endl;
            /*
            if (keysPressed[1] == true){
                xAccelerate += 0.01;
            }
            if (keysPressed[2] == true){
                if (currentY == 0){
                    currentY += 0.3;
                }
                yAccelerate += 0.01;
            }
            */
            break;
        }
    case Qt::Key_Left:
        {
           // moveBy(-10,0);
            //xAccelerate += 0.01;
            keysPressed[1] = true;
            /*
            if (keysPressed[0] == true){
                xAccelerate -= 0.01;
            }
            if (keysPressed[2] == true){
                if (currentY == 0){
                    currentY += 0.3;
                }
                yAccelerate += 0.01;
            }
            */
            break;
        }
    case Qt::Key_Space:
        {
            //cout << "spaceTrue" << endl;
            //if (currentY == 0){
            //    currentY += 0.3;
            //}
            //yAccelerate += 0.01;
            keysPressed[2] = true;
            /*
            if (keysPressed[0] == true){
                xAccelerate -= 0.01;
            }
            if (keysPressed[1] == true){
                xAccelerate += 0.01;
            }
            */
            break;
        }
    }

    update();

}

void background::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Right:
        {
            keysPressed[0] = false;
            //cout << "rightFalse" << endl;
            break;
        }
    case Qt::Key_Left:
        {
            keysPressed[1] = false;
            break;
        }
    case Qt::Key_Space:
        {
            cout << "spaceFalse" << endl;
            keysPressed[2] = false;
            break;
        }
    }
    update();
}


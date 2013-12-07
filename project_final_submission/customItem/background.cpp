#include "background.h"
#include <iostream>
#include "dialog.h"
#include "ui_dialog.h"
#include <QtGlobal>
using namespace std;
/**
  \param x this is a sweet parameter
  \param y waoh coolio

 */
/// This class governs all physics control
/// The "background" moves depending on the globalX and globalY variables
/// This simulates movement of the alien
/// Updates of game text are used in this class
/// Checks for death and other attributes are given
background::background()
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    currentX = 0;
    currentY = 0;
    temp_fuel = 0;
    handlingBonus = 0;
    strengthBonus = 0;
    deadCheck = false;
    deadCheck2 = false;
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


    painter->drawPixmap(-500,-740,1000,1000,QPixmap(":/Pictures/sky2.png"));

}

void background::advance(int phase)
{
    if(!phase) return;
    str_mins.setNum(item->minerals,'g',10);
    gameMineralsText->setPlainText(str_mins);
    if (currentY >= 1750){
        gameMineralsText->setDefaultTextColor(Qt::white);
    }
    else{
        gameMineralsText->setDefaultTextColor(Qt::black);
    }

    temp_fuel = qRound(item->itemFuel);
    str_fuel.setNum(temp_fuel,'g',10);
    gameFuelText->setPlainText(str_fuel);
    if (currentY >= 1750){
        gameFuelText->setDefaultTextColor(Qt::white);
    }
    else{
        gameFuelText->setDefaultTextColor(Qt::black);
    }

    str_lives.setNum(item->lives,'g',10);
    str_lives = "x" + str_lives;
    gameLivesText->setPlainText(str_lives);
    if (currentY >= 1750){
        gameLivesText->setDefaultTextColor(Qt::white);
    }
    else{
        gameLivesText->setDefaultTextColor(Qt::black);
    }


    if (item->dead && currentY <= 0 && deadCheck2 == false){
        deathTimer->start(500);
        deadCheck2 = true;
        return;
    }
    if (item->petFlying){
        globalX = 0;
        globalY = 4;
        currentX += globalX;
        currentY += globalY;
        setPos(currentX, currentY);
        sky2->setPos(currentX, currentY);
        space->setPos(currentX, currentY);
        space_ship->setPos(currentX, currentY);
        return;
    }
    if (dayTimer->isActive()){
        for (int i = 0;i < 3;i++){
            sky->keysPressed[i] = false;
        }
    }
    if (item->itemFuel <= 0){
        item->itemFuel = 0;
        item->lives = 0;
        item->dead = true;
    }
    if (item->dead && !deadCheck){
        deadCheck = true;
        DoDeath();
    }
    if (globalY > 2){
        globalY = 2;
    }
    if (globalX > 1){
        globalX = 1;
    }
    if (globalX < -1){
        globalX = -1;
    }
    if (currentX < -190){
        globalX = 0;
        currentX += 0.1;
    }
    if (currentX > 440){
        globalX = 0;
        currentX -= 0.1;
    }
    if (currentY < 0){
        globalY = 0;
        globalX = 0;
        currentY = 0;
    }
    if (currentY == 0){
        globalY = 0;
    }
    else{
        globalY -= 0.01;
    }
    if (keysPressed[0] == true && !item->dead){
        globalX -= 0.01 + handlingBonus;
    }
    if (keysPressed[1] == true && !item->dead){
        globalX += 0.01 + handlingBonus;
    }
    if (keysPressed[2] == true && !item->dead){
        if (currentY == 0){
            currentY += 0.3;
        }
        globalY += 0.014 + strengthBonus;
        item->itemFuel -= 0.1;
    }
    currentX += globalX;
    currentY += globalY;
    setPos(currentX, currentY);
    sky2->setPos(currentX, currentY);
    space->setPos(currentX, currentY);
    space_ship->setPos(currentX, currentY);
}

void background::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Right:
        {
            keysPressed[0] = true;
            break;
        }
    case Qt::Key_Left:
        {
            keysPressed[1] = true;
            break;
        }
    case Qt::Key_Space:
        {
            keysPressed[2] = true;
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
            break;
        }
    case Qt::Key_Left:
        {
            keysPressed[1] = false;
            break;
        }
    case Qt::Key_Space:
        {
            keysPressed[2] = false;
            break;
        }
    }
    update();
}


void background::DoDeath(){
    globalX = 0;
    globalY = 1;
}

int background::getX(){
    return currentX;
}

int background::getY(){
    return currentY;
}

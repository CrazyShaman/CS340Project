#include "upgrade.h"
#include "background.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
/**
  \param index numerical index

 */
/// These objects are clickable and represent the vairious possible upgrades you can purchase
upgrade::upgrade(int index) : QGraphicsItem()
{
    minCountInit = true;
    upgrade_level = 0;
    img_index = index;
    setFlag(QGraphicsItem::ItemIsFocusable);
}

QRectF upgrade::boundingRect() const
{
    if (img_index == 1)
        return QRectF(26,80,40,40);
    else if  (img_index == 2)
        return QRectF(106,80,40,40);
    else if  (img_index == 3)
        return QRectF(186,80,40,40);
    else if  (img_index == 4)
        return QRectF(26,175,40,40);
    else if  (img_index == 5)
        return QRectF(106,175,40,40);
    else if  (img_index == 6)
        return QRectF(186,175,40,40);
    else if  (img_index == 7)
        return QRectF(0,0,500,500);
    else if  (img_index == 0)
        return QRectF(230,10,68,41);
}

void upgrade::advance(int phase)
{
    if(!phase) return;

    if (this->hasFocus()){
        if (img_index == 0){
            shopTimer->start(200);
        }
        else if (upgrade_level < 5){
            if (img_index == 1 && item->minerals >= 20){
                item->minerals -= 20;
                upgrade_level++;
                str.setNum(item->minerals, 'g', 10);
                str = "Minerals: " + str;
                if (upgrade_level == 1)
                    brainFuelText3->setPlainText("1/5");
                if (upgrade_level == 2)
                    brainFuelText3->setPlainText("2/5");
                if (upgrade_level == 3)
                    brainFuelText3->setPlainText("3/5");
                if (upgrade_level == 4)
                    brainFuelText3->setPlainText("4/5");
                if (upgrade_level == 5)
                    brainFuelText3->setPlainText("5/5");
                shopMinerals->setPlainText(str);
            }
            else if (img_index == 2 && item->minerals >= 20){
                item->minerals -= 20;
                upgrade_level++;
                str.setNum(item->minerals, 'g', 10);
                str = "Minerals: " + str;
                if (upgrade_level == 1)
                    resilienceText3->setPlainText("1/5");
                if (upgrade_level == 2)
                    resilienceText3->setPlainText("2/5");
                if (upgrade_level == 3)
                    resilienceText3->setPlainText("3/5");
                if (upgrade_level == 4)
                    resilienceText3->setPlainText("4/5");
                if (upgrade_level == 5)
                    resilienceText3->setPlainText("5/5");
                shopMinerals->setPlainText(str);
            }
            else if (img_index == 3 && item->minerals >= 10){
                item->minerals -= 10;
                upgrade_level++;
                str.setNum(item->minerals, 'g', 10);
                str = "Minerals: " + str;
                if (upgrade_level == 1)
                    controlText3->setPlainText("1/5");
                if (upgrade_level == 2)
                    controlText3->setPlainText("2/5");
                if (upgrade_level == 3)
                    controlText3->setPlainText("3/5");
                if (upgrade_level == 4)
                    controlText3->setPlainText("4/5");
                if (upgrade_level == 5)
                    controlText3->setPlainText("5/5");
                shopMinerals->setPlainText(str);
            }
            else if (img_index == 4 && item->minerals >= 20){
                item->minerals -= 20;
                upgrade_level++;
                str.setNum(item->minerals, 'g', 10);
                str = "Minerals: " + str;
                if (upgrade_level == 1)
                    brainPowerText3->setPlainText("1/5");
                if (upgrade_level == 2)
                    brainPowerText3->setPlainText("2/5");
                if (upgrade_level == 3)
                    brainPowerText3->setPlainText("3/5");
                if (upgrade_level == 4)
                    brainPowerText3->setPlainText("4/5");
                if (upgrade_level == 5)
                    brainPowerText3->setPlainText("5/5");
                shopMinerals->setPlainText(str);
            }
            else if (img_index == 5 && item->minerals >= 20){
                item->minerals -= 20;
                upgrade_level++;
                str.setNum(item->minerals, 'g', 10);
                str = "Minerals: " + str;
                if (upgrade_level == 1)
                    petStrengthText3->setPlainText("1/5");
                if (upgrade_level == 2)
                    petStrengthText3->setPlainText("2/5");
                if (upgrade_level == 3)
                    petStrengthText3->setPlainText("3/5");
                if (upgrade_level == 4)
                    petStrengthText3->setPlainText("4/5");
                if (upgrade_level == 5)
                    petStrengthText3->setPlainText("5/5");
                shopMinerals->setPlainText(str);
            }
            else if (img_index == 6 && item->minerals >= 10){
                item->minerals -= 10;
                upgrade_level++;
                str.setNum(item->minerals, 'g', 10);
                str = "Minerals: " + str;
                if (upgrade_level == 1)
                    mineralRateText3->setPlainText("1/5");
                if (upgrade_level == 2)
                    mineralRateText3->setPlainText("2/5");
                if (upgrade_level == 3)
                    mineralRateText3->setPlainText("3/5");
                if (upgrade_level == 4)
                    mineralRateText3->setPlainText("4/5");
                if (upgrade_level == 5)
                    mineralRateText3->setPlainText("5/5");
                shopMinerals->setPlainText(str);
            }
        }
        this->clearFocus();
    }

    if (minCountInit){
        str.setNum(item->minerals, 'g', 10);
        shopMinerals->setPlainText(str);
        !minCountInit;
    }

}

void upgrade::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (img_index == 1)
        painter->drawPixmap(26,80,40,40,QPixmap(":/Pictures/BrainFuel.png"));
    else if (img_index == 2)
        painter->drawPixmap(106,80,40,40,QPixmap(":/Pictures/Resilience.jpg"));
    else if (img_index == 3)
        painter->drawPixmap(186,80,40,40,QPixmap(":/Pictures/Wheel.png"));
    else if (img_index == 4)
        painter->drawPixmap(26,175,40,40,QPixmap(":/Pictures/brainPower.png"));
    else if (img_index == 5)
        painter->drawPixmap(106,175,40,40,QPixmap(":/Pictures/pet.png"));
    else if (img_index == 6)
        painter->drawPixmap(186,175,40,40,QPixmap(":/Pictures/mineral.png"));
    else if (img_index == 7)
        painter->drawPixmap(0,0,500,500,QPixmap(":/Pictures/blackedout.png"));
    else if (img_index == 0)
        painter->drawPixmap(230,10,68,41,QPixmap(":/Pictures/shopDone.png"));
}

void upgrade::blackoutStart(){
    this->show();
    blackoutTimer->start(1000);
}

upgrade::~upgrade() {}

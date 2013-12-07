#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "upgrade.h"
#include "newitem.h"
#include "background.h"
#include "background2.h"
#include "background3.h"
#include "ship.h"
#include "plane.h"
#include "bird.h"
#include "blackout.h"
#include "pet.h"
#include "asteroid.h"
#include "fuel.h"
#include "mineral.h"
#include "gamelabel.h"
#include "script.h"
#include <QPushButton>
#include <QLabel>
#include <QSound>

namespace Ui {
class Dialog;
}

//extern Ui::Dialog *ui;
//extern QGraphicsScene * scene2;
extern int days;
extern qreal globalX;
extern qreal globalY;
extern newItem *item;
extern background *sky;
extern background2 *sky2;
extern background3 *space;
extern ship *space_ship;
extern QTimer *deathTimer;
extern QTimer *shopTimer;
extern QTimer *dayTimer;
extern QTimer *invulnerabilityTimer;
extern QTimer *invulnBlinkTimer1;
extern QTimer *invulnBlinkTimer2;
extern QTimer *blackoutTimer;
extern QTimer *petTimer;
extern QTimer *darkTimer;
extern QTimer *scriptTimer;
extern QGraphicsTextItem *gameWin1;
extern QGraphicsTextItem *gameWin2;
extern QGraphicsTextItem *gameMineralsText;
extern QGraphicsTextItem *gameFuelText;
extern QGraphicsTextItem *gameLivesText;
extern QGraphicsTextItem *shopMinerals;
extern QGraphicsTextItem *brainFuelText3;
extern QGraphicsTextItem *resilienceText3;
extern QGraphicsTextItem *controlText3;
extern QGraphicsTextItem *brainPowerText3;
extern QGraphicsTextItem *petStrengthText3;
extern QGraphicsTextItem *mineralRateText3;
extern upgrade *blackedout;
extern gameLabel *thruster;




class Dialog : public QDialog
{
    Q_OBJECT

public:
    Ui::Dialog *ui;
    QGraphicsScene * scene;
    QGraphicsScene * sceneShop;
    QGraphicsScene * sceneMenu;
    QGraphicsScene * sceneInstruction;
    QGraphicsScene * sceneScript;
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    //newItem *item;



private:
    //Ui::Dialog *ui;
    //background *sky;
    QString str;
    QSound *sound;
    QSound *sound2;
    plane *plane_1;
    plane *plane_2;
    plane *plane_3;
    plane *plane_4;
    plane *plane_5;
    plane *plane_6;
    plane *plane_7;
    plane *plane_8;
    plane *plane_9;
    plane *plane_10;
    plane *plane_11;
    plane *plane_12;
    plane *plane_13;
    plane *plane_14;
    plane *plane_15;
    plane *plane_16;
    plane *plane_17;
    plane *plane_18;
    plane *plane_19;
    plane *plane_20;
    plane *plane_21;
    plane *plane_22;
    plane *plane_23;
    plane *plane_24;
    bird *bird_1;
    bird *bird_2;
    bird *bird_3;
    bird *bird_4;
    bird *bird_5;
    bird *bird_6;
    bird *bird_7;
    bird *bird_8;
    bird *bird_9;
    bird *bird_10;
    bird *bird_11;
    bird *bird_12;
    bird *bird_13;
    bird *bird_14;
    bird *bird_15;
    bird *bird_16;
    bird *bird_17;
    bird *bird_18;
    bird *bird_19;
    bird *bird_20;
    bird *bird_21;
    bird *bird_22;
    bird *bird_23;
    bird *bird_24;
    mineral *mineral_1;
    mineral *mineral_2;
    mineral *mineral_3;
    mineral *mineral_4;
    mineral *mineral_5;
    mineral *mineral_6;
    mineral *mineral_7;
    mineral *mineral_8;
    mineral *mineral_9;
    mineral *mineral_10;
    mineral *mineral_11;
    mineral *mineral_12;
    mineral *mineral_13;
    mineral *mineral_14;
    mineral *mineral_15;
    mineral *mineral_16;
    mineral *mineral_17;
    mineral *mineral_18;
    mineral *mineral_19;
    mineral *mineral_20;
    mineral *mineral_21;
    mineral *mineral_22;
    mineral *mineral_23;
    mineral *mineral_24;
    mineral *mineral_25;
    mineral *mineral_26;
    mineral *mineral_27;
    mineral *mineral_28;
    mineral *mineral_29;
    mineral *mineral_30;
    mineral *mineral_31;
    mineral *mineral_32;
    fuel *fuel_1;
    fuel *fuel_2;
    fuel *fuel_3;
    fuel *fuel_4;
    blackout *blackout_1;
    blackout *blackout_2;
    asteroid *asteroid_1;
    asteroid *asteroid_2;
    asteroid *asteroid_3;
    asteroid *asteroid_4;
    asteroid *asteroid_5;
    asteroid *asteroid_6;
    asteroid *asteroid_7;
    asteroid *asteroid_8;
    asteroid *asteroid_9;
    asteroid *asteroid_10;
    asteroid *asteroid_11;
    asteroid *asteroid_12;
    asteroid *asteroid_13;
    asteroid *asteroid_14;
    asteroid *asteroid_15;
    asteroid *asteroid_16;
    pet *pet_1;
    pet *pet_2;
    QTimer *timer;
    int height;
    int width;
    int row1;
    int row2;
    int spacing;
    int start;
    QRect rec1;
    QRect rec2;
    QRect rec3;
    QRect rec4;
    QRect rec5;
    QRect rec6;
    //upgrade *blackedout;
    QGraphicsTextItem *menuTitle1;
    QGraphicsTextItem *menuTitle2;

    QPushButton *playButton;
    QPushButton *playButton2;
    QPushButton *exitButton;
    QPushButton *exitButton2;
    QPushButton *instructionsButton;
    QPushButton *menuButton;
    script *scriptPix1;
    script *scriptPix2;
    gameLabel *gameMineralsPix;
    gameLabel *gameFuelPix;
    gameLabel *gameLivesPix;
    gameLabel *shopMineralsPix;
    QGraphicsTextItem *dayText;
    QGraphicsTextItem *shopTitle;
    //QGraphicsTextItem *shopMinerals;
    upgrade *shopDone;
    upgrade *brainFuelPix;
    QGraphicsTextItem *brainFuelText1;
    QGraphicsTextItem *brainFuelText2;
    //QGraphicsTextItem *brainFuelText3;
    upgrade *resiliencePix;
    QGraphicsTextItem *resilienceText1;
    QGraphicsTextItem *resilienceText2;
    //QGraphicsTextItem *resilienceText3;
    upgrade *controlPix;
    QGraphicsTextItem *controlText1;
    QGraphicsTextItem *controlText2;
    //QGraphicsTextItem *controlText3;
    upgrade *brainPowerPix;
    QGraphicsTextItem *brainPowerText1;
    QGraphicsTextItem *brainPowerText2;
    //QGraphicsTextItem *controlText3;
    upgrade *petStrengthPix;
    QGraphicsTextItem *petStrengthText1;
    QGraphicsTextItem *petStrengthText2;
    //QGraphicsTextItem *controlText3;
    upgrade *mineralRatePix;
    QGraphicsTextItem *mineralRateText1;
    QGraphicsTextItem *mineralRateText2;
    //QGraphicsTextItem *controlText3;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    //void loseInvulnerability();
    //void testMove();

private slots:
    void gameNextScene();
    void shopNextScene();
    void dayStart();
    void on_playButton_clicked();
    void on_instructionsButton_clicked();
    void on_exitButton_clicked();
    void on_playButton2_clicked();
    void on_menuButton_clicked();
    void on_exitButton2_clicked();
    void blackoutDone();
    void darkDone();
    void petDone();

};

#endif // DIALOG_H

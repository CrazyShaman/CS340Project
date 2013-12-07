#include "dialog.h"
#include "ui_dialog.h"
#include "upgrade.h"
#include "newitem.h"
#include "plane.h"
#include "bird.h"
#include "blackout.h"
#include "pet.h"
#include "asteroid.h"
#include "fuel.h"
#include "mineral.h"
#include "background.h"
#include "background2.h"
#include "background3.h"
#include "ship.h"
#include "gamelabel.h"
#include "script.h"
#include <iostream>
#include <QSound>
using namespace std;

//Ui::Dialog *ui;
//QGraphicsScene *sceneShop;
int days;
qreal globalX;
qreal globalY;
newItem *item;
background *sky;
background2 *sky2;
background3 *space;
ship *space_ship;
QTimer *deathTimer;
QTimer *shopTimer;
QTimer *dayTimer;
QTimer *invulnerabilityTimer;
QTimer *invulnBlinkTimer1;
QTimer *invulnBlinkTimer2;
QTimer *blackoutTimer;
QTimer *petTimer;
QTimer *darkTimer;
QTimer *scriptTimer;
QGraphicsTextItem *gameWin1;
QGraphicsTextItem *gameWin2;
QGraphicsTextItem *gameMineralsText;
QGraphicsTextItem *gameFuelText;
QGraphicsTextItem *gameLivesText;
QGraphicsTextItem *shopMinerals;
QGraphicsTextItem *brainFuelText3;
QGraphicsTextItem *resilienceText3;
QGraphicsTextItem *controlText3;
QGraphicsTextItem *brainPowerText3;
QGraphicsTextItem *petStrengthText3;
QGraphicsTextItem *mineralRateText3;
upgrade *blackedout;
gameLabel *thruster;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    this->setWindowTitle("Will of the Alien");
    this->setWindowIcon(QPixmap(":/Pictures/AlienNew .png"));
    this->setFixedHeight(282);
    this->setFixedWidth(389);

    scene = new QGraphicsScene(0,0,250,250,this);
    sceneShop = new QGraphicsScene(0,0,250,250,this);
    sceneMenu = new QGraphicsScene(0,0,250,250,this);
    sceneInstruction = new QGraphicsScene(0,0,250,250,this);
    sceneScript = new QGraphicsScene(0,0,250,250,this);
    ui->graphicsView->setScene(sceneMenu);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    str;

    sound = new QSound(":/Sound/FunkyTime.wav", this);
    sound->setLoops(1000); //loop the sound 1000 times to simulate infinite loop
    sound->play();

    sceneMenu->setBackgroundBrush(QPixmap(":/Pictures/sky5.png"));

    menuTitle1 = new QGraphicsTextItem();
    menuTitle1->setDefaultTextColor(Qt::yellow);
    menuTitle1->setFont(QFont("papyrus",10,75));
    menuTitle1->setScale(4);
    menuTitle1->setPos(-20,-30);
    menuTitle1->setPlainText("Will of the");
    sceneMenu->addItem(menuTitle1);

    menuTitle2 = new QGraphicsTextItem();
    menuTitle2->setDefaultTextColor(Qt::yellow);
    menuTitle2->setFont(QFont("papyrus",10,75));
    menuTitle2->setScale(4);
    menuTitle2->setPos(30,20);
    menuTitle2->setPlainText("Alien");
    sceneMenu->addItem(menuTitle2);



    playButton = new QPushButton("Play", this);
    playButton->setStyleSheet("background-color: rgb(255,255,127); color : rgb(0,170,255); font-size: 16px");
    playButton->setGeometry(QRect(QPoint(270, 120),QSize(90, 40)));
    playButton->setFont(QFont("papyrus",10,75));

    instructionsButton = new QPushButton("Instructions", this);
    instructionsButton->setStyleSheet("background-color: rgb(255,255,127); color : rgb(0,170,255); font-size: 13px");
    instructionsButton->setGeometry(QRect(QPoint(270, 170),QSize(90, 40)));
    instructionsButton->setFont(QFont("papyrus",10,75));

    exitButton = new QPushButton("Exit", this);
    exitButton->setStyleSheet("background-color: rgb(255,255,127); color : rgb(0,170,255); font-size: 16px");
    exitButton->setGeometry(QRect(QPoint(270, 220),QSize(90, 40)));
    exitButton->setFont(QFont("papyrus",10,75));

    menuButton = new QPushButton("Main Menu",this);
    menuButton->setStyleSheet("background-color: rgb(255,255,127); color : rgb(0,170,255); font-size: 16px");
    menuButton->setGeometry(QRect(QPoint(40, 225),QSize(90, 40)));
    menuButton->setFont(QFont("papyrus",10,75));
    menuButton->hide();

    playButton2 = new QPushButton("Play", this);
    playButton2->setStyleSheet("background-color: rgb(255,255,127); color : rgb(0,170,255); font-size: 16px");
    playButton2->setGeometry(QRect(QPoint(140, 225),QSize(90, 40)));
    playButton2->setFont(QFont("papyrus",10,70));
    playButton2->hide();

    exitButton2 = new QPushButton("Exit", this);
    exitButton2->setStyleSheet("background-color: rgb(255,255,127); color : rgb(0,170,255); font-size: 16px");
    exitButton2->setGeometry(QRect(QPoint(240,225), QSize(90,40)));
    exitButton2->setFont(QFont("papyrus", 10, 70));
    exitButton2->hide();



    QPixmap menuAlien(":/Pictures/AlienNew .png");
    QGraphicsPixmapItem *menuItem1 = new QGraphicsPixmapItem;
    menuItem1->setPixmap(menuAlien.scaledToHeight(150,Qt::SmoothTransformation));
    menuItem1->setPos(-50,100);
    sceneMenu->addItem(menuItem1);

    QPixmap menuPlane1(":/Pictures/planeB_transp.png");
    QGraphicsPixmapItem *menuItem2 = new QGraphicsPixmapItem;
    menuItem2->setPixmap(menuPlane1.scaledToWidth(45,Qt::SmoothTransformation));
    menuItem2->setPos(-40,55);
    sceneMenu->addItem(menuItem2);

    QPixmap menuPlane2(":/Pictures/planeA.gif");
    QGraphicsPixmapItem *menuItem3 = new QGraphicsPixmapItem;
    menuItem3->setPixmap(menuPlane2.scaledToWidth(60,Qt::SmoothTransformation));
    menuItem3->setPos(210,55);
    sceneMenu->addItem(menuItem3);

    QPixmap instruc(":/Pictures/background.png");
    QGraphicsPixmapItem *instructionsPic = new QGraphicsPixmapItem;
    instructionsPic->setPixmap((instruc.scaled(375,265)));
    instructionsPic->setPos(-58,-5);
    sceneInstruction->addItem(instructionsPic);

    scriptPix2 = new script(-58,-5,2);
    sceneScript->addItem(scriptPix2);

    scriptPix1 = new script(-58,-5,1);
    sceneScript->addItem(scriptPix1);


    scene->setBackgroundBrush(Qt::white);

    qsrand( QDateTime::currentDateTime().toTime_t() );




    sky = new background;
    scene->addItem(sky);



    sky2 = new background2;
    scene->addItem(sky2);

    space = new background3;
    scene->addItem(space);

    space_ship = new ship;
    scene->addItem(space_ship);

    plane_1 = new plane(-150+(qrand()%300),-20,1,true);
    scene->addItem(plane_1);

    plane_2 = new plane(-150+(qrand()%300),-60,2,false);
    scene->addItem(plane_2);

    plane_3 = new plane(-150+(qrand()%300),-100,3,true);
    scene->addItem(plane_3);

    plane_4 = new plane(-150+(qrand()%300),-140,4,false);
    scene->addItem(plane_4);

    plane_5 = new plane(-150+(qrand()%300),-180,5,true);
    scene->addItem(plane_5);

    plane_6 = new plane(-150+(qrand()%300),-220,6,false);
    scene->addItem(plane_6);

    plane_7 = new plane(-150+(qrand()%300),-260,7,true);
    scene->addItem(plane_7);

    plane_8 = new plane(-150+(qrand()%300),-300,8,false);
    scene->addItem(plane_8);

    plane_9 = new plane(-150+(qrand()%300),-340,9,true);
    scene->addItem(plane_9);

    plane_10 = new plane(-150+(qrand()%300),-380,10,false);
    scene->addItem(plane_10);

    plane_11 = new plane(-150+(qrand()%300),-420,11,true);
    scene->addItem(plane_11);

    plane_12 = new plane(-150+(qrand()%300),-460,12,false);
    scene->addItem(plane_12);

    plane_13 = new plane(-150+(qrand()%300),-500,1,true);
    scene->addItem(plane_13);

    plane_14 = new plane(-150+(qrand()%300),-540,2,false);
    scene->addItem(plane_14);

    plane_15 = new plane(-150+(qrand()%300),-580,3,true);
    scene->addItem(plane_15);

    plane_16 = new plane(-150+(qrand()%300),-620,4,false);
    scene->addItem(plane_16);

    plane_17 = new plane(-150+(qrand()%300),-660,5,true);
    scene->addItem(plane_17);

    plane_18 = new plane(-150+(qrand()%300),-700,6,false);
    scene->addItem(plane_18);

    plane_19 = new plane(-150+(qrand()%300),-740,7,true);
    scene->addItem(plane_19);

    plane_20 = new plane(-150+(qrand()%300),-780,8,false);
    scene->addItem(plane_20);

    plane_21 = new plane(-150+(qrand()%300),-820,9,true);
    scene->addItem(plane_21);

    plane_22 = new plane(-150+(qrand()%300),-860,10,false);
    scene->addItem(plane_22);


    bird_1 = new bird(-150+(qrand()%300),-40,1,false);
    scene->addItem(bird_1);

    bird_2 = new bird(-150+(qrand()%300),-80,2,true);
    scene->addItem(bird_2);

    bird_3 = new bird(-150+(qrand()%300),-120,3,false);
    scene->addItem(bird_3);

    bird_4 = new bird(-150+(qrand()%300),-160,4,true);
    scene->addItem(bird_4);

    bird_5 = new bird(-150+(qrand()%300),-200,5,false);
    scene->addItem(bird_5);

    bird_6 = new bird(-150+(qrand()%300),-240,6,true);
    scene->addItem(bird_6);

    bird_7 = new bird(-150+(qrand()%300),-280,7,false);
    scene->addItem(bird_7);

    bird_8 = new bird(-150+(qrand()%300),-320,8,true);
    scene->addItem(bird_8);

    bird_9 = new bird(-150+(qrand()%300),-360,9,false);
    scene->addItem(bird_9);

    bird_10 = new bird(-150+(qrand()%300),-400,10,true);
    scene->addItem(bird_10);

    bird_11 = new bird(-150+(qrand()%300),-440,11,false);
    scene->addItem(bird_11);

    bird_12 = new bird(-150+(qrand()%300),-480,12,true);
    scene->addItem(bird_12);

    bird_13 = new bird(-150+(qrand()%300),-520,1,false);
    scene->addItem(bird_13);

    bird_14 = new bird(-150+(qrand()%300),-560,2,true);
    scene->addItem(bird_14);

    bird_15 = new bird(-150+(qrand()%300),-600,3,false);
    scene->addItem(bird_15);

    bird_16 = new bird(-150+(qrand()%300),-640,4,true);
    scene->addItem(bird_16);

    bird_17 = new bird(-150+(qrand()%300),-680,5,false);
    scene->addItem(bird_17);

    bird_18 = new bird(-150+(qrand()%300),-720,6,true);
    scene->addItem(bird_18);

    bird_19 = new bird(-150+(qrand()%300),-760,7,false);
    scene->addItem(bird_19);

    bird_20 = new bird(-150+(qrand()%300),-800,8,true);
    scene->addItem(bird_20);

    bird_21 = new bird(-150+(qrand()%300),-840,9,false);
    scene->addItem(bird_21);


    mineral_1 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,true);
    scene->addItem(mineral_1);

    mineral_2 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,true);
    scene->addItem(mineral_2);

    mineral_3 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,true);
    scene->addItem(mineral_3);

    mineral_4 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,true);
    scene->addItem(mineral_4);

    mineral_5 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,true);
    scene->addItem(mineral_5);

    mineral_6 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,true);
    scene->addItem(mineral_6);

    mineral_7 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,true);
    scene->addItem(mineral_7);

    mineral_8 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,true);
    scene->addItem(mineral_8);

    mineral_9 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,true);
    scene->addItem(mineral_9);

    mineral_10 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,true);
    scene->addItem(mineral_10);

    mineral_11 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,true);
    scene->addItem(mineral_11);

    mineral_12 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,true);
    scene->addItem(mineral_12);

    mineral_13 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,true);
    scene->addItem(mineral_13);

    mineral_14 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,true);
    scene->addItem(mineral_14);

    mineral_15 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,true);
    scene->addItem(mineral_15);

    mineral_16 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,true);
    scene->addItem(mineral_16);

    mineral_17 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,true);
    scene->addItem(mineral_17);

    mineral_18 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,true);
    scene->addItem(mineral_18);

    mineral_19 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,true);
    scene->addItem(mineral_19);

    mineral_20 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,true);
    scene->addItem(mineral_20);

    mineral_21 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,true);
    scene->addItem(mineral_21);

    mineral_22 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,true);
    scene->addItem(mineral_22);

    mineral_23 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,false);
    scene->addItem(mineral_23);

    mineral_24 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,false);
    scene->addItem(mineral_24);

    mineral_25 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,false);
    scene->addItem(mineral_25);

    mineral_26 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,false);
    scene->addItem(mineral_26);

    mineral_27 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,false);
    scene->addItem(mineral_27);

    mineral_28 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,false);
    scene->addItem(mineral_28);

    mineral_29 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,false);
    scene->addItem(mineral_29);

    mineral_30 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,false);
    scene->addItem(mineral_30);

    mineral_31 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,false);
    scene->addItem(mineral_31);

    mineral_32 = new mineral(-150+(qrand()%300),50-(qrand()%1200),1,false);
    scene->addItem(mineral_32);

    fuel_1 = new fuel(150-(qrand()%120),-50-(qrand()%1200),1,true);
    scene->addItem(fuel_1);

    fuel_2 = new fuel(-150+(qrand()%120),-50-(qrand()%1200),2,true);
    scene->addItem(fuel_2);

    fuel_3 = new fuel(150-(qrand()%120),-50-(qrand()%1200),3,true);
    scene->addItem(fuel_3);

    fuel_4 = new fuel(-150+(qrand()%120),-50-(qrand()%1200),4,true);
    scene->addItem(fuel_4);

    blackout_1 = new blackout(100,20,4,true);
    scene->addItem(blackout_1);

    blackout_2 = new blackout(100,-1400,4,true);
    scene->addItem(blackout_2);

    pet_1 = new pet(0,20,4,true);
    scene->addItem(pet_1);

    pet_2 = new pet(0,-1400,4,true);
    scene->addItem(pet_2);

    asteroid_1 = new asteroid(20,-1400,1,true);
    scene->addItem(asteroid_1);

    asteroid_2 = new asteroid(200,-1400,2,false);
    scene->addItem(asteroid_2);

    asteroid_3 = new asteroid(-100,-1400,3,true);
    scene->addItem(asteroid_3);

    asteroid_4 = new asteroid(120,-1400,4,false);
    scene->addItem(asteroid_4);

    asteroid_5 = new asteroid(20,-1400,5,true);
    scene->addItem(asteroid_5);

    asteroid_6 = new asteroid(200,-1400,6,false);
    scene->addItem(asteroid_6);

    asteroid_7 = new asteroid(-100,-1400,7,true);
    scene->addItem(asteroid_7);

    asteroid_8 = new asteroid(120,-1400,8,false);
    scene->addItem(asteroid_8);

    asteroid_9 = new asteroid(20,-1400,9,true);
    scene->addItem(asteroid_9);

    asteroid_10 = new asteroid(200,-1400,10,false);
    scene->addItem(asteroid_10);

    asteroid_11 = new asteroid(-100,-1400,11,true);
    scene->addItem(asteroid_11);

    asteroid_12 = new asteroid(120,-1400,12,false);
    scene->addItem(asteroid_12);

    asteroid_13 = new asteroid(20,-1400,13,true);
    scene->addItem(asteroid_13);

    asteroid_14 = new asteroid(200,-1400,14,false);
    scene->addItem(asteroid_14);

    asteroid_15 = new asteroid(-100,-1400,15,true);
    scene->addItem(asteroid_15);

    asteroid_16 = new asteroid(120,-1400,16,false);
    scene->addItem(asteroid_16);

    gameMineralsText = new QGraphicsTextItem();
    gameMineralsText->setPos(-40,-10);
    gameMineralsText->setScale(1.8);
    scene->addItem(gameMineralsText);

    gameMineralsPix = new gameLabel(-55,0,1);
    scene->addItem(gameMineralsPix);



    gameFuelText = new QGraphicsTextItem();
    gameFuelText->setPos(20,-10);
    gameFuelText->setScale(1.8);
    scene->addItem(gameFuelText);

    gameFuelPix = new gameLabel(5,0,2);
    scene->addItem(gameFuelPix);



    gameLivesText = new QGraphicsTextItem();
    gameLivesText->setPos(270,-10);
    gameLivesText->setScale(1.8);
    scene->addItem(gameLivesText);

    gameLivesPix = new gameLabel(255,-2,3);
    scene->addItem(gameLivesPix);




    dayText = new QGraphicsTextItem;
    dayText->setScale(6);
    dayText->setPos(20,0);
    scene->addItem(dayText);

    item = new newItem;
    scene->addItem(item);

    thruster = new gameLabel(119,216,4);
    thruster->setOpacity(0.5);
    scene->addItem(thruster);

    blackedout = new upgrade(7);
    blackedout->setPos(-100,-100);
    blackedout->hide();
    scene->addItem(blackedout);

    gameWin1 = new QGraphicsTextItem();
    gameWin1->setScale(5);
    gameWin1->setPos(0,100);
    gameWin1->setPlainText("You Win!");
    gameWin1->setDefaultTextColor(Qt::white);
    gameWin1->hide();
    scene->addItem(gameWin1);

    gameWin2 = new QGraphicsTextItem();
    gameWin2->setScale(2.5);
    gameWin2->setPos(-40,170);
    gameWin2->setDefaultTextColor(Qt::white);
    gameWin2->hide();
    scene->addItem(gameWin2);

    sky->setFocus();

    //Declare timers and connect them to events

    timer = new QTimer(this);
    cout << "Output sentence" << endl;
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    connect(timer,SIGNAL(timeout()),scene,SLOT(update()));
    connect(timer,SIGNAL(timeout()),sceneShop,SLOT(advance()));
    connect(timer,SIGNAL(timeout()),sceneShop,SLOT(update()));
    connect(timer,SIGNAL(timeout()),sceneScript,SLOT(advance()));
    connect(timer,SIGNAL(timeout()),sceneScript,SLOT(update()));
    timer->start(10);
    deathTimer = new QTimer(this);
    connect(deathTimer,SIGNAL(timeout()),this,SLOT(gameNextScene()));
    shopTimer = new QTimer(this);
    dayTimer = new QTimer(this);
    connect(shopTimer,SIGNAL(timeout()),this,SLOT(shopNextScene()));
    connect(dayTimer,SIGNAL(timeout()),this,SLOT(dayStart()));
    invulnerabilityTimer = new QTimer(this);
    invulnBlinkTimer1 = new QTimer(this);
    invulnBlinkTimer2 = new QTimer(this);
    connect(playButton, SIGNAL(released()), this, SLOT(on_playButton_clicked()));
    connect(instructionsButton, SIGNAL(released()), this, SLOT(on_instructionsButton_clicked()));
    connect(exitButton, SIGNAL(released()), this, SLOT(on_exitButton_clicked()));
    connect(menuButton, SIGNAL(released()), this, SLOT(on_menuButton_clicked()));
    connect(playButton2, SIGNAL(released()), this, SLOT(on_playButton2_clicked()));
    connect(exitButton2, SIGNAL(released()), this, SLOT(on_exitButton2_clicked()));
    blackoutTimer = new QTimer(this);
    connect(blackoutTimer,SIGNAL(timeout()),this,SLOT(blackoutDone()));
    petTimer = new QTimer(this);
    connect(petTimer,SIGNAL(timeout()),this,SLOT(petDone()));
    darkTimer = new QTimer(this);
    connect(darkTimer,SIGNAL(timeout()),this,SLOT(darkDone()));
    scriptTimer = new QTimer(this);
    connect(scriptTimer,SIGNAL(timeout()),this,SLOT(shopNextScene()));









    int height = 40;
    int width = 40;
    int row1 = 80;
    int row2 = 175;
    int spacing = 80;
    int start = 26;


    // Set up the shop

    sceneShop->addRect(start, row1, height, width);
    sceneShop->addRect(start+spacing, row1, height, width);
    sceneShop->addRect(start+spacing*2, row1, height, width);
    sceneShop->addRect(start, row2, height, width);
    sceneShop->addRect(start+spacing, row2, height, width);
    sceneShop->addRect(start+spacing*2, row2, height, width);

    shopTitle = new QGraphicsTextItem();
    shopTitle->setPlainText("The Shop");
    shopTitle->setPos(40,0);
    shopTitle->setScale(3.2);
    sceneShop->addItem(shopTitle);


    shopMinerals = new QGraphicsTextItem();
    shopMinerals->setPlainText("Minerals:");
    shopMinerals->setPos(-40,-10);
    shopMinerals->setScale(1.8);
    sceneShop->addItem(shopMinerals);

    shopMineralsPix = new gameLabel(-55,0,1);
    sceneShop->addItem(shopMineralsPix);

    shopDone = new upgrade(0);
    sceneShop->addItem(shopDone);


    brainFuelPix = new upgrade(1);
    sceneShop->addItem(brainFuelPix);

    brainFuelText1 = new QGraphicsTextItem();
    brainFuelText1->setPlainText("Brain Fuel");
    brainFuelText1->setDefaultTextColor(Qt::blue);
    brainFuelText1->setPos(start-14,row1-25);
    brainFuelText1->setScale(1.3);
    sceneShop->addItem(brainFuelText1);

    brainFuelText2 = new QGraphicsTextItem();
    brainFuelText2->setPlainText("20 Minerals");
    brainFuelText2->setPos(start-10,row1+36);
    brainFuelText2->setScale(1);
    sceneShop->addItem(brainFuelText2);

    brainFuelText3 = new QGraphicsTextItem();
    brainFuelText3->setPlainText("0/5");
    brainFuelText3->setPos(start+7,row1+42);
    brainFuelText3->setScale(1.3);
    sceneShop->addItem(brainFuelText3);

    resiliencePix = new upgrade(2);
    sceneShop->addItem(resiliencePix);

    resilienceText1 = new QGraphicsTextItem();
    resilienceText1->setPlainText("Resilience");
    resilienceText1->setDefaultTextColor(Qt::blue);
    resilienceText1->setPos(start-14+spacing,row1-25);
    resilienceText1->setScale(1.3);
    sceneShop->addItem(resilienceText1);

    resilienceText2 = new QGraphicsTextItem();
    resilienceText2->setPlainText("20 Minerals");
    resilienceText2->setPos(start-10+spacing,row1+36);
    resilienceText2->setScale(1);
    sceneShop->addItem(resilienceText2);

    resilienceText3 = new QGraphicsTextItem();
    resilienceText3->setPlainText("0/5");
    resilienceText3->setPos(start+7+spacing,row1+42);
    resilienceText3->setScale(1.3);
    sceneShop->addItem(resilienceText3);

    controlPix = new upgrade(3);
    sceneShop->addItem(controlPix);

    controlText1 = new QGraphicsTextItem();
    controlText1->setPlainText("Control");
    controlText1->setDefaultTextColor(Qt::blue);
    controlText1->setPos(start-8+spacing*2,row1-25);
    controlText1->setScale(1.3);
    sceneShop->addItem(controlText1);

    controlText2 = new QGraphicsTextItem();
    controlText2->setPlainText("10 Minerals");
    controlText2->setPos(start-10+spacing*2,row1+36);
    controlText2->setScale(1);
    sceneShop->addItem(controlText2);

    controlText3 = new QGraphicsTextItem();
    controlText3->setPlainText("0/5");
    controlText3->setPos(start+7+spacing*2,row1+42);
    controlText3->setScale(1.3);
    sceneShop->addItem(controlText3);

    brainPowerPix = new upgrade(4);
    sceneShop->addItem(brainPowerPix);

    brainPowerText1 = new QGraphicsTextItem();
    brainPowerText1->setPlainText("Brain Power");
    brainPowerText1->setDefaultTextColor(Qt::blue);
    brainPowerText1->setPos(start-25,row2-25);
    brainPowerText1->setScale(1.3);
    sceneShop->addItem(brainPowerText1);

    brainPowerText2 = new QGraphicsTextItem();
    brainPowerText2->setPlainText("20 Minerals");
    brainPowerText2->setPos(start-10,row2+36);
    brainPowerText2->setScale(1);
    sceneShop->addItem(brainPowerText2);

    brainPowerText3 = new QGraphicsTextItem();
    brainPowerText3->setPlainText("0/5");
    brainPowerText3->setPos(start+7,row2+42);
    brainPowerText3->setScale(1.3);
    sceneShop->addItem(brainPowerText3);

    petStrengthPix = new upgrade(5);
    sceneShop->addItem(petStrengthPix);

    petStrengthText1 = new QGraphicsTextItem();
    petStrengthText1->setPlainText("Pet Strength");
    petStrengthText1->setDefaultTextColor(Qt::blue);
    petStrengthText1->setPos(start-25+spacing,row2-25);
    petStrengthText1->setScale(1.3);
    sceneShop->addItem(petStrengthText1);

    petStrengthText2 = new QGraphicsTextItem();
    petStrengthText2->setPlainText("20 Minerals");
    petStrengthText2->setPos(start-10+spacing,row2+36);
    petStrengthText2->setScale(1);
    sceneShop->addItem(petStrengthText2);

    petStrengthText3 = new QGraphicsTextItem();
    petStrengthText3->setPlainText("0/5");
    petStrengthText3->setPos(start+7+spacing,row2+42);
    petStrengthText3->setScale(1.3);
    sceneShop->addItem(petStrengthText3);

    mineralRatePix = new upgrade(6);
    sceneShop->addItem(mineralRatePix);

    mineralRateText1 = new QGraphicsTextItem();
    mineralRateText1->setPlainText("Mineral Rate");
    mineralRateText1->setDefaultTextColor(Qt::blue);
    mineralRateText1->setPos(start-20+spacing*2,row2-25);
    mineralRateText1->setScale(1.3);
    sceneShop->addItem(mineralRateText1);

    mineralRateText2 = new QGraphicsTextItem();
    mineralRateText2->setPlainText("10 Minerals");
    mineralRateText2->setPos(start-10+spacing*2,row2+36);
    mineralRateText2->setScale(1);
    sceneShop->addItem(mineralRateText2);

    mineralRateText3 = new QGraphicsTextItem();
    mineralRateText3->setPlainText("0/5");
    mineralRateText3->setPos(start+7+spacing*2,row2+42);
    mineralRateText3->setScale(1.3);
    sceneShop->addItem(mineralRateText3);


}

/// Goes to shop
void Dialog::gameNextScene(){
    deathTimer->stop();
    for (int i = 0;i < 3;i++){
        sky->keysPressed[i] = false;
    }
    ui->graphicsView->setScene(sceneShop);
}

/// start of day text
void Dialog::dayStart(){
    dayTimer->stop();
    dayText->hide();
}

/// starts new day
void Dialog::shopNextScene(){
    scriptTimer->stop();
    item->dead = false;
    sky->deadCheck = false;
    sky->deadCheck2 = false;
    shopTimer->stop();
    item->day++;
    str.setNum(item->day,'g',10);
    str = "Day " + str;


    dayText->setPlainText(str);
    dayText->show();
    dayTimer->start(1300);
    if (mineralRatePix->upgrade_level == 1){
        mineral_23->mineralAvailable = true;
        mineral_24->mineralAvailable = true;
    }
    if (mineralRatePix->upgrade_level == 2){
        mineral_25->mineralAvailable = true;
        mineral_26->mineralAvailable = true;
    }
    if (mineralRatePix->upgrade_level == 3){
        mineral_27->mineralAvailable = true;
        mineral_28->mineralAvailable = true;
    }
    if (mineralRatePix->upgrade_level == 4){
        mineral_29->mineralAvailable = true;
        mineral_30->mineralAvailable = true;
    }
    if (mineralRatePix->upgrade_level == 5){
        mineral_31->mineralAvailable = true;
        mineral_32->mineralAvailable = true;
    }
    mineral_1->respawn();
    mineral_2->respawn();
    mineral_3->respawn();
    mineral_4->respawn();
    mineral_5->respawn();
    mineral_6->respawn();
    mineral_7->respawn();
    mineral_8->respawn();
    mineral_9->respawn();
    mineral_10->respawn();
    mineral_11->respawn();
    mineral_12->respawn();
    mineral_13->respawn();
    mineral_14->respawn();
    mineral_15->respawn();
    mineral_16->respawn();
    mineral_17->respawn();
    mineral_18->respawn();
    mineral_19->respawn();
    mineral_20->respawn();
    mineral_21->respawn();
    mineral_22->respawn();
    mineral_23->respawn();
    mineral_24->respawn();
    mineral_25->respawn();
    mineral_26->respawn();
    mineral_27->respawn();
    mineral_28->respawn();
    mineral_29->respawn();
    mineral_30->respawn();
    mineral_31->respawn();
    mineral_32->respawn();
    fuel_1->respawn();
    fuel_2->respawn();
    fuel_3->respawn();
    fuel_4->respawn();
    pet_1->respawn();
    pet_2->respawn();
    blackout_1->respawn();
    blackout_2->respawn();
    if (brainFuelPix->upgrade_level == 0){
        item->itemFuel = 100;
    }
    if (brainFuelPix->upgrade_level == 1){
        item->itemFuel = 120;
    }
    if (brainFuelPix->upgrade_level == 2){
        item->itemFuel = 140;
    }
    if (brainFuelPix->upgrade_level == 3){
        item->itemFuel = 160;
    }
    if (brainFuelPix->upgrade_level == 4){
        item->itemFuel = 180;
    }
    if (brainFuelPix->upgrade_level == 5){
        item->itemFuel = 200;
    }
    if (resiliencePix->upgrade_level == 0){
        item->lives = 2;
    }
    if (resiliencePix->upgrade_level == 1){
        item->lives = 3;
    }
    if (resiliencePix->upgrade_level == 2){
        item->lives = 4;
    }
    if (resiliencePix->upgrade_level == 3){
        item->lives = 5;
    }
    if (resiliencePix->upgrade_level == 4){
        item->lives = 6;
    }
    if (resiliencePix->upgrade_level == 5){
        item->lives = 7;
    }
    if (controlPix->upgrade_level == 1){
        sky->handlingBonus = 0.002;
    }
    if (controlPix->upgrade_level == 2){
        sky->handlingBonus = 0.004;
    }
    if (controlPix->upgrade_level == 3){
        sky->handlingBonus = 0.006;
    }
    if (controlPix->upgrade_level == 4){
        sky->handlingBonus = 0.008;
    }
    if (controlPix->upgrade_level == 5){
        sky->handlingBonus = 0.01;
    }
    if (brainPowerPix->upgrade_level == 1){
        sky->strengthBonus = 0.002;
    }
    if (brainPowerPix->upgrade_level == 2){
        sky->strengthBonus = 0.004;
    }
    if (brainPowerPix->upgrade_level == 3){
        sky->strengthBonus = 0.006;
    }
    if (brainPowerPix->upgrade_level == 4){
        sky->strengthBonus = 0.008;
    }
    if (brainPowerPix->upgrade_level == 5){
        sky->strengthBonus = 0.01;
    }
    if (petStrengthPix->upgrade_level == 1){
        item->petBonus = 250;
    }
    if (petStrengthPix->upgrade_level == 2){
        item->petBonus = 500;
    }
    if (petStrengthPix->upgrade_level == 3){
        item->petBonus = 750;
    }
    if (petStrengthPix->upgrade_level == 4){
        item->petBonus = 1000;
    }
    if (petStrengthPix->upgrade_level == 5){
        item->petBonus = 1250;
    }
    ui->graphicsView->setScene(scene);
}

/// when play is pushed
void Dialog::on_playButton_clicked()
{
    ui->graphicsView->setScene(sceneScript);
    playButton->hide();
    instructionsButton->hide();
    exitButton->hide();
    sound->stop();
    sound2 = new QSound(":/Sound/AlienTheme.wav");
    sound2->setLoops(1000);
    sound2->play();
}

/// when instructions is pushed
void Dialog::on_instructionsButton_clicked()
{
    ui->graphicsView->setScene(sceneInstruction);
    playButton->hide();
    instructionsButton->hide();
    exitButton->hide();
    menuButton->show();
    playButton2->show();
    exitButton2->show();
}

/// when exit is pushed
void Dialog::on_exitButton_clicked()
{
    this->close();
}

/// when menu is pushed
void Dialog::on_menuButton_clicked()
{
    ui->graphicsView->setScene(sceneMenu);
    playButton->show();
    instructionsButton->show();
    exitButton->show();
    menuButton->hide();
    playButton2->hide();
    exitButton2->hide();
}

/// when playbutton2 is pushed
void Dialog::on_playButton2_clicked()
{
   ui->graphicsView->setScene(sceneScript);
   menuButton->hide();
   playButton2->hide();
   exitButton2->hide();
   sound->stop();
   sound2 = new QSound(":/Sound/AlienTheme.wav");
   sound2->setLoops(1000);
   sound2->play();
}

/// when exitbutton2 is pushed
void Dialog::on_exitButton2_clicked()
{
    this->close();
}

/// when blackout is done
void Dialog::blackoutDone(){
    blackoutTimer->stop();
    blackedout->hide();
    darkTimer->start(750);
    item->dark = true;
}

/// residual effect of blackout
void Dialog::darkDone(){
    darkTimer->stop();
    item->dark = false;

}

/// no more pet invulnerability/speed
void Dialog::petDone(){
    petTimer->stop();
    item->petFlying = false;
    item->invulnerability = false;
}

Dialog::~Dialog()
{
    delete ui;
}

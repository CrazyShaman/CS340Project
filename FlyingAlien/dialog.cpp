#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
using namespace std;

qreal globalX;
qreal globalY;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(0,0,250,250,this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    scene->setBackgroundBrush(Qt::white);




    sky = new background;
    scene->addItem(sky);

    plane_1 = new plane;
    scene->addItem(plane_1);

    item = new newItem;
    scene->addItem(item);



    sky->setFocus();


    //pItem = scene->addPixmap(QPixmap::fromImage(QImage(":/Pictures/sky.jpg")));
   // pItem2 = scene->addPixmap(QPixmap::fromImage(QImage(":/Pictures/alien.jpg")));

   // sky->paint();
   // item->paint();


    //scene->setSceneRect(0,0,1000,1000);
    /*
    int currentX = 0;
    for (unsigned i=currentX; i<currentX + 100; i++)
    {
        ui->graphicsView->scene()->setSceneRect(i,300,100,100);
        qApp->processEvents();
    }
    currentX += 100;

    */
    timer = new QTimer(this);
    cout << "Output sentence" << endl;
    connect(timer,SIGNAL(timeout()),scene,SLOT(update()));
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    timer->start(1);
}



Dialog::~Dialog()
{
    delete ui;
}

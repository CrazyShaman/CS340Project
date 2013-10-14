#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(0,0,250,250,this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    scene->setBackgroundBrush(Qt::white);

    item = new newItem;
    scene->addItem(item);
    item->setFocus();

    sky = new background;
    scene->addItem(sky);
}

Dialog::~Dialog()
{
    delete ui;
}

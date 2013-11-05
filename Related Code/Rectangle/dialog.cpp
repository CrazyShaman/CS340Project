#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QPixmap p(":/Pictures/thesun.jpg");
    ui->Sun->setPixmap(p);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    int height = 60;
    int width = 60;
    int row1 = 90;
    int row2 = 210;

    QRect rec1(20, row1, height, width);
    QRect rec2(140, row1, height, width);
    QRect rec3(260, row1, height, width);
    QRect rec4(20, row2, height, width);
    QRect rec5(140, row2, height, width);
    QRect rec6(260, row2, height, width);


    //QBrush brush1(Qt::blue, Qt::SolidPattern);
    //QBrush brush2(Qt::green, Qt::SolidPattern);
    //painter.fillRect(rec1,brush1);
    //painter.fillRect(rec2, brush2);
    QPen framepen(Qt::black);
    framepen.setWidth(2);

    QPen framepen2(Qt::yellow);
    framepen.setWidth(2);

    QPen framepen3(Qt::green);
    framepen.setWidth(2);


    painter.setPen(framepen);
    painter.drawRect(rec1);
    //framepen.setColor(Qt::black);

    //painter.setPen(framepen3);
    painter.drawRect(rec2);
    //framepen.setColor(Qt::blue);

   // painter.setPen(framepen3);
    painter.drawRect(rec3);

    painter.drawRect(rec4);
    painter.drawRect(rec5);
    painter.drawRect(rec6);

    //painter.drawEllipse(rec1);

}

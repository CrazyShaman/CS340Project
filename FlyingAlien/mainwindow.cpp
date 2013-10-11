#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   // QPixmap p("/Users/Christofer/Brain Boosting/Fall 2013/CS 340/QT/plane.jpg");
   // ui->planeLabel->setPixmap(planeLabel);


}

MainWindow::~MainWindow()
{
    delete ui;
}

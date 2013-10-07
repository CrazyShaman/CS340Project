#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap p("plane.jpg");
    ui->labelPic->setPixmap(p);


}

MainWindow::~MainWindow()
{
    delete ui;
}

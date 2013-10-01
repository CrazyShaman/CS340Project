#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->horizontalSlider, SLOT(setValue(int)));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->spinBox, SLOT(setValue(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QPixmap pix("C:/Users/Junce/Desktop/chinese101.jpg"); //displays image, place path of image inside quotes
    ui->label->setPixmap(pix);

    QMessageBox::warning(this,tr("hello"),tr("help!"));   //displays a message box
}

void MainWindow::on_actionNew_window_triggered()
{
    nDialog = new newDialog(this);  // displays a dialog window
    nDialog->show();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSound>
#include <QDir>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSound* sound = new QSound("/Users/Brandon/Desktop/space.wav",this);
    //sound->setLoops(-1); //should loop infinitely, but does not work due to a bug
    sound->setLoops(1000); //loop the sound 1000 times to simulate infinite loop
    sound->play();
}

void MainWindow::stateChanged(QMediaPlayer::State state) {

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    //play the file once
    QSound::play("/Users/Brandon/Desktop/mario.wav");


    //play the file in an infinite loop
    /*QSound* sound = new QSound("/Users/Brandon/Desktop/mario.wav",this);
    //sound->setLoops(-1); //should loop infinitely, but does not work due to a bug
    sound->setLoops(1000); //loop the sound 1000 times to simulate infinite loop
    sound->play();*/

}

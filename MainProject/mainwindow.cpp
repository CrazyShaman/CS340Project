#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //create the playing scene
    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(QPixmap("C:/Users/Junce/Desktop/sky.jpg"));

    //creates the initial scene
    QGraphicsScene *openingScene = new QGraphicsScene(this);
    openingScene->setBackgroundBrush(Qt::green);

    //adds initial scene
    ui->graphicsView->setScene(openingScene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    //creates a lable (image of the alien) on the opening scene.
    QPixmap pic("C:/Users/Junce/Desktop/alien.jpg");
    QLabel *lable = new QLabel();
    lable->setPixmap(pic);
    openingScene->addWidget(lable);

    //adds button to the scene
    QPushButton *button = new QPushButton("Start");
    openingScene->addWidget(button);

    //adding alien to scene
    alien1 = new alien;
    scene->addItem(alien1);
    alien1->setFocus();

    //connect(button,SIGNAL(clicked()),ui->graphicsView,SLOT());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->graphicsView->setScene(scene);
}

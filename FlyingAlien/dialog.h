#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "newitem.h"
#include "background.h"
#include "plane.h"

extern qreal globalX;
extern qreal globalY;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    QGraphicsScene * scene;
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QGraphicsItem *pItem;
    QGraphicsItem *pItem2;



private:
    Ui::Dialog *ui;
    newItem *item;
    background *sky;
    plane *plane_1;
    QTimer *timer;



};

#endif // DIALOG_H

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "newitem.h"
#include "background.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QGraphicsScene * scene;
    newItem *item;
    background *sky;

};

#endif // DIALOG_H

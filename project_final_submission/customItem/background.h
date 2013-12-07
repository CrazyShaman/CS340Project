#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtGui>

class background: public QGraphicsItem
{
public:
    background();
    int getX();
    int getY();
    bool keysPressed[3];
    bool deadCheck;
    bool deadCheck2;
    qreal handlingBonus;
    qreal strengthBonus;
    qreal currentX;
    qreal currentY;
    qreal temp_fuel;

private:

    QString str_mins;
    QString str_fuel;
    QString str_lives;


protected:
    QRectF boundingRect()const;
    void DoDeath();
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);

};

#endif // BACKGROUND_H

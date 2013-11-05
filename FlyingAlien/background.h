#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtGui>;

class background: public QGraphicsItem
{
public:
    background();

private:
    qreal currentX;
    qreal currentY;
    bool keysPressed[3];

protected:
    QRectF boundingRect()const;
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);

};

#endif // BACKGROUND_H

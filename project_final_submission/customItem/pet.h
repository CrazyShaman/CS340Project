#ifndef PET_H
#define PET_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtGui>

class pet : public QGraphicsItem
{
private:
    qreal startingX;
    qreal startingY;
    int petIndex;
    bool petDirection;
    qreal petSpeed;
    qreal currentX;
    qreal currentY;
    void DoCollision();

public:
    pet(int x, int y, int index, bool direction);
    void respawn();

protected:
    QRectF boundingRect()const;
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PET_H

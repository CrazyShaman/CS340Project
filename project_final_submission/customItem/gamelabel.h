#ifndef GAMELABEL_H
#define GAMELABEL_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtGui>

class gameLabel : public QGraphicsItem
{
private:
    qreal startingX;
    qreal startingY;
    int gameLabelIndex;


public:
    gameLabel(int x, int y, int index);
    qreal thrusterOpacity;

protected:
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
};

#endif // GAMELABEL_H

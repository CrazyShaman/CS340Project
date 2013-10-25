#ifndef ALIEN_H
#define ALIEN_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtGui>

class alien :  public QGraphicsItem
{
public:
    alien();

protected:
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape() const;
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // ALIEN_H

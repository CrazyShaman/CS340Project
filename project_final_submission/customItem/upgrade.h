#ifndef UPGRADE_H
#define UPGRADE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QtGui>
#include <string>
#include <sstream>

class upgrade : public QGraphicsItem
{
private:
    int img_index;
    QString str;
    bool minCountInit;
public:
    int upgrade_level;
    void blackoutStart();
    upgrade(int index);
    ~upgrade();

protected:
    QRectF boundingRect()const;
    void advance(int phase);
    //void mousePressEvent(QMouseEvent *event);
    //void mouseReleaseEvent(QMouseEvent *event);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    //virtual ~upgrade();
};

#endif // UPGRADE_H

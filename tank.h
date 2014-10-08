#ifndef TANK_H
#define TANK_H

#include <QGraphicsObject>
#include <QImage>
#include <QRectF>
#include <QPainter>

class Tank : public QGraphicsObject
{
public:
    Tank(const qreal &x, const qreal &y, const bool &isLeft, QGraphicsObject *parent = 0);
    virtual ~Tank();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QImage *m_tankImg;

    qreal posX;
    qreal posY;
    qint32 pID;
};

#endif // TANK_H

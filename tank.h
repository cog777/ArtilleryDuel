#ifndef TANK_H
#define TANK_H

#include <QGraphicsObject>
#include <QImage>
#include <QRectF>
#include <QPainter>
#include "cannon.h"

class Tank : public QGraphicsObject
{
public:
    Tank(const qreal &x, const qreal &y, const bool &isLeft, QGraphicsObject *parent = 0);
    virtual ~Tank();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	Cannon *cannon() const;

private:
    QImage *m_tankImg;
	Cannon *m_cannon;
	float m_health;

	bool m_isLeft;
};

#endif // TANK_H

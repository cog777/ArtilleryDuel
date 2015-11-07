#ifndef CANNON_H
#define CANNON_H

#include <QGraphicsObject>
#include <QPainter>
#include <QRectF>
#include <QLine>
#include <QPen>
#include <qmath.h>
#include "bullet.h"

class Cannon : public QGraphicsObject
{
public:
	Cannon(const qint32 &x, const qint32 &y, const bool &isLeft, QGraphicsItem *parent = 0);

	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	float degree() const;
	qint32 gunPowder() const;

public slots:
	void setDegree(const int d);
	void setGunPowder(const int gunPowder);
	Bullet* shoot();

private:
	QRectF m_boundingRect;
	QLine m_line;
	qint32 m_gunPowder;
	int m_degree;
	bool m_isLeft;
};

#endif // CANNON_H

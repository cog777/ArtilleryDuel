#ifndef CANNON_H
#define CANNON_H

#include <QGraphicsObject>
#include <QPainter>
#include <QRectF>
#include <QLine>
#include <QPen>
#include <qmath.h>

class Cannon : public QGraphicsObject
{
public:
	Cannon(const qint32 &x, const qint32 &y, const bool &isLeft, QGraphicsObject *parent = 0);

	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	void setDegree(const float &degree);
	float degree() const;

private:
	QRectF m_currentBoundingRect;
	QLine m_lineCannon;
	float m_degree;
	float m_isLeft;
};

#endif // CANNON_H

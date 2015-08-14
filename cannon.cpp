#include "cannon.h"
#include "settings.h"

Cannon::Cannon(const qint32 &x, const qint32 &y, const bool &isLeft, QGraphicsObject *parent) :
	QGraphicsObject(parent),
	m_degree(0),
	m_isLeft(isLeft)
{
	setPos(x, y);
	setDegree(0);
}

QRectF Cannon::boundingRect() const
{
	return m_currentBoundingRect;
}

void Cannon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option)
	Q_UNUSED(widget)

	QPen pen;
	pen.setWidth(CANNON_WIDTH);
	painter->setPen(pen);
	painter->drawLine(m_lineCannon);
}

void Cannon::setDegree(const float &d)
{
	float degree;
	if(d < MIN_DEGREE)
		degree = MIN_DEGREE;
	else if(d > MAX_DEGREE)
		degree = MAX_DEGREE;
	else degree = d;
	float radian = qDegreesToRadians(degree);

	qint32 toX = qCos(radian) * TANK_CANNON_SIZE;
	qint32 toY = qSin(radian) * TANK_CANNON_SIZE;
	if(!m_isLeft) toX = -toX;

	m_lineCannon.setLine(0, 0, toX, -toY);
	m_currentBoundingRect = QRectF(0, -toY, toX, toY);
	m_degree = degree;
	update(boundingRect());
}

float Cannon::degree() const
{
	return m_degree;
}

void Cannon::setGunPowder(const qint32 &gunPowder)
{
	m_gunPowder = gunPowder;
}

qint32 Cannon::gunPowder() const
{
	return m_gunPowder;
}

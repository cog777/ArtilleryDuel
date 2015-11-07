#include "cannon.h"
#include "mainwindow.h"
#include "settings.h"
#include <QDebug>

extern MainWindow *mainWindow;

Cannon::Cannon(const qint32 &x, const qint32 &y, const bool &isLeft, QGraphicsItem *parent) :
	QGraphicsObject(parent),
	m_gunPowder(CANNON_MIN_GUNPOWDER),
	m_degree(0),
	m_isLeft(isLeft)
{
	setPos(x, y);
	setDegree(0);

	m_boundingRect.setRect(0, -CANNON_SIZE, ((isLeft) ? CANNON_SIZE : -CANNON_SIZE), CANNON_SIZE);

	if(m_isLeft)
	{
		connect(mainWindow, &MainWindow::p1_degreeChanged, this, &Cannon::setDegree);
		connect(mainWindow, &MainWindow::p1_gunPowderChanged, this, &Cannon::setGunPowder);
	}
	else
	{
		connect(mainWindow, &MainWindow::p2_degreeChanged, this, &Cannon::setDegree);
		connect(mainWindow, &MainWindow::p2_gunPowderChanged, this, &Cannon::setGunPowder);
	}
}

QRectF Cannon::boundingRect() const
{
	return m_boundingRect;
}

void Cannon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option)
	Q_UNUSED(widget)

	QPen pen;
	pen.setWidth(CANNON_WIDTH);
	painter->setPen(pen);
	painter->drawLine(m_line);

	pen.setColor(Qt::magenta);
	pen.setWidth(1);
	painter->setPen(pen);
	painter->drawRect(boundingRect());
}

void Cannon::setDegree(const int d)
{
	qint32 degree;
	if(d < CANNON_MIN_DEGREE)
		degree = CANNON_MIN_DEGREE;
	else if(d > CANNON_MAX_DEGREE)
		degree = CANNON_MAX_DEGREE;
	else degree = d;
	float radian = qDegreesToRadians((float)degree);

	qint32 toX = qCos(radian) * CANNON_SIZE;
	qint32 toY = qSin(radian) * CANNON_SIZE;
	if(!m_isLeft) toX = -toX;

	m_line.setLine(0, 0, toX, -toY);
	m_degree = degree;
	update(boundingRect());
}

float Cannon::degree() const
{
	return m_degree;
}

void Cannon::setGunPowder(const int gunPowder)
{
	m_gunPowder = gunPowder;
}

Bullet *Cannon::shoot()
{
	return new Bullet(m_line.p2(), m_isLeft, m_degree, m_gunPowder, this);
}

qint32 Cannon::gunPowder() const
{
	return m_gunPowder;
}

#include <QDebug>
#include <typeinfo>
#include "bullet.h"
#include "debug.h"
#include "tank.h"
#include "settings.h"

Bullet::Bullet(const qint32 &x, const qint32 &y, const bool &isLeft, const qint32 &degree, const qint32 &gunPowder, QGraphicsItem *parent)
: QGraphicsObject(parent),
  m_isLeft(isLeft),
  m_gunPowder(gunPowder),
  m_radian(qDegreesToRadians((float)degree)),
  m_currentT(0),
  m_timer(0)
{
	m_startPos.setX(x);
	m_startPos.setY(y);
	setPos(m_startPos);
	m_timer = new QTimer(this);
	connect(m_timer, &QTimer::timeout, this, &Bullet::move);

	m_timer->start(BULLET_MOVING_TIMER_INTERVAL);
}

Bullet::Bullet(const QPoint &startPos, const bool &isLeft, const qint32 &degree, const qint32 &gunPowder, QGraphicsItem *parent)
: QGraphicsObject(parent),
  m_isLeft(isLeft),
  m_startPos(startPos),
  m_gunPowder(gunPowder),
  m_radian(qDegreesToRadians((float)degree)),
  m_currentT(0),
  m_timer(0)
{
	setPos(m_startPos);
	m_timer = new QTimer(this);
	connect(m_timer, &QTimer::timeout, this, &Bullet::move);

	m_timer->start(BULLET_MOVING_TIMER_INTERVAL);
}

QRectF Bullet::boundingRect() const
{
	return QRectF(-BULLET_SIZE, -BULLET_SIZE, (2 * BULLET_SIZE), (2 * BULLET_SIZE));
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option)
	Q_UNUSED(widget)

	QPen pen;
	pen.setColor(Qt::black);
	pen.setBrush(QBrush(Qt::black));
	painter->setPen(pen);
	painter->drawEllipse(QPoint(0, 0), BULLET_SIZE, BULLET_SIZE);

/*	pen.setColor(Qt::magenta);
	pen.setBrush(QBrush(Qt::NoBrush));
	painter->setPen(pen);
	painter->drawRect(boundingRect());*/
}

void Bullet::move()
{
	QList<QGraphicsItem*> colliding_items = collidingItems();
	for(qint32 i = 0; i < colliding_items.size(); ++i)
	{
		if(typeid(colliding_items.at(i)) == typeid(Tank))
		{
			scene()->removeItem(this);
			deleteLater();
		}
	}

	QPointF pos = this->scenePos();
	if(pos.x() > scene()->width() || pos.y() > scene()->height() || pos.x() < 0)
	{
		scene()->removeItem(this);
		deleteLater();
	}

	float cos_a = qCos(m_radian);
	float sin_a = qSin(m_radian);
	qint32 v0_t = m_gunPowder * m_currentT;

	int x = v0_t * cos_a;
	int y = v0_t * sin_a - (10 / 2) * m_currentT * m_currentT;
	setPos(m_startPos.x() + ((m_isLeft) ? x : -x),
		   m_startPos.y() - y);

	m_currentT += BULLET_INCREASE_T;
}

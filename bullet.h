#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QPainter>
#include <QBrush>
#include <QPoint>
#include <QRectF>
#include <QTimer>
#include <QList>
#include <typeinfo>
#include <qmath.h>

class Bullet : public QGraphicsObject
{
public:
	Bullet(const qint32 &x, const qint32 &y, const bool &isLeft, const qint32 &degree, const qint32 &gunPowder, QGraphicsItem *parent = 0);
	Bullet(const QPoint &startPos, const bool &isLeft, const qint32 &degree, const qint32 &gunPowder, QGraphicsItem *parent = 0);

	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private slots:
	void move();

private:
	bool m_isLeft;
	QPoint m_startPos;
	qint32 m_gunPowder;
	float m_radian;
	float m_currentT;
	QTimer *m_timer;
};

#endif // BULLET_H

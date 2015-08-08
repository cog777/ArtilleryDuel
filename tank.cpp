#include "tank.h"
#include "settings.h"

Tank::Tank(const qreal &x, const qreal &y, const bool &isLeft, QGraphicsObject *parent) :
	QGraphicsObject(parent),
	m_tankImg(0),
	m_cannon(0),
	isLeft(isLeft)
{
	QImage img = QImage(":/images/player/Body.png");
	img = img.scaled(img.width() / TANK_MINIMIZE, img.height() / TANK_MINIMIZE);
	if(isLeft) img = img.mirrored(true, false);
	m_tankImg = new QImage(img);

	qint32 posX = x - (img.width() / 2);
	qint32 posY = y - (img.height() / 2);
	setPos(posX, posY);

	qint32 cannonX = isLeft ? img.width() / 2.3 : img.width() / 1.7;
	qint32 cannonY = img.height() / 2.3;
	m_cannon = new Cannon(cannonX, cannonY, isLeft, this);
}

Tank::~Tank()
{
    delete m_tankImg;
}

QRectF Tank::boundingRect() const
{
	return QRectF(0, 0, m_tankImg->width(), m_tankImg->height());
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

	painter->drawImage(0, 0, *m_tankImg);
}

Cannon *Tank::cannon() const
{
	return m_cannon;
}

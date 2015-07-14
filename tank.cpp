#include "tank.h"
#include "settings.h"

Tank::Tank(const qreal &x, const qreal &y, const bool &isLeft, QGraphicsObject *parent) :
    QGraphicsObject(parent), posX(x), posY(y), pID(isLeft)
{
	QImage img = QImage(":/images/player/Body.png");
	img = img.scaled(img.width() / TANK_MINIMIZE, img.height() / TANK_MINIMIZE);
	m_tankImg = new QImage(img);
    if(isLeft) *m_tankImg = m_tankImg->mirrored(true, false);

	setPos(posX - (m_tankImg->width() / 2), posY + (m_tankImg->height() / 2));
}

Tank::~Tank()
{
    delete m_tankImg;
}

QRectF Tank::boundingRect() const
{
	return QRectF(0, m_tankImg->height() * -1, m_tankImg->width(), m_tankImg->height());
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

	painter->drawImage(0, m_tankImg->height() * -1, *m_tankImg);
}

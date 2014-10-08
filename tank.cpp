#include "tank.h"

const qreal MAX_TANK_WIDTH = 95;
const qreal MAX_TANK_HEIGHT = 46;

Tank::Tank(const qreal &x, const qreal &y, const bool &isLeft, QGraphicsObject *parent) :
    QGraphicsObject(parent), posX(x), posY(y), pID(isLeft)
{
    m_tankImg = new QImage(":/images/player/Body.png");
    if(isLeft) *m_tankImg = m_tankImg->mirrored(true, false);

    setPos(posX, posY);
}

Tank::~Tank()
{
    delete m_tankImg;
}

QRectF Tank::boundingRect() const
{
    return QRectF(0, MAX_TANK_HEIGHT * -1, MAX_TANK_WIDTH, MAX_TANK_HEIGHT);
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawImage(0, MAX_TANK_HEIGHT * -1, *m_tankImg);
}

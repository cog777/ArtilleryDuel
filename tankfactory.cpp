#include "tankfactory.h"

TankFactory::TankFactory()
{}

Tank *TankFactory::buildTank(const qreal &x, const qreal &y, const qint32 &playerID, QGraphicsObject *parent)
{
    if(playerID == 0) return new Tank(x, y, false, parent);
    else if(playerID == 1) return new Tank(x, y, true, parent);
    else return NULL;
}

#include "tankfactory.h"
#include "settings.h"

TankFactory::TankFactory()
{}

Tank *TankFactory::buildTank(const qreal &x, const qreal &y, const qint32 &playerID, QGraphicsObject *parent)
{
	if(playerID == PLAYER_1) return new Tank(x, y, true, parent);
	else if(playerID == PLAYER_2) return new Tank(x, y, false, parent);
    else return NULL;
}

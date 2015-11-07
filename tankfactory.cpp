#include "tankfactory.h"
#include "settings.h"

TankFactory::TankFactory()
{}

Tank *TankFactory::buildTank(const qreal &x, const qreal &y, const Players &player, QGraphicsObject *parent)
{
	if(player == Player_1) return new Tank(x, y, true, parent);
	else if(player == Player_2) return new Tank(x, y, false, parent);
    else return NULL;
}

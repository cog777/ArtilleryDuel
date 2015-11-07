#ifndef TANKFACTORY_H
#define TANKFACTORY_H

#include <QGraphicsObject>
#include "tank.h"
#include "settings.h"

class TankFactory
{
public:
    TankFactory();

	static Tank *buildTank(const qreal &x, const qreal &y,
						   const Players &player, QGraphicsObject *parent = 0);
};

#endif // TANKFACTORY_H
/*public class ProductFactory{
 public Product createProduct(String ProductID){
  if (id==ID1)
   return new OneProduct();
  if (id==ID2) return
   return new AnotherProduct();
  ... // so on for the other Ids

        return null; //if the id doesn't have any of the expected values
    }*/

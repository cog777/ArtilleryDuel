#ifndef SETTINGS_H
#define SETTINGS_H

#include <QPoint>
#include <QColor>

// LANDSCAPE
const QColor LANDSCAPE_COLOR = QColor("green");
const QColor BACKGROUND_COLOR = QColor("blue");

const qint32 GROUNDSPLIT = 5; //At least 2
const qint32 TANK_DISTANCE_FROM_SIDE = 100;

const qint32 MAX_MOUNTAIN_HEIGHT = 600;
const qint32 MIN_MOUNTAIN_HEIGHT = 100;
// ----------


// TANK
const qint32 TANK_MINIMIZE = 2.5;
// ----------


// CANNON
const qint32 CANNON_SIZE = 25;
const float CANNON_WIDTH = 2;
const qint32 CANNON_MAX_DEGREE = 80;
const qint32 CANNON_MIN_DEGREE = 0;
const qint32 CANNON_MIN_GUNPOWDER = 20;
const qint32 CANNON_MAX_GUNPOWDER = 110;
// ----------


// BULLET
const qint32 BULLET_SIZE = 1;
const qint32 BULLET_MOVING_TIMER_INTERVAL = 10;
const float BULLET_INCREASE_T = 0.05;
// ----------

// Players
enum Players
{
	Nobody = -1,
	Player_1,
	Player_2
};
// ----------

#endif // SETTINGS_H

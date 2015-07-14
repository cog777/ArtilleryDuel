#ifndef SETTINGS_H
#define SETTINGS_H

#include <QPoint>
#include <QColor>

const QColor LANDSCAPE_COLOR = QColor("green");
const QColor BACKGROUND_COLOR = QColor("blue");

const qint32 GROUNDSPLIT = 5; //At least 2
const qint32 TANK_DISTANCE_FROM_SIDE = 100;

const qint32 MAX_MOUNTAIN_HEIGHT = 600;
const qint32 MIN_MOUNTAIN_HEIGHT = 100;

const qint32 TANK_MINIMIZE = 2.5;

//Player ID-s
const qint32 PLAYER_1 = 0;
const qint32 PLAYER_2 = 1;

#endif // SETTINGS_H

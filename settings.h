#ifndef SETTINGS_H
#define SETTINGS_H

#include <QPoint>
#include <QColor>

const qint32 WINDOW_WIDTH = 700;
const qint32 WINDOW_HEIGHT = 500;

//const QPoint LANDSCAPE_POINT1 = QPoint(0, WINDOW_HEIGHT);
//const QPoint LANDSCAPE_POINT2 = QPoint(WINDOW_WIDTH, 0);

const QPoint LANDSCAPE_POINT1 = QPoint(0, 0);
const QPoint LANDSCAPE_POINT2 = QPoint(WINDOW_WIDTH, WINDOW_HEIGHT);

const qreal LANDSCAPE_WIDTH = WINDOW_WIDTH; //LANDSCAPE_POINT2.x();
const qreal LANDSCAPE_HEIGHT = WINDOW_HEIGHT; //LANDSCAPE_POINT1.y();

const QColor LANDSCAPE_COLOR = QColor("yellow");

#endif // SETTINGS_H

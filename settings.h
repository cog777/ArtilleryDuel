#ifndef SETTINGS_H
#define SETTINGS_H

#include <QPoint>
#include <QColor>

const qint32 WINDOW_WIDTH = 700;
const qint32 WINDOW_HEIGHT = 500;

const QPoint LANDSCAPE_POINT1 = QPoint(0, 450);
const QPoint LANDSCAPE_POINT2 = QPoint(400, 0);
const qreal LANDSCAPE_WIDTH = LANDSCAPE_POINT2.x();
const qreal LANDSCAPE_HEIGHT = LANDSCAPE_POINT1.y();

const QColor LANDSCAPE_COLOR = QColor("yellow");

#endif // SETTINGS_H

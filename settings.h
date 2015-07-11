#ifndef SETTINGS_H
#define SETTINGS_H

#include <QPoint>
#include <QColor>

const QColor LANDSCAPE_COLOR = QColor("green");
const QColor BACKGROUND_COLOR = QColor("blue");

const qint32 GROUNDSPLIT = 5; //At least 2

// Smaller value cause bigger mountain.
const qint32 MAX_MOUNTAIN_HEIGHT = 600; // 200
const qint32 MIN_MOUNTAIN_HEIGHT = 100; // 350

#endif // SETTINGS_H

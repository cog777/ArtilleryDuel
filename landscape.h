#ifndef LANDSCAPE_H
#define LANDSCAPE_H

#include <QGraphicsObject>
#include <QPoint>
#include <QImage>
#include <QPainter>
#include <QVector>
#include "settings.h"

class LandScape : public QGraphicsObject
{
public:
    LandScape(qint32 width, qint32 heigth, QGraphicsObject *parent = 0);
    virtual ~LandScape();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void generateLandScape(const QPoint &point1, const QPoint &point2);

    void generateLandScapeOutLine(const QPoint &point1, const QPoint &point2);
    void generateLandScapePoints(const QPoint &point1, const QPoint &point2);

    QVector<qint32> m_heights;

private:
    QImage *m_pImage;
    QPainter *m_pImagePainter;
    qint32 m_width;
    qint32 m_height;
};

#endif // LANDSCAPE_H

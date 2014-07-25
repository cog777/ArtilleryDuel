#include "landscape.h"

LandScape::LandScape(QGraphicsObject *parent)
{
    m_pImage = new QImage(LANDSCAPE_WIDTH, LANDSCAPE_HEIGHT, QImage::Format_RGB32);
    m_pImagePainter = new QPainter(m_pImage);
}

LandScape::~LandScape()
{}

QRectF LandScape::boundingRect() const
{
    return QRectF(LANDSCAPE_POINT1.x(), LANDSCAPE_POINT2.y(),
                  LANDSCAPE_WIDTH, LANDSCAPE_HEIGHT);
}

void LandScape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawImage(QRectF(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT), *m_pImage);
}

void LandScape::generateLandScape(const QPoint &point1, const QPoint &point2)
{
    m_pImagePainter->drawPoint(point1);
    m_pImagePainter->drawPoint(point2);

    if(qAbs(point1.x() - point2.x()) > 1)
    {
        const QPoint middlePoint((point2.x() - point1.x()) / 2, qrand() % (((point1.y() - point2.y()) + 1) - 1) + 1);

        m_pImagePainter->drawPoint(middlePoint);

        generateLandScape(point1, middlePoint);
        generateLandScape(middlePoint, point2);
    }
}

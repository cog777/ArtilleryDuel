#include "landscape.h"
#include "debug.h"
#include <QPen>

LandScape::LandScape(qint32 &width, qint32 &heigth, QGraphicsObject *parent) :
	QGraphicsObject(parent),
	m_image(0),
	m_imagePainter(0),
	m_width(width),
	m_height(heigth)
{
	m_image = new QImage(m_width, m_height, QImage::Format_RGB32);
	m_image->fill(BACKGROUND_COLOR);
	m_imagePainter = new QPainter(m_image);
	m_imagePainter->setPen(QPen(LANDSCAPE_COLOR));

	m_heights.clear();
	m_heights.resize(m_width + 1);
}

LandScape::~LandScape()
{
	delete m_imagePainter;
	delete m_image;
}

QRectF LandScape::boundingRect() const
{
    return QRectF(0, 0, m_width, m_height);
}

void LandScape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

	painter->drawImage(QRectF(0, 0, m_width, m_height), *m_image);

/*	QPen pen;
	pen.setColor(Qt::magenta);
	painter->setPen(pen);
	painter->drawRect(boundingRect());*/
}

// Pontokat hasznal:

void LandScape::generateLandScapePoints(const QPoint &point1, const QPoint &point2)
{
	//static qint32 counter=0;
	//MSG_TO_LOG() << "Counter:" << ++counter;
	m_imagePainter->drawPoint(point1);
	m_imagePainter->drawPoint(point2);

    if((point2.x() - point1.x()) > 1)
    {
        // X kiszamitasa:
        // Pelda: P1.x = 4 P2.x = 2 Igy: (4-2)/2 -> 1 lesz nem pedig a 2 pont kozott.
        //const QPoint middlePoint((point2.x() - point1.x()) / 2, qrand() % (((point1.y() - point2.y()) + 1) - 1) + 1);
        qint32 new_x = (point2.x() - point1.x()) / 2 + point1.x();

        // Y kiszamitasa:
        // Meg kell hatarozni melyik szelso pont van lejjebb,
        // ahhoz hozza kell adni azt az erteket ami a pont 2 magassaga kozott van
        qint32 new_y = 0;
        qint32 high, low;
        high = low = 0;

        // Elso koordinata van feljebb
        if (point1.y() > point2.y())
        {
            high = point1.y();
            low = point2.y();
        }
        else
        {
            high = point2.y();
            low = point1.y();
        }
        // qrand() % ((High + 1) - Low) + Low)
        new_y = qrand() % ((high + 1) - low) + low ;
        const QPoint middlePoint(new_x, new_y);

		m_imagePainter->drawPoint(middlePoint);
        m_heights[middlePoint.x()] = middlePoint.y();

        generateLandScapePoints(point1, middlePoint);
        generateLandScapePoints(middlePoint, point2);
	}
}

qint32 LandScape::height(const qint32 &at) const
{
	return m_heights.at(at);
}

/*void LandScape::explodeAt(const qint32 x, const qint32 y)
{

}*/

// Csak korvonalat

void LandScape::generateLandScapeOutLine(const QPoint &point1, const QPoint &point2)
{
	//static qint32 counter=0;
	//MSG_TO_LOG() << "Counter:" << ++counter;

    if((point2.x() - point1.x()) > 1)
    {
        // X kiszamitasa:
        // Pelda: P1.x = 4 P2.x = 2 Igy: (4-2)/2 -> 1 lesz nem pedig a 2 pont kozott.
        qint32 new_x = (point2.x() - point1.x()) / 2 + point1.x();

        // Y kiszamitasa:
        // Meg kell hatarozni melyik szelso pont van lejjebb,
        // ahhoz hozza kell adni azt az erteket ami a pont 2 magassaga kozott van
        qint32 new_y = 0;
        qint32 high, low;
        high = low = 0;

        // Elso koordinata van feljebb
        if (point1.y() > point2.y())
        {
            high = point1.y();
            low = point2.y();
        }
        else
        {
            high = point2.y();
            low = point1.y();
        }
        // qrand() % ((High + 1) - Low) + Low)
        new_y = qrand() % ((high + 1) - low) + low ;
        const QPoint middlePoint(new_x, new_y);

        generateLandScapeOutLine(point1, middlePoint);
        generateLandScapeOutLine(middlePoint, point2);
    }
    else
    {
		m_imagePainter->drawLine(point1, point2);
        m_heights[point1.x()] = point1.y();
        m_heights[point2.x()] = point2.y();
    }
}

void LandScape::generateLandScape(const QPoint &point1, const QPoint &point2)
{
	//static qint32 counter=0;
	//MSG_TO_LOG() << "Counter:" << ++counter;

	if((point2.x() - point1.x()) > 1)
    {
        // X kiszamitasa:
        // Pelda: P1.x = 4 P2.x = 2 Igy: (4-2)/2 -> 1 lesz nem pedig a 2 pont kozott.
        qint32 new_x = (point2.x() - point1.x()) / 2 + point1.x();

        // Y kiszamitasa:
        // Meg kell hatarozni melyik szelso pont van lejjebb,
        // ahhoz hozza kell adni azt az erteket ami a pont 2 magassaga kozott van
        qint32 new_y = 0;
        qint32 high, low;
        high = low = 0;

        // Elso koordinata van feljebb
        if (point1.y() > point2.y())
        {
            high = point1.y();
            low = point2.y();
        }
        else
        {
            high = point2.y();
            low = point1.y();
        }

        // qrand() % ((High + 1) - Low) + Low)
        new_y = qrand() % ((high + 1) - low) + low;
        const QPoint middlePoint(new_x, new_y);

        generateLandScape(point1, middlePoint);
        generateLandScape(middlePoint, point2);
    }
    else
    {
		m_imagePainter->drawLine(point1, QPoint(point1.x(), m_height));
		m_imagePainter->drawLine(point2, QPoint(point2.x(), m_height));
        m_heights[point1.x()] = point1.y();
        m_heights[point2.x()] = point2.y();
    }
}

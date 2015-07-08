#include "game.h"
#include <QDebug>
#include "settings.h"

Game::Game(QPointer<QGraphicsScene> pScene, qint32 &width, qint32 &height, QObject *parent)
	: QObject(parent),
	  m_pScene(pScene),
	  m_width(width),
	  m_height(height)
{
    m_pScene->setSceneRect(0, 0, m_width, m_height);
    m_landScape = new LandScape(m_width, m_height);
    initialize();
}

Game::~Game()
{}

void Game::initialize()
{
	m_pScene->addItem(m_landScape);

	const qint32 unit = m_width / GROUNDSPLIT;
	for(int i = 0; i < GROUNDSPLIT; i++)
	{
		// qrand() % ((High + 1) - Low) + Low)
		qint32 prevHeight;
		if(i == 0) prevHeight = qrand() % ((MIN_MOUNTAIN_HEIGHT + 1) - MAX_MOUNTAIN_HEIGHT) + MAX_MOUNTAIN_HEIGHT;
		else prevHeight = m_landScape->height(unit * i);

		qint32 nextHeight;
		if(i == 0 || i == GROUNDSPLIT - 1 || i == GROUNDSPLIT - 2) nextHeight = qrand() % ((MIN_MOUNTAIN_HEIGHT + 1) - MAX_MOUNTAIN_HEIGHT) + MAX_MOUNTAIN_HEIGHT;
		else nextHeight = qrand() % ((m_height + 1) - 1) + 1;

		const QPoint point1 = QPoint(unit * i, prevHeight);
		const QPoint point2 = QPoint(unit * (i + 1), nextHeight);
		m_landScape->generateLandScape(point1, point2);
	}

	m_testTank = TankFactory::buildTank(10, 50, 0);
	m_pScene->addItem(m_testTank);
}

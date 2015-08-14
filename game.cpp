#include "game.h"
#include <QDebug>
#include "settings.h"

Game::Game(QPointer<QGraphicsScene> pScene, qint32 &width, qint32 &height, QObject *parent) :
	QObject(parent),
	m_pScene(pScene),
	m_landScape(0),
	m_tank1(0),
	m_tank2(0),
	m_width(width),
	m_height(height)
{
	m_pScene->setSceneRect(0, 0, m_width, m_height);
	m_landScape = new LandScape(m_width, m_height);
	initialize();
}

Game::~Game()
{
	delete m_tank1;
	delete m_tank2;
	delete m_landScape;
}

void Game::initialize()
{
	m_pScene->addItem(m_landScape);

	qint32 prevHeight = -1;
	const qint32 unit = m_width / GROUNDSPLIT;
	for(int i = 0; i < GROUNDSPLIT; i++)
	{
		qint32 leftHeight = 0;
		if (prevHeight == -1)
		{
			leftHeight = m_height - (qrand() % (MAX_MOUNTAIN_HEIGHT) + MIN_MOUNTAIN_HEIGHT);
		}
		else
		{
			leftHeight = prevHeight;
		}

		qint32 rightHeight = m_height - (qrand() % (MAX_MOUNTAIN_HEIGHT) + MIN_MOUNTAIN_HEIGHT);
		prevHeight = rightHeight;
		const QPoint point1 = QPoint(unit * i, leftHeight);
		const QPoint point2 = QPoint(unit * (i + 1), rightHeight);
		m_landScape->generateLandScape(point1, point2);
	}

	setupPlayers();
}

void Game::setupPlayers()
{
	m_tank1 = TankFactory::buildTank(TANK_DISTANCE_FROM_SIDE, m_landScape->height(TANK_DISTANCE_FROM_SIDE), PLAYER_1);

	const qint32 x = m_width - TANK_DISTANCE_FROM_SIDE;
	m_tank2 = TankFactory::buildTank(x, m_landScape->height(x), PLAYER_2);

	m_pScene->addItem(m_tank1);
	m_pScene->addItem(m_tank2);
}

void Game::p1_degreeChanged(const qint32 &value)
{
	Cannon *cannon = m_tank1->cannon();
	cannon->setDegree(value);
}

void Game::p1_gunPowderChanged(const qint32 value)
{
	Cannon *cannon = m_tank1->cannon();
	cannon->setGunPowder(value);
}

void Game::p1_shoot()
{
	changeControl(PLAYER_2);
}

void Game::p2_degreeChanged(const qint32 &value)
{
	Cannon *cannon = m_tank2->cannon();
	cannon->setDegree(value);
}

void Game::p2_gunPowderChanged(const qint32 value)
{
	Cannon *cannon = m_tank2->cannon();
	cannon->setGunPowder(value);
}

void Game::p2_shoot()
{
	changeControl(PLAYER_1);
}

#include <QDebug>
#include "game.h"
#include "mainwindow.h"
#include "settings.h"

extern MainWindow *mainWindow;

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
	connect(mainWindow, &MainWindow::p1_fire, this, &Game::p1_shoot);
	connect(mainWindow, &MainWindow::p2_fire, this, &Game::p2_shoot);

	initialize();
}

Game::~Game()
{
	//It makes "Program has unexpectedly finished", but why?
/*	delete m_tank1;
	delete m_tank2;
	delete m_landScape;*/
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
	m_tank1 = TankFactory::buildTank(TANK_DISTANCE_FROM_SIDE, m_landScape->height(TANK_DISTANCE_FROM_SIDE), Player_1);

	const qint32 x = m_width - TANK_DISTANCE_FROM_SIDE;
	m_tank2 = TankFactory::buildTank(x, m_landScape->height(x), Player_2);

	m_pScene->addItem(m_tank1);
	m_pScene->addItem(m_tank2);
}

void Game::p1_shoot()
{
	mainWindow->changeControl(Nobody);
	Bullet *bullet = m_tank1->cannon()->shoot();
	m_pCurrentBullet = bullet;
	connect(bullet, &Bullet::destroyed, this, &Game::p1_shootingFinished);
}

void Game::p2_shoot()
{
	mainWindow->changeControl(Nobody);
	Bullet *bullet = m_tank2->cannon()->shoot();
	m_pCurrentBullet = bullet;
	connect(bullet, &Bullet::destroyed, this, &Game::p2_shootingFinished);
}

void Game::p1_shootingFinished()
{
	mainWindow->changeControl(Player_2);
	disconnect(m_pCurrentBullet, &Bullet::destroyed, this, &Game::p1_shootingFinished);
}

void Game::p2_shootingFinished()
{
	mainWindow->changeControl(Player_1);
	disconnect(m_pCurrentBullet, &Bullet::destroyed, this, &Game::p2_shootingFinished);
}

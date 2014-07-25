#include "game.h"
#include <QDebug>
#include <settings.h>

Game::Game(QPointer<QGraphicsScene> pScene, QObject *parent) :
    QObject(parent)
{
    m_pScene = pScene;
    m_landScape = new LandScape;
}

Game::~Game()
{}

void Game::initialize()
{
    m_pScene->addItem(m_landScape);

    m_landScape->generateLandScape(LANDSCAPE_POINT1, LANDSCAPE_POINT2);
}

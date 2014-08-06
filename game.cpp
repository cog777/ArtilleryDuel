#include "game.h"
#include <QDebug>
#include <settings.h>

Game::Game(QPointer<QGraphicsScene> pScene, QObject *parent) :
    QObject(parent)
{
    m_pScene = pScene;
    m_pScene->setSceneRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    m_landScape = new LandScape;
}

Game::~Game()
{}

void Game::initialize()
{
    m_pScene->addItem(m_landScape);

    m_landScape->generateLandScape(LANDSCAPE_POINT1, QPoint(LANDSCAPE_XPART1, WINDOW_HEIGHT));
    m_landScape->generateLandScape(QPoint(LANDSCAPE_XPART1, m_landScape->m_heights.at(LANDSCAPE_XPART1)),
                                   QPoint(LANDSCAPE_XPART2, qrand() % ((WINDOW_HEIGHT + 1) - 1) + 1));
    m_landScape->generateLandScape(QPoint(LANDSCAPE_XPART2, m_landScape->m_heights.at(LANDSCAPE_XPART2)),
                                   QPoint(LANDSCAPE_XPART3, qrand() % ((WINDOW_HEIGHT + 1) - 1) + 1));
    m_landScape->generateLandScape(QPoint(LANDSCAPE_XPART3, m_landScape->m_heights.at(LANDSCAPE_XPART3)),
                                   LANDSCAPE_POINT2);
    // Probald ki oket
//    m_landScape->generateLandScapePoints(LANDSCAPE_POINT1, LANDSCAPE_POINT2);
//    m_landScape->generateLandScapeOutLine(LANDSCAPE_POINT1, LANDSCAPE_POINT2);
}

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

    // qrand() % ((High + 1) - Low) + Low)
    m_landScape->generateLandScape(QPoint(LANDSCAPE_XPOS1, qrand() % ((WINDOW_WIDTH + 1) - 1) + 1), QPoint(LANDSCAPE_XPOS2, qrand() % ((WINDOW_WIDTH + 1) - 1) + 1));
    m_landScape->generateLandScape(QPoint(LANDSCAPE_XPOS2, m_landScape->m_heights[LANDSCAPE_XPOS2]), QPoint(LANDSCAPE_XPOS3, qrand() % ((WINDOW_WIDTH + 1) - 1) + 1));
    m_landScape->generateLandScape(QPoint(LANDSCAPE_XPOS3, m_landScape->m_heights[LANDSCAPE_XPOS3]), QPoint(LANDSCAPE_XPOS4, qrand() % ((WINDOW_WIDTH + 1) - 1) + 1));
    m_landScape->generateLandScape(QPoint(LANDSCAPE_XPOS4, m_landScape->m_heights[LANDSCAPE_XPOS4]), QPoint(LANDSCAPE_XPOS5, qrand() % ((WINDOW_WIDTH + 1) - 1) + 1));
    // Probald ki oket
//    m_landScape->generateLandScapePoints(LANDSCAPE_POINT1, LANDSCAPE_POINT2);
//    m_landScape->generateLandScapeOutLine(LANDSCAPE_POINT1, LANDSCAPE_POINT2);
}

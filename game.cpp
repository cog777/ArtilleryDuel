#include "game.h"
#include <QDebug>
#include "settings.h"

Game::Game(QPointer<QGraphicsScene> pScene, qint32 width, qint32 height, QObject *parent) :
    QObject(parent), m_width(width), m_height(height)
{
    m_pScene = pScene;
    m_pScene->setSceneRect(0, 0, m_width, m_height);
    m_landScape = new LandScape(m_width, m_height);
    initialize();
}

Game::~Game()
{}

void Game::initialize()
{
    m_pScene->addItem(m_landScape);
    const qint32 LANDSCAPE_XPOS1 = 0;
    const qint32 LANDSCAPE_XPOS2 = m_width / 4;
    const qint32 LANDSCAPE_XPOS3 = m_width / 2;
    const qint32 LANDSCAPE_XPOS4 = LANDSCAPE_XPOS2 + LANDSCAPE_XPOS3;
    const qint32 LANDSCAPE_XPOS5 = m_width;
    // qrand() % ((High + 1) - Low) + Low)
    m_landScape->generateLandScape(QPoint(LANDSCAPE_XPOS1, qrand() % ((m_width + 1) - 1) + 1), QPoint(LANDSCAPE_XPOS2, qrand() % ((m_width + 1) - 1) + 1));
    m_landScape->generateLandScape(QPoint(LANDSCAPE_XPOS2, m_landScape->m_heights[LANDSCAPE_XPOS2]), QPoint(LANDSCAPE_XPOS3, qrand() % ((m_width + 1) - 1) + 1));
    m_landScape->generateLandScape(QPoint(LANDSCAPE_XPOS3, m_landScape->m_heights[LANDSCAPE_XPOS3]), QPoint(LANDSCAPE_XPOS4, qrand() % ((m_width + 1) - 1) + 1));
    m_landScape->generateLandScape(QPoint(LANDSCAPE_XPOS4, m_landScape->m_heights[LANDSCAPE_XPOS4]), QPoint(LANDSCAPE_XPOS5, qrand() % ((m_width + 1) - 1) + 1));
    // Probald ki oket
//    m_landScape->generateLandScapePoints(LANDSCAPE_POINT1, LANDSCAPE_POINT2);
//    m_landScape->generateLandScapeOutLine(LANDSCAPE_POINT1, LANDSCAPE_POINT2);
    m_testTank = TankFactory::buildTank(10, 50, 0);

    m_pScene->addItem(m_testTank);
}

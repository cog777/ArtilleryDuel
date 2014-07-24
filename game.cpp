#include "game.h"
#include <QDebug>

Game::Game(QPointer<QGraphicsScene> pScene, QObject *parent) :
    QObject(parent)
{
    m_pScene = pScene;
}

Game::~Game()
{}

void Game::initialize()
{}

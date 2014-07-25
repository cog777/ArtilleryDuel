#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QPointer>
#include <QGraphicsScene>
#include <landscape.h>

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QPointer<QGraphicsScene> pScene, QObject *parent = 0);
    virtual ~Game();

signals:

public slots:
    void initialize();

private:
    QPointer<QGraphicsScene> m_pScene;
    LandScape *m_landScape;
};

#endif // GAME_H

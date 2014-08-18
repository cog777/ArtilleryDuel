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
    explicit Game(QPointer<QGraphicsScene> pScene, qint32 width, qint32 height, QObject *parent = 0);
    virtual ~Game();

signals:

public slots:
    void initialize();

private:
    QPointer<QGraphicsScene> m_pScene;
    LandScape *m_landScape;
    qint32 m_width;
    qint32 m_height;
};

#endif // GAME_H

#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QPointer>
#include <QGraphicsScene>

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
};

#endif // GAME_H

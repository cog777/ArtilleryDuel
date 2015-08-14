#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QPointer>
#include <QGraphicsScene>
#include <QVector>
#include "landscape.h"
#include "tank.h"
#include "tankfactory.h"
#include "cannon.h"

class Game : public QObject
{
    Q_OBJECT
public:
	explicit Game(QPointer<QGraphicsScene> pScene, qint32 &width, qint32 &height, QObject *parent = 0);
	~Game();

signals:
	void p1_healthChanged(qint32 health);
	void p2_healthChanged(qint32 health);
	void changeControl(const qint32 &player);

public slots:
    void initialize();
	void setupPlayers();

	void p1_degreeChanged(const qint32 &value);
	void p1_gunPowderChanged(const qint32 value);
	void p1_shoot();

	void p2_degreeChanged(const qint32 &value);
	void p2_gunPowderChanged(const qint32 value);
	void p2_shoot();

private:
	void generateLandScape();
    QPointer<QGraphicsScene> m_pScene;
    LandScape *m_landScape;
	Tank *m_tank1;
	Tank *m_tank2;
    qint32 m_width;
    qint32 m_height;
};

#endif // GAME_H

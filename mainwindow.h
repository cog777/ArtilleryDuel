#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QGraphicsScene>
#include <QDateTime>
#include <QPainter>
#include <QTimer>
#include <QString>
#include "game.h"
#include "cannon.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	qint32 controlState() const;

signals:
	void p1_degreeChanged(int);
	void p2_degreeChanged(int);
	void p1_gunPowderChanged(int);
	void p2_gunPowderChanged(int);
	void p1_fire();
	void p2_fire();

public slots:
	void changeControl(const Players &player);

private slots:
	void p1_updateAngleDisplay(const int &value);
	void p2_updateAngleDisplay(const int &value);

	void initializeGUI();

	void on_exitButton_clicked();

	void on_regenerateButton_clicked();

private:
	Ui::MainWindow *ui;
	QGraphicsScene *m_scene;
	Players m_controlState;
	Game *m_game;
};

#endif // MAINWINDOW_H

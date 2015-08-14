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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

public slots:
	void changeControl(const qint32 &player);

private slots:
	void p1_degreeChanged(const qint32 value);
	void p2_degreeChanged(const qint32 value);

	void initializeGUI();

	void on_exitButton_clicked();

	void on_regenerateButton_clicked();

private:
	void connectSignalsAndSlots();

	Ui::MainWindow *ui;
	QGraphicsScene *m_scene;
	Game *m_game;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QGraphicsScene>
#include <QDateTime>
#include <QPainter>
#include <QTimer>
#include <game.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void initializeGUI();

	void on_exitButton_clicked();

	void on_pushButton_clicked();

private:
	Ui::MainWindow *ui;
	QGraphicsScene *m_scene;
	Game *m_game;
};

#endif // MAINWINDOW_H

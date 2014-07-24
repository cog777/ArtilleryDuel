#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
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

private:
    Ui::MainWindow *ui;
    QGraphicsScene *m_pScene;
    Game *m_pGame;
};

#endif // MAINWINDOW_H

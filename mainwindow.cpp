#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "settings.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qsrand(QDateTime::currentDateTime().toTime_t());

    QTimer::singleShot(0, this, SLOT(initializeGUI()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeGUI()
{
    showFullScreen();
    m_pScene = new QGraphicsScene(ui->graphicsView);
    m_pGame = new Game(m_pScene, ui->graphicsView->width(), ui->graphicsView->height(), this);

    ui->graphicsView->setScene(m_pScene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    //m_pGame->initialize();
}

void MainWindow::on_exitButton_clicked()
{
    close();
}

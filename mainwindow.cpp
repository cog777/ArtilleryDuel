#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer::singleShot(0, this, SLOT(initializeGUI()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeGUI()
{
    m_pScene = new QGraphicsScene(this);
    m_pGame = new Game(m_pScene, this);

    ui->graphicsView->setScene(m_pScene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    m_pGame->initialize();
}

void MainWindow::on_exitButton_clicked()
{
    close();
}

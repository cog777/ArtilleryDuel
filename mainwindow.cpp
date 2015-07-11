#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "settings.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	m_scene(0),
	m_game(0)
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
	m_scene = new QGraphicsScene(ui->graphicsView);
	on_pushButton_clicked();

	ui->graphicsView->setScene(m_scene);
	ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

void MainWindow::on_exitButton_clicked()
{
	QApplication::exit(0);
}

void MainWindow::on_pushButton_clicked()
{
	if (!m_game) delete m_game;
	m_scene->clear();

	qint32 width = ui->graphicsView->width() - 10;
	qint32 height = ui->graphicsView->height() - 10;
	m_game = new Game(m_scene, width, height, this);
}

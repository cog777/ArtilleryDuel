#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "settings.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	m_scene(0),
	m_game(0)
{
	ui->setupUi(this);

	qsrand(QDateTime::currentDateTime().toTime_t());
	QTimer::singleShot(0, this, SLOT(initializeGUI()));
	ui->p1_angleSlider->setMinimum(MIN_DEGREE);
	ui->p1_angleSlider->setMaximum(MAX_DEGREE);
	ui->p2_angleSlider->setMinimum(MIN_DEGREE);
	ui->p2_angleSlider->setMaximum(MAX_DEGREE);

	connect(ui->p1_angleSlider, SIGNAL(valueChanged(int)), this, SLOT(p1_degreeChanged(qint32)));
	connect(ui->p2_angleSlider, SIGNAL(valueChanged(int)), this, SLOT(p2_degreeChanged(qint32)));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::changeControl(const qint32 &player)
{
	switch(player)
	{
		case PLAYER_1:
			ui->p1_controlBox->setEnabled(true);
			ui->p2_controlBox->setEnabled(false);
		break;

		case PLAYER_2:
			ui->p1_controlBox->setEnabled(false);
			ui->p2_controlBox->setEnabled(true);
		break;

		case PLAYER_NOBODY:
			ui->p1_controlBox->setEnabled(false);
			ui->p2_controlBox->setEnabled(false);
		break;
	}
}

void MainWindow::p1_degreeChanged(const qint32 value)
{
	ui->p1_angleDisplay->setText(QString::number(value) + "°");
	m_game->p1_degreeChanged(value);
}

void MainWindow::p2_degreeChanged(const qint32 value)
{
	ui->p2_angleDisplay->setText(QString::number(value) + "°");
	m_game->p2_degreeChanged(value);
}

void MainWindow::initializeGUI()
{
	showFullScreen();
	m_scene = new QGraphicsScene(ui->graphicsView);
	on_regenerateButton_clicked();

	ui->graphicsView->setScene(m_scene);
	ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

void MainWindow::on_exitButton_clicked()
{
	QApplication::exit(0);
}

void MainWindow::on_regenerateButton_clicked()
{
	if(m_game) delete m_game;
	m_scene->clear();

	qint32 width = ui->graphicsView->width() - 10;
	qint32 height = ui->graphicsView->height() - 10;
	m_game = new Game(m_scene, width, height, this);
	connectSignalsAndSlots();
	changeControl(PLAYER_1);
}

void MainWindow::connectSignalsAndSlots()
{
	connect(ui->p1_gunPowder, SIGNAL(valueChanged(int)), m_game, SLOT(p1_gunPowderChanged(const qint32)));
	connect(m_game, SIGNAL(p1_healthChanged(qint32)), ui->p1_healthDisplay, SLOT(display(int)));
	connect(ui->p1_fireButton, SIGNAL(clicked()), m_game, SLOT(p1_shoot()));

	connect(ui->p2_gunPowder, SIGNAL(valueChanged(int)), m_game, SLOT(p2_gunPowderChanged(const qint32)));
	connect(m_game, SIGNAL(p2_healthChanged(qint32)), ui->p2_healthDisplay, SLOT(display(int)));
	connect(ui->p2_fireButton, SIGNAL(clicked()), m_game, SLOT(p2_shoot()));

	connect(m_game, SIGNAL(changeControl(qint32)), this, SLOT(changeControl(qint32)));
}

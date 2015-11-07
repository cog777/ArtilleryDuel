#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings.h"
#include <QDebug>

MainWindow *mainWindow;

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	m_scene(0),
	m_controlState(Nobody),
	m_game(0)
{
	ui->setupUi(this);
	mainWindow = this;

	showFullScreen();
	qsrand(QDateTime::currentDateTime().toTime_t());
	QTimer::singleShot(500, this, SLOT(initializeGUI()));
	ui->p1_angleSlider->setMinimum(CANNON_MIN_DEGREE);
	ui->p1_angleSlider->setMaximum(CANNON_MAX_DEGREE);
	ui->p2_angleSlider->setMinimum(CANNON_MIN_DEGREE);
	ui->p2_angleSlider->setMaximum(CANNON_MAX_DEGREE);
	ui->p1_gPowderSlider->setMinimum(CANNON_MIN_GUNPOWDER);
	ui->p1_gPowderSlider->setMaximum(CANNON_MAX_GUNPOWDER);
	ui->p2_gPowderSlider->setMinimum(CANNON_MIN_GUNPOWDER);
	ui->p2_gPowderSlider->setMaximum(CANNON_MAX_GUNPOWDER);

	connect(ui->p1_angleSlider, SIGNAL(valueChanged(int)), this, SLOT(p1_updateAngleDisplay(int)));
	connect(ui->p2_angleSlider, SIGNAL(valueChanged(int)), this, SLOT(p2_updateAngleDisplay(int)));

	connect(ui->p1_gPowderSlider, SIGNAL(valueChanged(int)), this, SIGNAL(p1_gunPowderChanged(int)));
	connect(ui->p2_gPowderSlider, SIGNAL(valueChanged(int)), this, SIGNAL(p2_gunPowderChanged(int)));
	connect(ui->p1_fireButton, SIGNAL(clicked()), this, SIGNAL(p1_fire()));
	connect(ui->p2_fireButton, SIGNAL(clicked()), this, SIGNAL(p2_fire()));
}

MainWindow::~MainWindow()
{
	delete ui;
}

qint32 MainWindow::controlState() const
{
	return m_controlState;
}

void MainWindow::changeControl(const Players &player)
{
	switch(player)
	{
		case Player_1:
			ui->p1_controlBox->setEnabled(true);
			ui->p2_controlBox->setEnabled(false);
			m_controlState = Player_1;
		break;

		case Player_2:
			ui->p1_controlBox->setEnabled(false);
			ui->p2_controlBox->setEnabled(true);
			m_controlState = Player_2;
		break;

		case Nobody:
			ui->p1_controlBox->setEnabled(false);
			ui->p2_controlBox->setEnabled(false);
			m_controlState = Nobody;
		break;
	}
}

void MainWindow::p1_updateAngleDisplay(const int &value)
{
	ui->p1_angleDisplay->setText(QString::number(value) + "°");
	p1_degreeChanged(value);
}

void MainWindow::p2_updateAngleDisplay(const int &value)
{
	ui->p2_angleDisplay->setText(QString::number(value) + "°");
	p2_degreeChanged(value);
}

void MainWindow::initializeGUI()
{
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
	m_scene->setSceneRect(0, 0, width, height);
	m_game = new Game(m_scene, width, height, this);
	changeControl(Player_1);
}

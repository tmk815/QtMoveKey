#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTime>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    QTimer *timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    timer->start(10);

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{

    QColor red(255,0,0);

    QPainter people(this);

    people.setRenderHint(QPainter::Antialiasing);

    people.setPen(Qt::NoPen);

    people.setBrush(red);
    people.setPen(red);

    //people.save();

    people.translate(50,50);

    people.drawEllipse(posx,posy,50,50);

    //people.restore();
}

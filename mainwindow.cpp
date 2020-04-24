#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <math.h>
#include <QWheelEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    centerX = 150;
    centerY = 150;
    factor = 1.0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::red));

    painter.drawEllipse(centerX,centerY,50*factor,50*factor);

}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    double numDegrees = event->delta() / 8.0;
    double numSteps = numDegrees / 15.0;
    factor *= pow(1.1, numSteps);
    if (factor < 0.07)
        factor = 0.07;
    if(factor > 50)
        factor = 50;

    qDebug() << factor << numDegrees << numSteps << event->delta();
    update();

}

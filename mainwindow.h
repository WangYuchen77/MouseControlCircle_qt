#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent *event);
    void wheelEvent(QWheelEvent *event);



private:
    Ui::MainWindow *ui;


    double centerX;
    double centerY;
    double factor;
};

#endif // MAINWINDOW_H

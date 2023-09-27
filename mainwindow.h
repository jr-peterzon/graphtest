#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "timeplot.h"
#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_tick();

private:
    Ui::MainWindow *ui;
    TimePlot *plot;
    QTimer *tmr;
};
#endif // MAINWINDOW_H

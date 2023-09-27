#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    plot = new TimePlot();
    ui->timeplot->setScene(plot);
    ui->timeplot->setViewportUpdateMode(QGraphicsView::NoViewportUpdate);
    tmr = new QTimer(this);
    QObject::connect(tmr, SIGNAL(timeout()), this, SLOT(on_tick()));
    tmr->start(50);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tick()
{
    if (plot) {
        plot->randomize();
        QList<
        QRectF> r;
        r.append(plot->sceneRect());
        ui->timeplot->viewport()->update();
    }
}


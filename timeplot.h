#ifndef TIMEPLOT_H
#define TIMEPLOT_H

#include <QGraphicsScene>
#include <QObject>
#include <QLineF>
#include <QGraphicsLineItem>

class TimePlot : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit TimePlot(QObject *parent = nullptr);
    void randomize();
private:
    qreal values[4][101];
    uint64_t timestamps[100];
    QLineF lines[100];
    QGraphicsLineItem * line_GI[100];
    int index=0;
};

#endif // TIMEPLOT_H

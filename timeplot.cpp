#include "timeplot.h"

TimePlot::TimePlot(QObject *parent)
    : QGraphicsScene{parent}
{
    qreal xstart=0.0;
    qreal dx = 5.0;
    qreal y = 100.0;
    for (int i=0;i<100;i++){
        values[0][i]=y;
        qreal nextx=xstart+dx;

        int yoff = (rand()&255);
        qreal nexty = 100.0 + (qreal)yoff/25.5;



        lines[i].setLine(xstart,y,nextx,nexty);
        xstart=nextx;
        y=nexty;
        line_GI[i]=addLine(lines[i]);
    }
    values[0][100]=y;
}

void TimePlot::randomize()
{
    index = (index+1)%101;
    qreal xstart=0.0;
    qreal dx = 5.0;

    for (int i=0;i<100;i+=1){
        int off = (i+index)%101;
        int nextoff = (i+index+1)%101;
        qreal nextx=xstart+dx;
        line_GI[i]->setLine(xstart,values[0][off],nextx,values[0][nextoff]);
        xstart=nextx;
    }
}

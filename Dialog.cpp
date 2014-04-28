#include "Dialog.h"
#include "ui_Dialog.h"
#include <qwt_plot_grid.h>
#include <qwt_plot_curve.h>
#include "Simulation.h"

Dialog::Dialog( QWidget *parent ) :
QDialog( parent ),
ui( new Ui::Dialog ) {
    ui->setupUi( this );
    ui->plot->setAxisScale( QwtPlot::yLeft, 0.0, 50.0 );
    ui->plot->setAxisScale( QwtPlot::xBottom, 0.0, 300.0 );

    QwtPlotGrid *grid = new QwtPlotGrid;
    grid->setPen( QColor( 150, 150, 0 ) );
    grid->attach( ui->plot );

    QwtPlotCurve *curve = new QwtPlotCurve;

    QPolygonF points;
    Simulation s;
    s.getData( points );

    curve->setSamples( points );
    curve->attach( ui->plot );
}

Dialog::~Dialog( ) {
    delete ui;
}

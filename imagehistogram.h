#ifndef IMAGEHISTOGRAM_H
#define IMAGEHISTOGRAM_H

#include <QWidget>
#include <QtCharts/QBarSet>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarSeries>

class ImageHistogram : public QWidget
{
	Q_OBJECT
public:
	explicit ImageHistogram(QWidget *parent = nullptr);
signals:

private:
	QList<int> pixelsDataSet;
	QBarSet *barSet;
	QBarSeries *series;
	QChart *chart;
	QValueAxis *axisY;
	QChartView *chartView;

private slots:
	void slotSetPixelsData(QList<QColor> pixelData);
};

#endif // IMAGEHISTOGRAM_H

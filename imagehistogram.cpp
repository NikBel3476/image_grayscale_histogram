#include "imagehistogram.h"

#include <QGridLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarSet>

ImageHistogram::ImageHistogram(QWidget *parent)
	: QWidget{parent}
{
	barSet = new QBarSet("Histogram");
	for (int i = 0; i < 256; i++) {
		*barSet << 0;
		pixelsDataSet.append(0);
	}

	series = new QBarSeries();
	series->append(barSet);

	chart = new QChart();
	chart->setTitle("Grayscale image histogram");
	chart->addSeries(series);
	chart->legend()->hide();
	chart->setAnimationOptions(QChart::SeriesAnimations);

	QValueAxis *axisX = new QValueAxis();
	axisX->setRange(0, 255);
	axisX->setLabelFormat("%d");
	chart->addAxis(axisX, Qt::AlignBottom);
	series->attachAxis(axisX);

	axisY = new QValueAxis();
	axisY->setRange(0, *std::max_element(pixelsDataSet.begin(), pixelsDataSet.end()));
	axisY->setLabelFormat("%d");
	chart->addAxis(axisY, Qt::AlignLeft);
	series->attachAxis(axisY);

	chartView = new QChartView(chart);
	chartView->setRenderHint(QPainter::Antialiasing);

	QGridLayout *layout = new QGridLayout(this);
	layout->addWidget(chartView);
}

void ImageHistogram::slotSetPixelsData(QList<QColor> pixelsData) {
	int pixelsBarSet[256] = { 0 };

	for (int i = 0; i < pixelsData.count(); i++) {
		pixelsBarSet[pixelsData[i].red()]++; // red, green and blue are equal
	}

	QBarSet *newBarSet = new QBarSet("Histogram");
	for (int i = 0; i < 256; i++) {
		*newBarSet << pixelsBarSet[i];
		pixelsDataSet[i] = pixelsBarSet[i];
	}

	axisY->setMax(*std::max_element(pixelsDataSet.begin(), pixelsDataSet.end()));
	series->clear();
	series->append(newBarSet);
}

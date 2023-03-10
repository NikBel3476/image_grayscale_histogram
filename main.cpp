#include "imagehistogram.h"
#include "window.h"
#include "imageviewer.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QPushButton>
#include <QCommandLineParser>
#include <QProgressBar>
#include <QSlider>
#include <QtWidgets/QGridLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarCategoryAxis>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QTranslator translator;
	const QStringList uiLanguages = QLocale::system().uiLanguages();
	for (const QString &locale : uiLanguages) {
		const QString baseName = "qtHistogram_" + QLocale(locale).name();
		if (translator.load(":/i18n/" + baseName)) {
			app.installTranslator(&translator);
			break;
		}
	}

	// Create a container window
	Window window;
	window.setMinimumSize(800, 400);

	// Image viewer
	QCommandLineParser commandLineParser;
	commandLineParser.addHelpOption();
	commandLineParser.addPositionalArgument(ImageViewer::tr("[file]"), ImageViewer::tr("Image file to open."));
	commandLineParser.process(QCoreApplication::arguments());
	ImageViewer imageViewer;
	if (!commandLineParser.positionalArguments().isEmpty()
			&& !imageViewer.loadFile(commandLineParser.positionalArguments().constFirst())) {
			return -1;
	}

	// histogram
	ImageHistogram *imageHistogram = new ImageHistogram();

	QGridLayout *gridLayout = new QGridLayout(&window);
	gridLayout->setContentsMargins(0, 0, 0, 0);
	gridLayout->addWidget(&imageViewer, 0, 0);
	gridLayout->addWidget(imageHistogram, 0, 1);

	window.showMaximized();

	// Connection
	QObject::connect(&imageViewer, SIGNAL (imageLoaded(QList<QColor>)), imageHistogram, SLOT (slotSetPixelsData(QList<QColor>)));

	return app.exec();
}

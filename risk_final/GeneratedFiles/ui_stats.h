/********************************************************************************
** Form generated from reading UI file 'stats.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATS_H
#define UI_STATS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_statsGui
{
public:
    QTextBrowser *textBrowser;
    QTextBrowser *all_stats;
    QTextBrowser *Info;
    QComboBox *chosenStats;
    QComboBox *chosenStats_2;
    QTextBrowser *Info_2;

    void setupUi(QWidget *statsGui)
    {
        if (statsGui->objectName().isEmpty())
            statsGui->setObjectName(QStringLiteral("statsGui"));
        statsGui->resize(668, 682);
        textBrowser = new QTextBrowser(statsGui);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(90, 30, 501, 51));
        all_stats = new QTextBrowser(statsGui);
        all_stats->setObjectName(QStringLiteral("all_stats"));
        all_stats->setGeometry(QRect(100, 390, 491, 51));
        Info = new QTextBrowser(statsGui);
        Info->setObjectName(QStringLiteral("Info"));
        Info->setGeometry(QRect(100, 130, 491, 51));
        chosenStats = new QComboBox(statsGui);
        chosenStats->setObjectName(QStringLiteral("chosenStats"));
        chosenStats->setGeometry(QRect(410, 100, 181, 22));
        chosenStats_2 = new QComboBox(statsGui);
        chosenStats_2->setObjectName(QStringLiteral("chosenStats_2"));
        chosenStats_2->setGeometry(QRect(410, 190, 181, 22));
        Info_2 = new QTextBrowser(statsGui);
        Info_2->setObjectName(QStringLiteral("Info_2"));
        Info_2->setGeometry(QRect(100, 230, 491, 121));

        retranslateUi(statsGui);
        QObject::connect(chosenStats, SIGNAL(activated(int)), statsGui, SLOT(spin(int)));
        QObject::connect(chosenStats_2, SIGNAL(activated(int)), statsGui, SLOT(player_stats(int)));

        QMetaObject::connectSlotsByName(statsGui);
    } // setupUi

    void retranslateUi(QWidget *statsGui)
    {
        statsGui->setWindowTitle(QApplication::translate("statsGui", "Form", 0));
        textBrowser->setHtml(QApplication::translate("statsGui", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; font-weight:600; color:#55aa00;\">welcome to statistics zone</span></p></body></html>", 0));
        all_stats->setHtml(QApplication::translate("statsGui", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        Info->setHtml(QApplication::translate("statsGui", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#55aa00;\">genreral statistics</span></p></body></html>", 0));
        chosenStats->clear();
        chosenStats->insertItems(0, QStringList()
         << QApplication::translate("statsGui", "maxWins", 0)
         << QApplication::translate("statsGui", "maxLooses", 0)
         << QApplication::translate("statsGui", "maxGamePlayed", 0)
         << QApplication::translate("statsGui", "maxTimePlayed", 0)
        );
        chosenStats->setCurrentText(QApplication::translate("statsGui", "maxWins", 0));
        chosenStats_2->setCurrentText(QString());
        Info_2->setHtml(QApplication::translate("statsGui", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#55aa00;\">players stats</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class statsGui: public Ui_statsGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATS_H

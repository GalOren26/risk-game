/********************************************************************************
** Form generated from reading UI file 'move.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVE_H
#define UI_MOVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Move
{
public:
    QGroupBox *TROOPS;
    QPushButton *MINUS;
    QPushButton *PLUS;
    QTextEdit *troopsP;
    QPushButton *ENTER;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *Move)
    {
        if (Move->objectName().isEmpty())
            Move->setObjectName(QStringLiteral("Move"));
        Move->resize(452, 402);
        TROOPS = new QGroupBox(Move);
        TROOPS->setObjectName(QStringLiteral("TROOPS"));
        TROOPS->setGeometry(QRect(140, 160, 171, 161));
        MINUS = new QPushButton(TROOPS);
        MINUS->setObjectName(QStringLiteral("MINUS"));
        MINUS->setGeometry(QRect(10, 103, 71, 51));
        MINUS->setStyleSheet(QStringLiteral("border-image:url(:/new/Resources/minus.png)"));
        PLUS = new QPushButton(TROOPS);
        PLUS->setObjectName(QStringLiteral("PLUS"));
        PLUS->setGeometry(QRect(90, 103, 71, 51));
        PLUS->setStyleSheet(QStringLiteral("border-image:url(:/new/Resources/plus.png)"));
        troopsP = new QTextEdit(TROOPS);
        troopsP->setObjectName(QStringLiteral("troopsP"));
        troopsP->setGeometry(QRect(40, 20, 91, 71));
        QFont font;
        font.setFamily(QStringLiteral("Rockwell Condensed"));
        font.setPointSize(26);
        font.setBold(true);
        font.setWeight(75);
        troopsP->setFont(font);
        troopsP->setStyleSheet(QStringLiteral("background-color:\"gray\""));
        ENTER = new QPushButton(Move);
        ENTER->setObjectName(QStringLiteral("ENTER"));
        ENTER->setGeometry(QRect(190, 350, 75, 23));
        ENTER->setCursor(QCursor(Qt::PointingHandCursor));
        ENTER->setStyleSheet(QStringLiteral("background-color:\"green\""));
        textBrowser = new QTextBrowser(Move);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(100, 40, 256, 101));

        retranslateUi(Move);
        QObject::connect(PLUS, SIGNAL(clicked()), Move, SLOT(plus()));
        QObject::connect(MINUS, SIGNAL(clicked()), Move, SLOT(minus()));
        QObject::connect(ENTER, SIGNAL(clicked()), Move, SLOT(end()));

        QMetaObject::connectSlotsByName(Move);
    } // setupUi

    void retranslateUi(QWidget *Move)
    {
        Move->setWindowTitle(QApplication::translate("Move", "Form", 0));
        TROOPS->setTitle(QString());
        MINUS->setText(QString());
        MINUS->setShortcut(QApplication::translate("Move", "-", 0));
        PLUS->setText(QString());
        PLUS->setShortcut(QApplication::translate("Move", "+", 0));
        troopsP->setHtml(QApplication::translate("Move", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Rockwell Condensed'; font-size:26pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt; font-weight:400;\">12</span></p></body></html>", 0));
        ENTER->setText(QApplication::translate("Move", "ENTER", 0));
        textBrowser->setHtml(QApplication::translate("Move", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:9.75pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; font-weight:600; color:#55aa00;\">Please enter number of Troops to transper</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class Move: public Ui_Move {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVE_H

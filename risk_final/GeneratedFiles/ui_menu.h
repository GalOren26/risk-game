/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QPushButton *LOAD;
    QPushButton *cube;
    QGroupBox *groupBox1;
    QTextEdit *nameP1;
    QLabel *label;
    QLabel *label_2;
    QComboBox *colorP1;
    QLabel *cubeP1;
    QLabel *pic1_ord;
    QLabel *label_3;
    QTextEdit *idP1;
    QGroupBox *groupBox2;
    QTextEdit *nameP2;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *colorP2;
    QLabel *cubeP2;
    QLabel *pic2_ord;
    QTextEdit *idP2;
    QLabel *label_4;
    QGroupBox *groupBox3;
    QTextEdit *nameP3;
    QLabel *label_9;
    QLabel *label_10;
    QComboBox *colorP3;
    QLabel *cubeP3;
    QLabel *pic3_ord;
    QLabel *label_7;
    QTextEdit *idP3;
    QGroupBox *groupBox4;
    QTextEdit *nameP4;
    QLabel *label_11;
    QLabel *label_12;
    QComboBox *colorP4;
    QLabel *cubeP4;
    QLabel *pic4_ord;
    QTextEdit *idP4;
    QLabel *label_8;
    QSpinBox *spinBox;
    QPushButton *FINISH;
    QLabel *order;
    QLabel *text;
    QLabel *info;
    QLabel *label_41;
    QPushButton *loadStats;
    QPushButton *defalutStatsB;

    void setupUi(QWidget *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QStringLiteral("menu"));
        menu->resize(890, 852);
        menu->setStyleSheet(QStringLiteral("background-image: url(':/risk-menu')"));
        LOAD = new QPushButton(menu);
        LOAD->setObjectName(QStringLiteral("LOAD"));
        LOAD->setGeometry(QRect(780, 300, 91, 23));
        cube = new QPushButton(menu);
        cube->setObjectName(QStringLiteral("cube"));
        cube->setGeometry(QRect(600, 110, 75, 23));
        groupBox1 = new QGroupBox(menu);
        groupBox1->setObjectName(QStringLiteral("groupBox1"));
        groupBox1->setGeometry(QRect(130, 140, 541, 111));
        groupBox1->setStyleSheet(QStringLiteral("background-color:\"white\""));
        nameP1 = new QTextEdit(groupBox1);
        nameP1->setObjectName(QStringLiteral("nameP1"));
        nameP1->setGeometry(QRect(110, 20, 181, 21));
        label = new QLabel(groupBox1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 61, 21));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label_2 = new QLabel(groupBox1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 80, 61, 21));
        label_2->setFont(font);
        colorP1 = new QComboBox(groupBox1);
        colorP1->setObjectName(QStringLiteral("colorP1"));
        colorP1->setGeometry(QRect(110, 80, 181, 22));
        cubeP1 = new QLabel(groupBox1);
        cubeP1->setObjectName(QStringLiteral("cubeP1"));
        cubeP1->setGeometry(QRect(450, 40, 91, 51));
        pic1_ord = new QLabel(groupBox1);
        pic1_ord->setObjectName(QStringLiteral("pic1_ord"));
        pic1_ord->setGeometry(QRect(360, 50, 51, 31));
        QFont font1;
        font1.setPointSize(14);
        pic1_ord->setFont(font1);
        label_3 = new QLabel(groupBox1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 50, 61, 21));
        label_3->setFont(font);
        idP1 = new QTextEdit(groupBox1);
        idP1->setObjectName(QStringLiteral("idP1"));
        idP1->setGeometry(QRect(110, 50, 181, 21));
        groupBox2 = new QGroupBox(menu);
        groupBox2->setObjectName(QStringLiteral("groupBox2"));
        groupBox2->setGeometry(QRect(130, 280, 541, 111));
        groupBox2->setStyleSheet(QStringLiteral("background-color:\"white\""));
        nameP2 = new QTextEdit(groupBox2);
        nameP2->setObjectName(QStringLiteral("nameP2"));
        nameP2->setGeometry(QRect(110, 20, 181, 21));
        label_5 = new QLabel(groupBox2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 20, 61, 21));
        label_5->setFont(font);
        label_6 = new QLabel(groupBox2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 80, 61, 21));
        label_6->setFont(font);
        colorP2 = new QComboBox(groupBox2);
        colorP2->setObjectName(QStringLiteral("colorP2"));
        colorP2->setGeometry(QRect(108, 80, 181, 22));
        cubeP2 = new QLabel(groupBox2);
        cubeP2->setObjectName(QStringLiteral("cubeP2"));
        cubeP2->setGeometry(QRect(440, 30, 81, 51));
        pic2_ord = new QLabel(groupBox2);
        pic2_ord->setObjectName(QStringLiteral("pic2_ord"));
        pic2_ord->setGeometry(QRect(360, 40, 51, 31));
        pic2_ord->setFont(font1);
        idP2 = new QTextEdit(groupBox2);
        idP2->setObjectName(QStringLiteral("idP2"));
        idP2->setGeometry(QRect(110, 50, 181, 21));
        label_4 = new QLabel(groupBox2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 50, 61, 21));
        label_4->setFont(font);
        groupBox3 = new QGroupBox(menu);
        groupBox3->setObjectName(QStringLiteral("groupBox3"));
        groupBox3->setGeometry(QRect(130, 420, 531, 111));
        groupBox3->setStyleSheet(QStringLiteral("background-color:\"white\""));
        nameP3 = new QTextEdit(groupBox3);
        nameP3->setObjectName(QStringLiteral("nameP3"));
        nameP3->setGeometry(QRect(110, 20, 181, 21));
        label_9 = new QLabel(groupBox3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 20, 61, 21));
        label_9->setFont(font);
        label_10 = new QLabel(groupBox3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 80, 61, 21));
        label_10->setFont(font);
        colorP3 = new QComboBox(groupBox3);
        colorP3->setObjectName(QStringLiteral("colorP3"));
        colorP3->setGeometry(QRect(108, 80, 181, 22));
        cubeP3 = new QLabel(groupBox3);
        cubeP3->setObjectName(QStringLiteral("cubeP3"));
        cubeP3->setGeometry(QRect(440, 30, 81, 51));
        pic3_ord = new QLabel(groupBox3);
        pic3_ord->setObjectName(QStringLiteral("pic3_ord"));
        pic3_ord->setGeometry(QRect(360, 40, 51, 31));
        pic3_ord->setFont(font1);
        label_7 = new QLabel(groupBox3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 50, 61, 21));
        label_7->setFont(font);
        idP3 = new QTextEdit(groupBox3);
        idP3->setObjectName(QStringLiteral("idP3"));
        idP3->setGeometry(QRect(110, 50, 181, 21));
        groupBox4 = new QGroupBox(menu);
        groupBox4->setObjectName(QStringLiteral("groupBox4"));
        groupBox4->setGeometry(QRect(130, 560, 531, 111));
        groupBox4->setStyleSheet(QStringLiteral("background-color:\"white\""));
        nameP4 = new QTextEdit(groupBox4);
        nameP4->setObjectName(QStringLiteral("nameP4"));
        nameP4->setGeometry(QRect(110, 20, 181, 21));
        label_11 = new QLabel(groupBox4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 20, 61, 21));
        label_11->setFont(font);
        label_12 = new QLabel(groupBox4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(30, 80, 61, 21));
        label_12->setFont(font);
        colorP4 = new QComboBox(groupBox4);
        colorP4->setObjectName(QStringLiteral("colorP4"));
        colorP4->setGeometry(QRect(108, 80, 181, 22));
        cubeP4 = new QLabel(groupBox4);
        cubeP4->setObjectName(QStringLiteral("cubeP4"));
        cubeP4->setGeometry(QRect(420, 30, 91, 51));
        pic4_ord = new QLabel(groupBox4);
        pic4_ord->setObjectName(QStringLiteral("pic4_ord"));
        pic4_ord->setGeometry(QRect(350, 40, 51, 31));
        pic4_ord->setFont(font1);
        idP4 = new QTextEdit(groupBox4);
        idP4->setObjectName(QStringLiteral("idP4"));
        idP4->setGeometry(QRect(110, 50, 181, 21));
        label_8 = new QLabel(groupBox4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 50, 61, 21));
        label_8->setFont(font);
        spinBox = new QSpinBox(menu);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(300, 80, 71, 22));
        spinBox->setMinimum(2);
        spinBox->setMaximum(4);
        spinBox->setValue(4);
        FINISH = new QPushButton(menu);
        FINISH->setObjectName(QStringLiteral("FINISH"));
        FINISH->setGeometry(QRect(710, 760, 131, 23));
        order = new QLabel(menu);
        order->setObjectName(QStringLiteral("order"));
        order->setGeometry(QRect(490, 120, 51, 31));
        order->setFont(font);
        text = new QLabel(menu);
        text->setObjectName(QStringLiteral("text"));
        text->setGeometry(QRect(160, 70, 131, 31));
        text->setFont(font);
        text->setStyleSheet(QStringLiteral("color:\"white\""));
        info = new QLabel(menu);
        info->setObjectName(QStringLiteral("info"));
        info->setGeometry(QRect(100, 750, 381, 71));
        info->setFont(font1);
        label_41 = new QLabel(menu);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setGeometry(QRect(0, 0, 891, 851));
        label_41->setPixmap(QPixmap(QString::fromUtf8(":/new/Resources/backg.bmp")));
        label_41->setScaledContents(true);
        loadStats = new QPushButton(menu);
        loadStats->setObjectName(QStringLiteral("loadStats"));
        loadStats->setGeometry(QRect(780, 270, 91, 23));
        defalutStatsB = new QPushButton(menu);
        defalutStatsB->setObjectName(QStringLiteral("defalutStatsB"));
        defalutStatsB->setGeometry(QRect(780, 240, 91, 23));
        label_41->raise();
        LOAD->raise();
        cube->raise();
        groupBox1->raise();
        groupBox2->raise();
        groupBox3->raise();
        groupBox4->raise();
        spinBox->raise();
        FINISH->raise();
        order->raise();
        text->raise();
        info->raise();
        loadStats->raise();
        defalutStatsB->raise();

        retranslateUi(menu);
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), menu, SLOT(spin(int)));
        QObject::connect(defalutStatsB, SIGNAL(clicked()), menu, SLOT(defalutStats()));

        colorP3->setCurrentIndex(0);
        colorP4->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QWidget *menu)
    {
        menu->setWindowTitle(QApplication::translate("menu", "menu", 0));
        LOAD->setText(QApplication::translate("menu", "load", 0));
        cube->setText(QApplication::translate("menu", "cube", 0));
        groupBox1->setTitle(QApplication::translate("menu", "player 1", 0));
        nameP1->setHtml(QApplication::translate("menu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">player1</p></body></html>", 0));
        label->setText(QApplication::translate("menu", "name:", 0));
        label_2->setText(QApplication::translate("menu", "color:", 0));
        colorP1->clear();
        colorP1->insertItems(0, QStringList()
         << QApplication::translate("menu", "red", 0)
         << QApplication::translate("menu", "green", 0)
         << QApplication::translate("menu", "cyan", 0)
         << QApplication::translate("menu", "yellow", 0)
         << QApplication::translate("menu", "blue", 0)
        );
        cubeP1->setText(QApplication::translate("menu", "TextLabel", 0));
        pic1_ord->setText(QApplication::translate("menu", "order", 0));
        label_3->setText(QApplication::translate("menu", "id:", 0));
        idP1->setHtml(QApplication::translate("menu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1234</p></body></html>", 0));
        groupBox2->setTitle(QApplication::translate("menu", "player 2", 0));
        nameP2->setHtml(QApplication::translate("menu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">player2</p></body></html>", 0));
        label_5->setText(QApplication::translate("menu", "name:", 0));
        label_6->setText(QApplication::translate("menu", "color:", 0));
        colorP2->clear();
        colorP2->insertItems(0, QStringList()
         << QApplication::translate("menu", "red", 0)
         << QApplication::translate("menu", "green", 0)
         << QApplication::translate("menu", "cyan", 0)
         << QApplication::translate("menu", "yellow", 0)
         << QApplication::translate("menu", "blue", 0)
        );
        colorP2->setCurrentText(QApplication::translate("menu", "red", 0));
        cubeP2->setText(QApplication::translate("menu", "TextLabel", 0));
        pic2_ord->setText(QApplication::translate("menu", "order", 0));
        idP2->setHtml(QApplication::translate("menu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">5678</p></body></html>", 0));
        label_4->setText(QApplication::translate("menu", "id:", 0));
        groupBox3->setTitle(QApplication::translate("menu", "player 3", 0));
        nameP3->setHtml(QApplication::translate("menu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">player3</p></body></html>", 0));
        label_9->setText(QApplication::translate("menu", "name:", 0));
        label_10->setText(QApplication::translate("menu", "color:", 0));
        colorP3->clear();
        colorP3->insertItems(0, QStringList()
         << QApplication::translate("menu", "red", 0)
         << QApplication::translate("menu", "green", 0)
         << QApplication::translate("menu", "cyan", 0)
         << QApplication::translate("menu", "yellow", 0)
         << QApplication::translate("menu", "blue", 0)
        );
        colorP3->setCurrentText(QApplication::translate("menu", "red", 0));
        cubeP3->setText(QApplication::translate("menu", "TextLabel", 0));
        pic3_ord->setText(QApplication::translate("menu", "order", 0));
        label_7->setText(QApplication::translate("menu", "id:", 0));
        idP3->setHtml(QApplication::translate("menu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">2468</p></body></html>", 0));
        groupBox4->setTitle(QApplication::translate("menu", "player 4", 0));
        nameP4->setHtml(QApplication::translate("menu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">player4</p></body></html>", 0));
        label_11->setText(QApplication::translate("menu", "name:", 0));
        label_12->setText(QApplication::translate("menu", "color:", 0));
        colorP4->clear();
        colorP4->insertItems(0, QStringList()
         << QApplication::translate("menu", "red", 0)
         << QApplication::translate("menu", "green", 0)
         << QApplication::translate("menu", "cyan", 0)
         << QApplication::translate("menu", "yellow", 0)
         << QApplication::translate("menu", "blue", 0)
        );
        colorP4->setCurrentText(QApplication::translate("menu", "red", 0));
        cubeP4->setText(QApplication::translate("menu", "TextLabel", 0));
        pic4_ord->setText(QApplication::translate("menu", "order", 0));
        idP4->setHtml(QApplication::translate("menu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1357</p></body></html>", 0));
        label_8->setText(QApplication::translate("menu", "id:", 0));
        FINISH->setText(QApplication::translate("menu", "START THE GAME! ", 0));
        order->setText(QString());
        text->setText(QApplication::translate("menu", "# of players", 0));
        info->setText(QString());
        label_41->setText(QString());
        loadStats->setText(QApplication::translate("menu", "load stats", 0));
        defalutStatsB->setText(QApplication::translate("menu", "default stats", 0));
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H

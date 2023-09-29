/********************************************************************************
** Form generated from reading UI file 'Mess.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESS_H
#define UI_MESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mess_gui
{
public:
    QTextEdit *textEdit;

    void setupUi(QWidget *mess_gui)
    {
        if (mess_gui->objectName().isEmpty())
            mess_gui->setObjectName(QStringLiteral("mess_gui"));
        mess_gui->resize(400, 175);
        textEdit = new QTextEdit(mess_gui);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(83, 50, 251, 91));
        QFont font;
        font.setPointSize(26);
        textEdit->setFont(font);

        retranslateUi(mess_gui);

        QMetaObject::connectSlotsByName(mess_gui);
    } // setupUi

    void retranslateUi(QWidget *mess_gui)
    {
        mess_gui->setWindowTitle(QApplication::translate("mess_gui", "Form", 0));
        textEdit->setHtml(QApplication::translate("mess_gui", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:26pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#ff0000;\">player1 is out! losser...</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class mess_gui: public Ui_mess_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESS_H

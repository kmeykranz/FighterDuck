/********************************************************************************
** Form generated from reading UI file 'gameMenu.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEMENU_H
#define UI_GAMEMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameMenu
{
public:
    QLabel *label;
    QPushButton *startButton;
    QPushButton *ExitButton;
    QLabel *window;

    void setupUi(QWidget *GameMenu)
    {
        if (GameMenu->objectName().isEmpty())
            GameMenu->setObjectName(QString::fromUtf8("GameMenu"));
        GameMenu->resize(750, 400);
        GameMenu->setMinimumSize(QSize(750, 400));
        GameMenu->setMaximumSize(QSize(750, 400));
        GameMenu->setAutoFillBackground(false);
        GameMenu->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(GameMenu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 50, 451, 101));
        QFont font;
        font.setPointSize(50);
        font.setUnderline(false);
        label->setFont(font);
        startButton = new QPushButton(GameMenu);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(270, 160, 211, 51));
        QFont font1;
        font1.setPointSize(15);
        startButton->setFont(font1);
        startButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: #2E3648;\n"
"	border-style: solid;\n"
"    border-width: 5px;\n"
"    border-color:darkred;\n"
"}"));
        ExitButton = new QPushButton(GameMenu);
        ExitButton->setObjectName(QString::fromUtf8("ExitButton"));
        ExitButton->setGeometry(QRect(270, 240, 211, 51));
        ExitButton->setFont(font1);
        ExitButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: #2E3648;\n"
"	border-style: solid;\n"
"    border-width: 5px;\n"
"    border-color:darkred;\n"
"}"));
        window = new QLabel(GameMenu);
        window->setObjectName(QString::fromUtf8("window"));
        window->setGeometry(QRect(0, 0, 45, 13));
        window->raise();
        label->raise();
        startButton->raise();
        ExitButton->raise();

        retranslateUi(GameMenu);

        QMetaObject::connectSlotsByName(GameMenu);
    } // setupUi

    void retranslateUi(QWidget *GameMenu)
    {
        GameMenu->setWindowTitle(QCoreApplication::translate("GameMenu", "Form", nullptr));
        label->setText(QCoreApplication::translate("GameMenu", "<html><head/><body><p><span style=\" color:#ff0000;\">Fighter Duck</span></p></body></html>", nullptr));
        startButton->setText(QCoreApplication::translate("GameMenu", "Start", nullptr));
        ExitButton->setText(QCoreApplication::translate("GameMenu", "Exit", nullptr));
        window->setText(QCoreApplication::translate("GameMenu", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameMenu: public Ui_GameMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEMENU_H

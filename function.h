#ifndef FUNCTION_H
#define FUNCTION_H
#include <QLabel>
#include <QDebug>
#include <QMovie>
#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QEventLoop>
#include <QTextEdit>
#include <QGuiApplication>

enum Dir{up,left,down,right};

//自定义delay函数
static void delay(int msec){
    QTime dieTime= QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

#endif // FUNCTION_H

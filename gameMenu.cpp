#include "gameMenu.h"
#include "ui_gameMenu.h"

GameMenu::GameMenu(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::GameMenu)
{
    ui->setupUi(this);
    this->setFixedSize(750,400);
    this->setWindowTitle("Fighter Duck Demo04");
    //背景加载
    background=new QMovie("Images/bg.gif");
    ui->window->setMovie(background);
    background->setSpeed(20);
    background->start();
    ui->window->setFixedSize(750,400);
    ui->window->setScaledContents(true);
}

GameMenu::~GameMenu(){
    delete w;
}

void GameMenu::on_startButton_clicked()
{
    w=new GameEngine;
    w->show();
    this->close();
}


void GameMenu::on_ExitButton_clicked()
{
    exit(-1);
}


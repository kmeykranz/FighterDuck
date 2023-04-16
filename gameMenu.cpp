#include "gameMenu.h"
#include "ui_gameMenu.h"

GameMenu::GameMenu(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::GameMenu)
{
    ui->setupUi(this);
    //背景加载
    background=new QMovie("Images/bg.gif");
    ui->window->setMovie(background);
    background->setSpeed(10);
    background->start();
    ui->window->setFixedSize(750,400);
    ui->window->setScaledContents(true);
    this->setFixedSize(750,400);
    this->setWindowTitle("Fighter Duck Demo04");
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


void GameMenu::on_connectButton_clicked()
{
    w->createClient();
    w->getClient()->Connect(ui->ip,ui->port,ui->id);
}


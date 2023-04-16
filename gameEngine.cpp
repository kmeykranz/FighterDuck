#include "gameengine.h"
#include "ui_gameengine.h"

GameEngine::GameEngine(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameEngine)
{
    ui->setupUi(this);
    this->setWindowTitle("Fighter duck Demo 04");
    this->setFixedSize(750,400);
    //背景加载
    background=new QMovie("Images/bg.gif");
    QLabel *bg = new QLabel(this);
    bg->setMovie(background);
    background->setSpeed(10);
    background->start();
    bg->setFixedSize(750,400);
    bg->setScaledContents(true);

    //创建玩家
    box=new BoxEnemy(this);
    enemy=new Enemy(this);
    duck=new Player(this);

    //游戏帧率控制
    timer=new QTimer;
    connect(timer,&QTimer::timeout,this,&GameEngine::MainGame);
    timer->start(1000/30);
    timer2=new QTimer;
    connect(timer2,&QTimer::timeout,this,&GameEngine::SlowGame);
    timer2->start(1000/10);
}

GameEngine::~GameEngine()
{
    delete ui;
    delete duck;
    delete timer;
    delete box;
    delete enemy;
}

//按键
void GameEngine::keyPressEvent(QKeyEvent* e){
    if(e->key()==Qt::Key_Escape)exit(-1);
    if(e->key()==Qt::Key_A)duck->Walk(left);
    if(e->key()==Qt::Key_D)duck->Walk(right);
    if(e->key()==Qt::Key_S)duck->Down();
    //    if(e->key()==Qt::Key_W);
    if(e->key()==Qt::Key_J){
        if(distance2>0&&duck->GetSide()==left&&distance2<100){
            duck->Fight1(enemy);
        }
        else if(distance2<0&&duck->GetSide()==right&&-distance2<100){
            duck->Fight1(enemy);
        }
        else if(distance>0&&duck->GetSide()==left&&distance<100){
            duck->Fight1(box);
        }
        else if(distance<0&&duck->GetSide()==right&&-distance<100){
            duck->Fight1(box);
        }
        else{
            duck->Fight1();
        }
    }
    if(e->key()==Qt::Key_K){
        if(distance2>0&&duck->GetSide()==left&&distance2<100){
            duck->Fight2(enemy);
        }
        else if(distance2<0&&duck->GetSide()==right&&-distance2<100){
            duck->Fight2(enemy);
        }
        else if(distance>0&&duck->GetSide()==left&&distance<100){
            duck->Fight2(box);
        }
        else if(distance<0&&duck->GetSide()==right&&-distance<100){
            duck->Fight2(box);
        }

        else{
            duck->Fight2();
        }
    }
}
//松开按键
void GameEngine::keyReleaseEvent(QKeyEvent*e){
    if(e->key()==Qt::Key_A||e->key()==Qt::Key_S||e->key()==Qt::Key_D||e->key()==Qt::Key_W){
        duck->Stand();
    }
}
//Game Loop
void GameEngine::MainGame(){
    duck->Refresh();
    duck->Refresh();
    enemy->Refresh();
    distance=duck->GetX()-box->GetX();
    distance2=duck->GetX()-enemy->GetX();
    if(duck->GetHealth()==0){
        exit(-1);
    }
    else if(enemy->GetHealth()==0){
        exit(-1);
    }
}

void GameEngine::SlowGame(){
    if(enemy->FindPlayer(duck->GetX(),duck->IsFight())){
        if(distance2>0){
            duck->Hurt(right);
            delay(300);
            enemy->Stand(right);
        }
        else{
            duck->Hurt(left);
            delay(300);
            enemy->Stand(left);
        }
    }
}


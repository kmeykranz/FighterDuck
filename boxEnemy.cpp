#include "boxEnemy.h"

BoxEnemy::BoxEnemy(QWidget* widget)
{
    this->Load();
    box=new QLabel(widget);
    box->setPixmap(boxDef);
    box->setFixedSize(150,150);
    box->setScaledContents(true);
    box->show();

    health=new QLabel(widget);

    health->move(x+50,y-30);
    string_health_number= QString::number(health_number, 10);
    health->setFont(QFont("Microsoft YaHei", 20, QFont::Bold));
    health->setStyleSheet("color:red;");
    health->setText(string_health_number);
    box->move(x,y);
    health->show();
}
BoxEnemy::~BoxEnemy(){
    delete box;
    delete box_hurt_r;
    delete box_hurt_l;
}
void BoxEnemy::Hurt(Dir dir){
    health_number-=10;
    string_health_number= QString::number(health_number, 10);
    health->setText(string_health_number);
    if(dir==right){
        box->setMovie(box_hurt_r);
        box_hurt_r->start();
        delay(200);
        box_hurt_r->stop();
        box->setPixmap(boxDef);
    }else{
        box->setMovie(box_hurt_l);
        box_hurt_l->start();
        delay(200);
        box_hurt_l->stop();
        box->setPixmap(boxDef);
    }
}
int BoxEnemy::GetX(){
    return x;
}

int BoxEnemy::GetHealth(){
    return health_number;
}

void BoxEnemy::Load(){
    boxDef.load("Images/box.png");

    box_hurt_r=new QMovie("Images/box_hurt_r.gif");
    box_hurt_l=new QMovie("Images/box_hurt_l.gif");
}

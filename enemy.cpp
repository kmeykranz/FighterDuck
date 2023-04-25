#include "enemy.h"

Enemy::Enemy(QWidget* widget)
{
    this->Load();
    enemy=new QLabel(widget);
    enemy->setFixedSize(160,160);
    enemy->setScaledContents(true);
    enemy->setMovie(stand_l);
    stand_l->start();
    enemy->show();

    health=new QLabel(widget);
    string_health_number= QString::number(health_number, 10);
    health->setFont(QFont("Microsoft YaHei", 20, QFont::Bold));
    health->setStyleSheet("color:red;");
    health->setText(string_health_number);
    health->show();
}
Enemy::~Enemy(){
    delete enemy;
    delete walk_l;
    delete walk_r;
    delete stand_l;
    delete stand_r;
    delete fight_r1;
    delete fight_l1;
    delete health;
    delete prepare_r;
    delete prepare_l;
    delete catch_r;
    delete catch_l;
    delete hurt_r;
    delete hurt_l;
}
void Enemy::Refresh(){
    enemy->move(x,y);
    health->move(x+50,y);
}
void Enemy::Hurt(Dir dir){
    is_hurt=1;
    health_number-=10;
    string_health_number= QString::number(health_number, 10);
    health->setText(string_health_number);
    if(dir==right){
        enemy->setMovie(hurt_l);
        hurt_l->start();
        if(x<650){
            x+=15;
            delay(100);
            x+=10;
            delay(80);
            x+=5;}
        hurt_l->stop();
        enemy->setMovie(stand_l);
        stand_l->start();
    }else{
        enemy->setMovie(hurt_r);
        hurt_r->start();
        if(x>-50){
            x-=15;
            delay(100);
            x-=10;
            delay(80);
            x-=5;}
        hurt_r->stop();
        enemy->setMovie(stand_r);
        stand_r->start();
    }
    is_hurt=0;
}
int Enemy::GetX(){
    return x;
}

int Enemy::GetHealth(){
    return health_number;
}

void Enemy::Fight(Dir dir){
    if(dir==left){
        enemy->setMovie(fight_l1);
        fight_l1->start();
        delay(200);
        x-=30;
        delay(100);
        x-=25;
        delay(100);
        x-=15;
        delay(500);
        fight_l1->stop();
        enemy->setMovie(stand_l);
        stand_l->start();
    }
    else{
        enemy->setMovie(fight_r1);
        fight_r1->start();
        delay(200);
        x+=30;
        delay(100);
        x+=25;
        delay(100);
        x+=15;
        delay(500);
        fight_r1->stop();
        enemy->setMovie(stand_r);
        stand_r->start();
    }
}

bool Enemy::FindPlayer(int dis,bool is_fight){
    if(is_hurt==0&&(this->x)-dis>0&&(this->x)-dis<80){
        delay(500);
        if(is_fight==1){
            enemy->setMovie(catch_l);
            catch_l->start();
        }
        else{
            enemy->setMovie(prepare_l);
            prepare_l->start();
            delay(500);
        }
        enemy->setMovie(fight_l1);
        fight_l1->start();
        delay(200);
        x-=30;
        return 1;
        delay(100);
        x-=25;
        delay(100);
        x-=15;
    }
    else if(is_hurt==0&&(this->x)-dis<0&&dis-(this->x)<80){
        delay(500);
        if(is_fight==1){
            enemy->setMovie(catch_r);
            catch_r->start();
        }
        else{
            enemy->setMovie(prepare_r);
            prepare_r->start();
            delay(500);
        }
        enemy->setMovie(fight_r1);
        fight_r1->start();
        delay(200);
        x+=30;
        return 1;
        delay(100);
        x+=25;
        delay(100);
        x+=15;
    }
    else{
        if((this->x)-dis>0){
            enemy->setMovie(walk_l);
            walk_l->start();
            x-=3;
        }else if((this->x)-dis<0){
            enemy->setMovie(walk_r);
            walk_r->start();
            x+=3;
        }
        return 0;
    }
}

void Enemy::Stand(Dir dir){
    if(dir==right){
        fight_r1->stop();
        enemy->setMovie(stand_r);
        stand_r->start();
    }
    else{
        fight_l1->stop();
        enemy->setMovie(stand_l);
        stand_l->start();
    }
}

void Enemy::Load(){
    stand_r=new QMovie("Images/BadDuck/stand_r.gif");
    stand_l=new QMovie("Images/BadDuck/stand_l.gif");
    fight_r1=new QMovie("Images/BadDuck/fight_r1.gif");
    fight_l1=new QMovie("Images/BadDuck/fight_l1.gif");
    walk_r=new QMovie("Images/BadDuck/walk_r.gif");
    walk_l=new QMovie("Images/BadDuck/walk_l.gif");
    hurt_r=new QMovie("Images/BadDuck/hurt_r.gif");
    hurt_l=new QMovie("Images/BadDuck/hurt_l.gif");
    catch_r=new QMovie("Images/BadDuck/catch_r.gif");
    catch_l=new QMovie("Images/BadDuck/catch_l.gif");
    prepare_r=new QMovie("Images/BadDuck/prepare_r.gif");
    prepare_l=new QMovie("Images/BadDuck/prepare_l.gif");

    down_r.load("Images/BadDuck/down_r.png");
    down_l.load("Images/BadDuck/down_l.png");
}


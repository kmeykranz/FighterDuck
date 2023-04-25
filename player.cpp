#include "player.h"

Player::Player(QWidget* widget)
{
    this->Load();
    player=new QLabel(widget);
    player->setFixedSize(160,160);
    player->setScaledContents(true);
    this->Stand();
    player->show();

    health=new QLabel(widget);
    health->move(x+50,y-30);
    string_health_number= QString::number(health_number, 10);
    health->setFont(QFont("Microsoft YaHei", 20, QFont::Bold));
    health->setStyleSheet("color:green;");
    health->setText(string_health_number);
    health->show();
}
Player::~Player(){
    delete player;
    delete walk_l;
    delete walk_r;
    delete stand_l;
    delete stand_r;
    delete fight_r1;
    delete fight_r2;
    delete fight_l1;
    delete fight_l2;
    delete health;
    delete hurt_l;
    delete hurt_r;
}

int Player::GetHealth(){
    return health_number;
}

void Player::Refresh(){
    player->move(x,y);
    health->move(x+50,y);
    string_health_number= QString::number(health_number, 10);
    health->setText(string_health_number);
}

void Player::Walk(Dir dir){
    if(dir==right){
        side=right;
        player->setMovie(walk_r);
        walk_r->start();
        if(x<650){
        (this->x)+=speed;
        }
    }else{
        side=left;
        player->setMovie(walk_l);
        walk_l->start();
        if(x>-50){
        (this->x)-=speed;
        }
    }
}

void Player::Stand(){
    if(side==right){
        player->setMovie(stand_r);
        stand_r->start();
    }
    else{
        player->setMovie(stand_l);
        stand_l->start();
    }
    is_down=false;
}

void Player::Down(){
    if(side==right){
        player->setPixmap(down_r);
        is_down=true;
    }
    else{
        player->setPixmap(down_l);
        is_down=true;
    }
}
void Player::Fight1(){
    if(is_fight==0){
        is_fight=1;
        if(side==right){
            player->setMovie(fight_r1);
            fight_r1->start();
            is_down=false;
            if(x<650){
            this->x+=20;
            delay(100);
            this->x+=10;
            delay(100);
            this->x+=5;}
            else{delay(200);}
            is_fight=0;
            fight_r1->stop();
            player->setMovie(stand_r);
        }else{
            player->setMovie(fight_l1);
            fight_l1->start();
            is_down=false;
            if(x>-50){
            this->x-=20;
            delay(100);
            this->x-=10;
            delay(100);
            this->x-=5;}
            else{delay(200);}
            is_fight=0;
            fight_l1->stop();
            player->setMovie(stand_l);
        }
    }
}
void Player::Fight2(){
    if(is_fight==0){
        is_fight=1;
        if(side==right){
            player->setMovie(fight_r2);
            fight_r2->start();
            is_down=false;
            if(x<650){
            this->x+=20;
            delay(100);
            this->x+=10;
            delay(100);
            this->x+=5;}
            else{delay(200);}
            is_fight=0;
            fight_r2->stop();
            player->setMovie(stand_r);
        }else{
            player->setMovie(fight_l2);
            fight_l2->start();
            is_down=false;
            if(x<650){
            this->x-=20;
            delay(100);
            this->x-=10;
            delay(100);
            this->x-=5;}
            else{delay(200);}
            is_fight=0;
            fight_l2->stop();
            player->setMovie(stand_l);
        }
    }
}

void Player::Fight1(BoxEnemy *box){
    if(is_fight==0){
        is_fight=1;
        if(box->GetHealth()>0){
            this->health_number+=10;
        }
        if(side==right){
            player->setMovie(fight_r1);
            fight_r1->start();
            this->x+=20;
            delay(100);
            box->Hurt(right);
            is_down=false;
            is_fight=0;
            fight_r1->stop();
            player->setMovie(stand_r);
        }else{
            player->setMovie(fight_l1);
            fight_l1->start();
            this->x-=20;
            delay(100);
            box->Hurt(left);
            is_down=false;
            is_fight=0;
            fight_l1->stop();
            player->setMovie(stand_l);

        }
        is_fight=0;
    }
}

void Player::Fight2(BoxEnemy *box){
    if(is_fight==0){
        is_fight=1;
        if(box->GetHealth()>0){
            this->health_number+=10;
        }
        if(side==right){
            player->setMovie(fight_r2);
            fight_r2->start();
            this->x+=25;
            delay(100);
            box->Hurt(right);
            this->x+=15;
            delay(100);
            this->x+=10;
            delay(50);
            this->x+=5;
            delay(50);

            is_down=false;
            is_fight=0;
            fight_r2->stop();
            player->setMovie(stand_r);
        }else{
            player->setMovie(fight_l2);
            fight_l2->start();
            this->x-=25;
            delay(100);
            box->Hurt(left);
            this->x-=15;
            delay(100);
            this->x-=10;
            delay(50);
            this->x-=5;
            delay(50);
            is_down=false;
            is_fight=0;
            fight_l2->stop();
            player->setMovie(stand_l);

        }
        is_fight=0;
    }
}

void Player::Fight1(Enemy *box){
    if(is_fight==0){
        is_fight=1;
        if(side==right){
            player->setMovie(fight_r1);
            fight_r1->start();
            this->x+=13;
            box->Hurt(right);
            delay(100);
            this->x+=7;
            is_down=false;
            is_fight=0;
            fight_r1->stop();
            player->setMovie(stand_r);
        }else{
            player->setMovie(fight_l1);
            fight_l1->start();
            this->x+=13;
            box->Hurt(left);
            delay(100);
            this->x+=7;
            is_down=false;
            is_fight=0;
            fight_l1->stop();
            player->setMovie(stand_l);

        }
    }
}

void Player::Fight2(Enemy *box){
    if(is_fight==0){
        is_fight=1;
        if(side==right){
            player->setMovie(fight_r2);
            fight_r2->start();
            this->x+=13;
            box->Hurt(right);
            delay(100);
            this->x+=7;

            is_down=false;
            is_fight=0;
            fight_r2->stop();
            player->setMovie(stand_r);
        }else{
            player->setMovie(fight_l2);
            fight_l2->start();
            this->x-=13;
            box->Hurt(left);
            delay(100);
            this->x-=7;

            is_down=false;
            is_fight=0;
            fight_l2->stop();
            player->setMovie(stand_l);

        }
    }
}

void Player::Hurt(Dir dir){
    if(is_down){
        if(dir==right){
            x+=15;
            delay(100);
            x+=10;
            delay(80);
            x+=5;
        }else{
            x-=15;
            delay(100);
            x-=10;
            delay(80);
            x-=5;
        }
        return;}
    is_hurt=1;
    health_number-=10;
    string_health_number= QString::number(health_number, 10);
    health->setText(string_health_number);
    if(side==right){
        player->setMovie(hurt_r);
        hurt_r->start();
    }else{
        player->setMovie(hurt_l);
        hurt_l->start();
    }
    if(dir==right){
        x+=15;
        delay(100);
        x+=10;
        delay(80);
        x+=5;
    }else{
        x-=15;
        delay(100);
        x-=10;
        delay(80);
        x-=5;
    }
    if(side==right){
        hurt_r->stop();
        player->setMovie(stand_r);
        stand_r->start();
    }else{
        hurt_l->stop();
        player->setMovie(stand_l);
        stand_l->start();
    }
    is_hurt=0;
}

bool Player::GetIsDown(){
    return is_down;
}

int Player::GetX(){
    return x;
}

Dir Player::GetSide(){
    return side;
}

bool Player::IsHurt(){
    return is_hurt;
}

bool Player::IsFight(){
    return is_fight;
}


void Player::Load(){
    stand_r=new QMovie("Images/Duck/stand_r.gif");
    stand_l=new QMovie("Images/Duck/stand_l.gif");
    fight_r1=new QMovie("Images/Duck/fight_r1.gif");
    fight_r2=new QMovie("Images/Duck/fight_r2.gif");
    fight_l1=new QMovie("Images/Duck/fight_l1.gif");
    fight_l2=new QMovie("Images/Duck/fight_l2.gif");
    walk_r=new QMovie("Images/Duck/walk_r.gif");
    walk_l=new QMovie("Images/Duck/walk_l.gif");
    hurt_r=new QMovie("Images/Duck/hurt_r.gif");
    hurt_l=new QMovie("Images/Duck/hurt_l.gif");

    down_r.load("Images/Duck/down_r.png");
    down_l.load("Images/Duck/down_l.png");
}

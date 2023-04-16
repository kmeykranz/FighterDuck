#ifndef ENEMY_H
#define ENEMY_H
#include "function.h"

class Enemy
{
public:
    Enemy(QWidget* widget);
    ~Enemy();

    void Hurt(Dir dir); //受伤
    void Load(); //加载资源
    void Refresh(); //刷新显示位置
    bool FindPlayer(int dis,bool is_fight); //寻找玩家并攻击
    int GetHealth();

    void Fight(Dir dir);

    int GetX();
    void Stand(Dir dir);
private:
    QLabel *enemy;

    QMovie *stand_r;
    QMovie *stand_l;
    QMovie *fight_r1;
    QMovie *fight_l1;
    QMovie *walk_r;
    QMovie *walk_l;
    QMovie *hurt_r;
    QMovie *hurt_l;
    QPixmap down_r;
    QPixmap down_l;

    QMovie *catch_r;
    QMovie *catch_l;
    QMovie *prepare_r;
    QMovie *prepare_l;

    QString string_health_number;

    QLabel *health;
    int health_number=500;
    int x=450,y=182;
    bool is_hurt=0;
};

#endif // ENEMY_H

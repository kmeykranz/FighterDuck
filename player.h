#ifndef PLAYER_H
#define PLAYER_H
#include "function.h"
#include "boxEnemy.h"
#include "enemy.h"

class Player
{
public:
    Player(QWidget *widget);
    ~Player();

    void Stand(); //默认
    void Down(); //防御
    bool GetIsDown(); //返回是否在防御
    void Refresh(); //刷新显示位置
    void Walk(Dir dir); //移动
    void Fight1(); //攻击1
    void Fight2(); //攻击2
    //重载函数
    void Fight1(BoxEnemy *box); //攻击box对象
    void Fight2(BoxEnemy *box);
    void Fight1(Enemy *enemy); //攻击enemy对象
    void Fight2(Enemy *enemy);

    void Load(); //加载资源
    void Hurt(Dir dir); //受伤
    bool IsHurt(); //返回是否处于受伤
    int GetHealth(); //获取血量
    bool IsFight(); //是否在攻击

    int GetX();
    Dir GetSide();
private:
    QLabel *player;

    QMovie *stand_r;
    QMovie *stand_l;
    QMovie *fight_r1;
    QMovie *fight_r2;
    QMovie *fight_l1;
    QMovie *fight_l2;
    QMovie *walk_r;
    QMovie *walk_l;
    QPixmap down_r;
    QPixmap down_l;

    QMovie *hurt_r;
    QMovie *hurt_l;

    int speed=5;
    Dir side=right; //面向右边
    bool is_down; //是否下蹲
    int x=100,y=182;
    bool is_fight=0;
    bool is_hurt=0;

    QLabel *health;
    QString string_health_number;
    int health_number=100;

};
#endif // PLAYER_H

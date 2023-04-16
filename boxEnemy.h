#ifndef BOXENEMY_H
#define BOXENEMY_H
#include "function.h"


class BoxEnemy
{
public:
    BoxEnemy(QWidget* widget);
    ~BoxEnemy();

    void Hurt(Dir dir); //受伤
    void Load(); //加载资源

    int GetX(); //获取X坐标
    int GetHealth(); //获取血量
private:
    QLabel *box;
    QPixmap boxDef;
    QMovie *box_hurt_r;
    QMovie *box_hurt_l;


    QLabel *health;
    QString string_health_number;
    int health_number=50;
    int x=0,y=166;
};

#endif // BOXENEMY_H

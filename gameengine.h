#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "function.h"
#include "player.h"
#include "boxEnemy.h"
#include "Enemy.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameEngine; }
QT_END_NAMESPACE

class GameEngine : public QWidget
{
    Q_OBJECT
public:
    GameEngine(QWidget *parent = nullptr);
    ~GameEngine();
protected:
    void keyPressEvent(QKeyEvent* e);
    void keyReleaseEvent(QKeyEvent* e);
public slots:
    void MainGame(); //游戏主循环
    void SlowGame(); //慢循环
private:
    Ui::GameEngine *ui;
    Player *duck;
    QMovie *background;
    BoxEnemy *box;
    Enemy *enemy;
    QTimer *timer;//帧率控制
    QTimer *timer2;//帧率控制
    int distance,distance2;
    QLabel *end;
};
#endif // GAMEENGINE_H

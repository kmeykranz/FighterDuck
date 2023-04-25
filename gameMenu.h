#ifndef GAMEMENU_H
#define GAMEMENU_H
#include "function.h"
#include "gameengine.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameMenu; }
QT_END_NAMESPACE

class GameMenu: public QWidget
{
    Q_OBJECT
public:
    GameMenu(QWidget *parent = nullptr);
    ~GameMenu();
private slots:
    void on_startButton_clicked();

    void on_ExitButton_clicked();

private:
    Ui::GameMenu *ui;
    GameEngine *w;
    QMovie *background;
};

#endif // GAMEMENU_H

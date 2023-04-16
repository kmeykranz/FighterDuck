QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    boxEnemy.cpp \
    enemy.cpp \
    gameEngine.cpp \
    gameMenu.cpp \
    main.cpp \
    player.cpp

HEADERS += \
    boxEnemy.h \
    enemy.h \
    function.h \
    gameEngine.h \
    gameMenu.h \
    player.h\

FORMS += \
    gameEngine.ui \
    gameMenu.ui

RC_FILE=Images/duck.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

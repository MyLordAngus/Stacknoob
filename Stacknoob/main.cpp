#include <QtGui/QApplication>
#include "mainwindow.h"
#include "core/game.h"
#include "core/player.h"
#include "core/workflow.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Player player("Player1",0);
    Game game(&player);

    Workflow work(&player);
    work.createPiece();

    return a.exec();
}

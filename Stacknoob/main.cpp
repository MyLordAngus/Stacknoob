#include <QtGui/QApplication>

#include "mainwindow.h"
#include "core/game.h"
#include "core/workflow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Game game;
    w.getBWidget()->connectWorkflow(&(game.getPlayer(0)->getWorkflow()));

    game.launchGame();

    w.show();

    return a.exec();
}

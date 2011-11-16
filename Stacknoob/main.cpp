#include <QtGui/QApplication>

#include "mainwindow.h"
#include "core/game.h"
#include "core/workflow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Game game;
    game.launchGame();

    w.connectWorkflow(game.getWorkflow());
    w.show();

    return a.exec();
}

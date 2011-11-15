#include <QtGui/QApplication>

#include "mainwindow.h"
#include "core/game.h"
#include "core/workflow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Game game;

    Workflow* wf = game.getWorkflow();
    w.getBWidget()->connectWorkflow(wf);

    game.launchGame();

    w.show();

    return a.exec();
}

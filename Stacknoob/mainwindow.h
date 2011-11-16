#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "view/boardwidget.h"
#include "view/panelwidget.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    BoardWidget* getBWidget() { return this->b_widget; }

private:
    Ui::MainWindow *ui;

    /// The graphical board
    BoardWidget* b_widget;
    PanelWidget* p_widget;

};

#endif // MAINWINDOW_H

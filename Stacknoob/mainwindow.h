#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "view/boardwidget.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    BoardWidget* b_widget;
};

#endif // MAINWINDOW_H

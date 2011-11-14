#include <QHBoxLayout>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "view/boardwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Main Layout
    QHBoxLayout *layout = new QHBoxLayout();
    BoardWidget *board = new BoardWidget();
    this->b_widget = board;
    layout->addWidget(board);

    this->centralWidget()->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

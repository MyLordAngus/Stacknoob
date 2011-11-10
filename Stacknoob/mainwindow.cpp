#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Main Layout
    QHBoxLayout *layout = new QHBoxLayout();
    this->centralWidget()->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

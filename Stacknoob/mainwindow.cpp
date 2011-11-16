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
    this->b_widget = new BoardWidget();
    layout->addWidget(b_widget);

    this->p_widget = new PanelWidget();
    layout->addWidget(p_widget);

    this->centralWidget()->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

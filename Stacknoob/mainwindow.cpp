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

    // Board Widget
    this->b_widget = new BoardWidget();
    layout->addWidget(b_widget);

    // Panel Widget to display score and next piece
    this->p_widget = new PanelWidget();
    layout->addWidget(p_widget);

    this->centralWidget()->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectWorkflow(Workflow* w)
{
    this->b_widget->connectWorkflow(w);
    this->p_widget->connectWorkflow(w);
}

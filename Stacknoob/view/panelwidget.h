#ifndef PANELWIDGET_H
#define PANELWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLCDNumber>

#include "core/workflow.h"
#include "boardframe.h"

class PanelWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PanelWidget(QWidget *parent = 0);
    void connectWorkflow(Workflow* w);

private:
    Workflow* workflow;

    QVBoxLayout layout;
    QLCDNumber* score;
    BoardFrame* next_piece;

public slots:
    void updateScore(int);
};

#endif // PANELWIDGET_H

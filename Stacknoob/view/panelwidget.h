#ifndef PANELWIDGET_H
#define PANELWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLCDNumber>

class PanelWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PanelWidget(QWidget *parent = 0);

private:
    QVBoxLayout layout;
    QLCDNumber* score;
    QLabel* nextPiece;

signals:

public slots:

};

#endif // PANELWIDGET_H

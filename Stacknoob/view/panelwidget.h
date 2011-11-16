#ifndef PANELWIDGET_H
#define PANELWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

class PanelWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PanelWidget(QWidget *parent = 0);

private:
    QVBoxLayout layout;

signals:

public slots:

};

#endif // PANELWIDGET_H

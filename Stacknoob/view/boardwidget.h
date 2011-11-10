#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QPainter>
#include <QMessageBox>

class BoardWidget : public QFrame
{
    Q_OBJECT
public:
    explicit BoardWidget(QFrame *parent = 0);
    virtual void paintEvent(QPaintEvent *);

private:

signals:

public slots:

};

#endif // BOARDWIDGET_H

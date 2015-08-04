/**
    widget.h

    @author Dmytro Haponov
    @version 1.2 3/08/15
*/
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_CreateDBbutt_clicked();

    void on_OpenDBbutt_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

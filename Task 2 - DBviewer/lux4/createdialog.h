/**
    createdialog.h

    @author Dmytro Haponov
    @version 1.2 3/08/15
*/
#ifndef CREATEDIALOG_H
#define CREATEDIALOG_H

#include <QDialog>

namespace Ui {
class CreateDialog;
}

class CreateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateDialog(QWidget *parent = 0);
    ~CreateDialog();

private slots:
    void on_createBrowse_clicked();

    void on_buttonBox_accepted();

private:
    Ui::CreateDialog *ui;
};

#endif // CREATEDIALOG_H

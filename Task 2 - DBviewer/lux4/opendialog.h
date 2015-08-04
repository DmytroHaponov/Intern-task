/**
    opendialog.h

    @author Dmytro Haponov
    @version 1.2 3/08/15
*/

#ifndef OPENDIALOG_H
#define OPENDIALOG_H

#include <QDialog>

namespace Ui {
class OpenDialog;
}

class OpenDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OpenDialog(QWidget *parent = 0);
    ~OpenDialog();

private slots:
    void on_OpenBrowseButt_clicked();

    void on_buttonBox_accepted();

private:
    Ui::OpenDialog *ui;
};

#endif // OPENDIALOG_H

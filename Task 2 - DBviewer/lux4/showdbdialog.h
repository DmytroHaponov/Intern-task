/**
    showdialog.h

    @author Dmytro Haponov
    @version 1.2 3/08/15
*/
#ifndef SHOWDBDIALOG_H
#define SHOWDBDIALOG_H

#include <QDialog>

namespace Ui {
class ShowDBdialog;
}

class ShowDBdialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowDBdialog(QWidget *parent = 0);
    ~ShowDBdialog();

private slots:

    void on_addDataButt_clicked();

    void on_DeleteData_clicked();

    void on_Edit_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::ShowDBdialog *ui;
};

#endif // SHOWDBDIALOG_H

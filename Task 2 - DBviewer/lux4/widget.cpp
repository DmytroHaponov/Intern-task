/**
    widget.cpp
    Purpose: display main window which leads to create and open dialogs

    @author Dmytro Haponov
    @version 1.2 3/08/15
*/

#include "widget.h"
#include "ui_widget.h"
#include <QtSql>
#include "createdialog.h"
#include "opendialog.h"

//==========================================
//auto generated code
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}
Widget::~Widget()
{
    delete ui;
}
//==========================================
            //after Create DB button clicked
void Widget::on_CreateDBbutt_clicked()
{
    //main window becomes inaccessible,
    //Create DB dialog appears
    CreateDialog createdb;
    createdb.setModal(true);
    createdb.exec();
}
//==========================================
            //after Open DB button clicked
void Widget::on_OpenDBbutt_clicked()
{
    //main window becomes inaccessible,
    //Open DB dialog appears
    OpenDialog opendb;
    opendb.setModal(true);
    opendb.exec();
}

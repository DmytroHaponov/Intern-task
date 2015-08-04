/**
    showdbdialog.cpp
    Purpose: display, add, edit and delete sql db data

    @author Dmytro Haponov
    @version 1.2 3/08/15
*/

#include "showdbdialog.h"
#include "ui_showdbdialog.h"
#include <QtSql>
#include <QString>
#include "createdialog.h"
#include "opendialog.h"
#include <QMessageBox>
#include <QDebug>

/**
    define a macro to refresh data shown
    after any activity
*/
#define refresh() \
    QSqlQueryModel * model = new QSqlQueryModel();\
    QSqlQuery qry1;\
    qry1.prepare("select * from single_table");\
    qry1.exec();\
    model->setQuery(qry1);\
    ui->tableView->setModel(model);
//===========================================================================================
                //auto generated code,
                //refresh() used for opened page to show data at once
ShowDBdialog::ShowDBdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowDBdialog)
{
    ui->setupUi(this);
    //---------------------------
    refresh();
    //---------------------------
}
ShowDBdialog::~ShowDBdialog()
{
    delete ui;
}
//============================================================================================
                //after Add button clicked
void ShowDBdialog::on_addDataButt_clicked()
{
    QString id, name, age;
//take info from the fields
    id=ui->IDEdit->text();
    name=ui->NameEdit->text();
    age=ui->AgeEdit->text();
//sql query for adding
    QSqlQuery qry;
    qry.prepare("insert into single_table (id,name,age) values('"+id+"','"+name+"','"+age+"')");
//show message for success or fail
    if(qry.exec())
    {
            QMessageBox::information(this,tr("Save"),tr("Saved"));
    }
    else
    {
            QMessageBox::critical(this,tr("Trouble Saving"), qry.lastError().text());
    }
    //---------------------------
    refresh();
    //---------------------------
}
//============================================================================================
                    //after Delete button clicked
void ShowDBdialog::on_DeleteData_clicked()
{
    QString id, name, age;
//take info from the fields
    id=ui->IDEdit->text();
    name=ui->NameEdit->text();
    age=ui->AgeEdit->text();
//sql query for delete row
    QSqlQuery qry, qryid;
    qryid.prepare("select * from single_table where id='"+id+"'");
//show message for fail or execute further
    if(qryid.exec())
    {
        //count - number of occurances of ID in DB
        int count=0;
        while(qryid.next())
            count++;
        //in case no such ID found - error
        //otherwise proceed
        if(count)
        {
            qry.prepare("delete from single_table where id='"+id+"'");
            //show message for success or fail
            if(qry.exec())
            {
                QMessageBox::information(this,tr("Save"),tr("Row deleted"));
            }
            else
            {
                QMessageBox::critical(this,tr("Trouble Saving:"), qry.lastError().text());
            }
        }
        else
        {
            QMessageBox::critical(this,tr("No such id"),tr("Changing ID is forbidden"));
        }
    }
    else
    {
        QMessageBox::critical(this,tr("Troble id"), qry.lastError().text() );
    }
    //---------------------------
    refresh();
    //---------------------------
}
//============================================================================================
                    //after Edit button clicked
void ShowDBdialog::on_Edit_clicked()
{
    QString id, name, age;
//take info from the fields
    id=ui->IDEdit->text();
    name=ui->NameEdit->text();
    age=ui->AgeEdit->text();
//sql query to check for existing id
    QSqlQuery qry, qryid;
    qryid.prepare("select * from single_table where id='"+id+"'");
//show message for fail or execute further
    if(qryid.exec())
    {
    //count - number of occurances of ID in DB
        int count=0;
        while(qryid.next())
            count++;
       //in case no such ID found - error
       //otherwise proceed
        if(count)
        {
            //query to update db with new data
            qry.prepare( "update single_table set name='"+name+"',age='"+age+"' where id='"+id+"'");
            //show message for success or fail
            if(qry.exec())
            {
                QMessageBox::information(this,tr("Save"),tr("Saved"));
            }
            else
            {
                QMessageBox::critical(this,tr("Trouble Saving:"), qry.lastError().text());
            }
        }
        else
        {
           QMessageBox::critical(this,tr("No such id"),tr("Changing ID is forbidden"));
        }
    }
    else
    {
        QMessageBox::critical(this,tr("Troble id"), qry.lastError().text() );
    }
    //---------------------------
    refresh();
    //---------------------------
}

//======================================================================================================
                    //after double clicked on any cell in table
void ShowDBdialog::on_tableView_activated(const QModelIndex &index)
{
//take the value of the cell where user double clicked
    QString tempval = ui->tableView->model()->data(index).toString();
//sql query for finding the row which contains cell where user double clicked
    QSqlQuery qry;
    qry.prepare("select * from single_table where id='"+tempval+"' or name='"+tempval+"' or age='"+tempval+"'");
//show message if failed to execute query
//otherwise proceed
    if(qry.exec())
    {
        //go through found
        while(qry.next())
        {
          //set edit fields values to the values in row where user double clicked
          ui->IDEdit->setText(qry.value(0).toString());
          ui->NameEdit->setText(qry.value(1).toString());
          ui->AgeEdit->setText(qry.value(2).toString());
        }
    }
    else
    {
       QMessageBox::critical(this,tr("Trouble selecting"), qry.lastError().text());
    }
}

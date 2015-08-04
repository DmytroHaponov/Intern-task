/**
    createdialog.cpp
    Purpose: display dialog window to create a DB

    @author Dmytro Haponov
    @version 1.2 3/08/15
*/

#include "createdialog.h"
#include "ui_createdialog.h"
#include <QtSql>
#include <QString>
#include <QFileDialog>
#include "showdbdialog.h"
#include <QMessageBox>
//========================================================================
//auto generated code
CreateDialog::CreateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateDialog)
{
    ui->setupUi(this);
}
CreateDialog::~CreateDialog()
{
    delete ui;
}
//========================================================================
                    //after Browse button clicked
void CreateDialog::on_createBrowse_clicked()
{
//select path to the new db
//folder view allowed only
    QString dbpath = QFileDialog::getExistingDirectory();
    ui->pathLineEdit -> setText(dbpath);
}
//========================================================================
                    //after OK button clicked
void CreateDialog::on_buttonBox_accepted()
{
    QString dbnametyped, dbpathfinal;
//get name and path that are in editlines
    dbnametyped = ui->NameLineEdit->text();
    dbpathfinal = ui->pathLineEdit->text();

//open connection to db
    QSqlDatabase createdDB = QSqlDatabase::addDatabase( "QSQLITE" );
    createdDB.setDatabaseName(dbpathfinal + "/" + dbnametyped + ".sqlite");
//check whether created db opened, such creating it
    if( !createdDB.open() )
    {
        qDebug() << createdDB.lastError();
        qFatal( "Failed to connect." );
    }
//---------------------------------------------------------------------------
/**
   create default empty table
   with 3 columns:
   "id", "name", "age"
 */
       QSqlQuery qry;
       qry.prepare("CREATE TABLE single_table"
         "("
            "id integer PRIMARY KEY NOT NULL, "
            "name VARCHAR(255), "
            "age integer"
         ");");
       if (!qry.exec())
       {
           QMessageBox::critical(this,tr("error creating table"), qry.lastError().text());
       }
//-----------------------------------------------------------------------------
//go to showDB window
      ShowDBdialog showdb;
      this->hide();
      showdb.setModal(true);
      showdb.exec();
}

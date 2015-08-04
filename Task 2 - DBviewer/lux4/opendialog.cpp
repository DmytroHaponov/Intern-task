/**
    opendialog.cpp
    Purpose: display dialog window to select a DB to open

    @author Dmytro Haponov
    @version 1.2 3/08/15
*/

#include "opendialog.h"
#include "ui_opendialog.h"
#include <QtSql>
#include <QFileDialog>
#include "showdbdialog.h"
#include <QDebug>
//========================================================================
//auto generated code
OpenDialog::OpenDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenDialog)
{
    ui->setupUi(this);
}
OpenDialog::~OpenDialog()
{
    delete ui;
}
//========================================================================
                //after Browse button clicked
void OpenDialog::on_OpenBrowseButt_clicked()
{
//get path to db as a string
//files with .sqlite allowed only
    QString dbopenpath = QFileDialog::getOpenFileName(this,
         tr("Choose SQlite db file"), "", tr("SQlite file (*.sqlite)"));

//set editline field to path selected before
     ui->lineEdit -> setText(dbopenpath);
}
//========================================================================
                //after OK button clicked
void OpenDialog::on_buttonBox_accepted()
{
      QString dbpathfinal;
//get result path - whether it was selected via Browse button
//or typed in editline field
      dbpathfinal = ui->lineEdit->text();

//open connection to db
      QSqlDatabase openedDB = QSqlDatabase::addDatabase( "QSQLITE" );
      openedDB.setDatabaseName(dbpathfinal);

//check whether db opened
      if( !openedDB.open() )
      {
        qDebug() << openedDB.lastError();
        qFatal( "Failed to connect." );
      }
//------------------------------------------------------------------------
//goto showdbdialog window
      ShowDBdialog showdb;
      this->hide();
      showdb.setModal(true);
      showdb.exec();
}


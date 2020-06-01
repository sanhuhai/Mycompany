#pragma once

#include <QtSql>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QtWidgets/QMainWindow>
#include <QDialog>
#include <QList>
#include <QVector>
#include <QString>
#include <QSqlDatabase>
#include <QMap>
#include <QStandardItem>
#include <QStandardItemModel>
#include "OpenDatabase.h"
#include "ui_QueryInformation.h"

class QueryInformation : public QDialog
{
	Q_OBJECT

public:
	QueryInformation(QWidget *parent = Q_NULLPTR);
	~QueryInformation();
	
	void openDatabase();
	void init();
	private slots :
		void search();
		void display();

private:
	Ui::QueryInformation ui;
	QSqlQuery qurey;
	QString qstr , select ;
	QList <QString> Q;
	QMap <QString, QString> QM;
	QStandardItemModel * model;
	OpenDatabase database;
};

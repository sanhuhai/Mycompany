#pragma once
#include <QtSql>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QtWidgets/QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>
#include "OpenDatabase.h"
#include <QDialog>
#include "ui_QureyDepartment.h"

class QureyDepartment : public QDialog
{
	Q_OBJECT

public:
	QureyDepartment(QWidget *parent = Q_NULLPTR);
	~QureyDepartment();
	void init();
	void display();
private slots:
	void search();
	
private:
	Ui::QureyDepartment ui;
	OpenDatabase database;
	QString insert;
	QSqlQuery qurey;
	QMap<QString, QString>QM;
	QStandardItemModel * model;
};

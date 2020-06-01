#pragma once
#include <QtSql>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QtWidgets/QMainWindow>
#include <QDialog>
#include <QStandardItemModel>
#include <QStandardItem>
#include "OpenDatabase.h"
#include "ui_DeleteEmployee.h"

class DeleteEmployee : public QDialog
{
	Q_OBJECT

public:
	DeleteEmployee(QWidget *parent = Q_NULLPTR);
	~DeleteEmployee();
	void init();
	void display();
private slots:
	void deleteInformation();

private:
	Ui::DeleteEmployee ui;
	QSqlQuery qurey;
	QString qstr, select;
	OpenDatabase database;
	QMap <QString, QString> QM;
	QStandardItemModel * model;
};

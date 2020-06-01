#pragma once
#include <QtSql>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QtWidgets/QMainWindow>
#include <QDialog>
#include "OpenDatabase.h"
#include "ui_InsertEmployee.h"

class InsertEmployee : public QDialog
{
	Q_OBJECT

public:
	InsertEmployee(QWidget *parent = Q_NULLPTR);
	~InsertEmployee();
	void display();
	private slots:
		void signup();
		void cancel();
private:
	Ui::InsertEmployee ui;
	OpenDatabase database;
	QString insert;
	QSqlQuery qurey;
};

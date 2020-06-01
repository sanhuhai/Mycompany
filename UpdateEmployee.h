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
#include "ui_UpdateEmployee.h"

class UpdateEmployee : public QDialog
{
	Q_OBJECT

	public:
		UpdateEmployee(QWidget *parent = Q_NULLPTR);
		~UpdateEmployee();
		void init();
		void display();
	private slots:
		void updateInformation();
	private:
		Ui::UpdateEmployee ui;
		QSqlQuery qurey;
		QString qstr, select;
		OpenDatabase database;
		QMap <QString, QString> QM;
		QStandardItemModel * model;
};
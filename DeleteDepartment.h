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
#include "ui_DeleteDepartment.h"

class DeleteDepartment : public QDialog
{
	Q_OBJECT

public:
	DeleteDepartment(QWidget *parent = Q_NULLPTR);
	~DeleteDepartment();
	void init();
	void display();
private slots:
	void del();

private:
	Ui::DeleteDepartment ui;
	OpenDatabase database;
	QString insert;
	QSqlQuery qurey;
	QMap<QString, QString>QM;
	QStandardItemModel * model;
};

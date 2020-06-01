#pragma once
#include <QtSql>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QtWidgets/QMainWindow>
#include "OpenDatabase.h"
#include <QDialog>
#include <QMap>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDialog>
#include <QDialog>
#include "ui_insertDepartment.h"

class insertDepartment : public QDialog
{
	Q_OBJECT

public:
	insertDepartment(QWidget *parent = Q_NULLPTR);
	~insertDepartment();
	void display();
private slots:
	void add();
	void cancel();

private:
	Ui::insertDepartment ui;
	OpenDatabase database;
	QString insert;
	QSqlQuery qurey;
	QMap<QString, QString>QM;
	QStandardItemModel * model;
};

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
#include "ui_UpdateDepartment.h"

class UpdateDepartment : public QDialog
{
	Q_OBJECT

public:
	UpdateDepartment(QWidget *parent = Q_NULLPTR);
	~UpdateDepartment();
	void init();
	void display();
private slots:
	void update();
private:
	Ui::UpdateDepartment ui;
	OpenDatabase database;
	QString insert;
	QSqlQuery qurey;
	QMap<QString, QString>QM;
	QStandardItemModel * model;
};

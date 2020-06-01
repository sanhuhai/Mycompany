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
#include <QMap>
#include "OpenDatabase.h"
#include <QDialog>
#include "ui_AddCommodity.h"

class AddCommodity : public QDialog
{
	Q_OBJECT

public:
	AddCommodity(QWidget *parent = Q_NULLPTR);
	~AddCommodity();
	void display();
private slots :
	void add();
	void cancel();
private:
	Ui::AddCommodity ui;
	OpenDatabase database;
	QString insert;
	QSqlQuery qurey;
};

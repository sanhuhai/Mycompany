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
#include "ui_QueryCommodity.h"

class QueryCommodity : public QDialog
{
	Q_OBJECT

public:
	QueryCommodity(QWidget *parent = Q_NULLPTR);
	~QueryCommodity();
	void init();
	void display();
private slots:
	void search();

private:
	Ui::QueryCommodity ui;
	OpenDatabase database;
	QString insert;
	QSqlQuery qurey;
	QMap<QString, QString>QM;
	QStandardItemModel * model;
};

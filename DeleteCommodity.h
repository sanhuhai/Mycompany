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
#include "ui_DeleteCommodity.h"

class DeleteCommodity : public QDialog
{
	Q_OBJECT

public:
	DeleteCommodity(QWidget *parent = Q_NULLPTR);
	~DeleteCommodity();
	void init();
	void display();
private slots:
	void deleteCommodity();
	void cancel();

private:
	Ui::DeleteCommodity ui;
	OpenDatabase database;
	QString insert;
	QSqlQuery qurey;
	QMap<QString, QString>QM;
	QStandardItemModel * model;
};

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
#include "ui_SaleCommodity.h"

class SaleCommodity : public QDialog
{
	Q_OBJECT

public:
	SaleCommodity(QWidget *parent = Q_NULLPTR);
	~SaleCommodity();
	void display();
private slots:
	void sale();
	void cancel();
private:
	Ui::SaleCommodity ui;
	OpenDatabase database;
	QString insert;
	QSqlQuery qurey;
};

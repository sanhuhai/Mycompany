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
#include "ui_TransferCommodity.h"

class TransferCommodity : public QDialog
{
	Q_OBJECT

public:
	TransferCommodity(QWidget *parent = Q_NULLPTR);
	~TransferCommodity();
	void init();
	void display();
private slots:
	void transfer();
	void cancel();
private:
	Ui::TransferCommodity ui;
	OpenDatabase database;
	QString insert;
	QSqlQuery qurey;
};

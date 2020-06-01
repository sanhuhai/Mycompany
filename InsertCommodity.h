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
#include "ui_InsertCommodity.h"

class InsertCommodity : public QDialog
{
	Q_OBJECT

	public:
		InsertCommodity(QWidget *parent = Q_NULLPTR);
		~InsertCommodity();
		void display();
	private slots:
		void add();
		void cancel();
	private:
		Ui::InsertCommodity ui;
		OpenDatabase database;
		QString insert;
		QSqlQuery qurey;
};

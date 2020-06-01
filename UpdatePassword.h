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
#include "ui_UpdatePassword.h"

class UpdatePassword : public QDialog
{
	Q_OBJECT

public:
	UpdatePassword(QWidget *parent = Q_NULLPTR);
	~UpdatePassword();
	void display();
private slots:
	void change();
	void cancel();
private:
	Ui::UpdatePassword ui;
	OpenDatabase database;
	QString insert;
	QSqlQuery qurey;
};

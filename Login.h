#pragma once
#include <QtSql>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <iostream>
#include <string>
#include <QtWidgets/QMainWindow>
#include <QDialog>
#include "OpenDatabase.h"
#include "ui_Login.h"

class Login : public QDialog
{
	Q_OBJECT

public:
	Login(QWidget *parent = Q_NULLPTR);
	~Login();
	int cnt = 3;
	void openDatabase();
private slots:
	bool LoginAccount();
	void Cancel();
	void display();
private:
	Ui::Login ui;
	QString databaseName, password, qstr;
	QSqlQuery query;
	QSqlDatabase dataBase;
	OpenDatabase opendatabase;
};

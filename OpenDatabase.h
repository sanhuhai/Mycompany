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

class OpenDatabase {
	public :
		OpenDatabase() ;
		~OpenDatabase() ;
		void openDatabase();
		void closeDatabase();
		QSqlDatabase database;
};


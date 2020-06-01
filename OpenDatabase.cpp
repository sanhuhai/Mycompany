#include "OpenDatabase.h"

OpenDatabase::OpenDatabase() {
}

OpenDatabase::~OpenDatabase() {
}

void OpenDatabase::openDatabase() {
	this->database = QSqlDatabase::addDatabase("QMYSQL");
	this->database.setHostName("localhost");
	this->database.setDatabaseName("mycompany");
	this->database.setUserName("root");
	this->database.setPassword("15012277049yqz@#");
}

void OpenDatabase::closeDatabase() {
	this->database.close();
}
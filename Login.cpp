#include "Login.h"
using namespace std;
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
Login::Login(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	display();
}

Login::~Login()
{
}

void Login::openDatabase() {
	this->dataBase = QSqlDatabase::addDatabase("QMYSQL");
	this->dataBase.setHostName("localhost");
	this->dataBase.setDatabaseName("mycompany");
	this->dataBase.setUserName("root");
	this->dataBase.setPassword("15012277049yqz@#");
}

bool Login::LoginAccount() {
	QString account = this->ui.Account->text();
	QString password = this->ui.Password->text();
	qstr = "select employeeNum , password from passwordtable where employeeNum = '" + account + "' and password = '" + password + "' ; ";
	qDebug() << qstr << endl;
	openDatabase();
	if (!dataBase.open()) {
		QMessageBox::information(this, "���ݿ��ʧ��:\n", "���ݿ��ʧ��", "ȷ��");
		exit(0);
	}
	query = QSqlQuery::QSqlQuery(dataBase);
	bool ok = false;
	query.exec(qstr);
	while (query.next()) {
		if (query.value(0).toString() == account && query.value(1).toString() == password) {
			ok = true;
			break;
		}
	}
	//qDebug() << query.value(0).toString() << endl << query.value(1).toString();
	if (ok) {
		QMessageBox::information(this, "ִ�гɹ�", "��ӭ����ϵͳ", "ȷ��");
		this->close();
	}
	else QMessageBox::critical(this, "���ؾ���", "�˻����������������", "ȷ��");
	dataBase.close();
}

void Login::Cancel() {
	exit(0);
}

void Login::display() {
	if (cnt != 0) {
		connect(this->ui.Login_Button, SIGNAL(clicked(bool)), this, SLOT(LoginAccount()));
		cnt--;
	}
	else exit(0);
	connect(this->ui.Cancel_Button, SIGNAL(clicked(bool)), this, SLOT(Cancel()));
}

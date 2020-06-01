#include "UpdatePassword.h"
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
UpdatePassword::UpdatePassword(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	display();
}

UpdatePassword::~UpdatePassword()
{
}

void UpdatePassword::change() {
	this->database.openDatabase();
	this->qurey = QSqlQuery(this->database.database);
	if (!this->database.database.open()) QMessageBox::critical(this, "严重错误", "数据库打开失败", "确认");
	QString account = this->ui.Account->text();
	QString password = this->ui.Password->text();
	insert = "select * from passwordtable where employeeNum = " + account + ";" ;
	qDebug() << insert;
	qurey.exec(insert);
	while (qurey.next()) {
		if (account != qurey.value(0).toString()) QMessageBox::critical(this, "严重错误", "没有该员工", "确认");
		if (password != qurey.value(1).toString()) QMessageBox::critical(this, "严重错误", "密码错误", "确认");
		if (account == qurey.value(0).toString() && password == qurey.value(1).toString()) {
			QString newPassword = this->ui.newPassword->text();
			QString newPassqordAgain = this->ui.newPasswordAgain->text();
			if (newPassword != newPassqordAgain)QMessageBox::critical(this, "严重错误", "新密码不一致", "确认");
			else {
				insert = "update passwordtable set password = '" + newPassword + "' where password = '" + password + "' and employeeNum = " + account + ";";
				qDebug() << insert;
				qurey.exec(insert);
				QMessageBox::information(this,"提示","修改成功","确认");
			}
		}
	}
}

void UpdatePassword::cancel() {
	this->close();
}

void UpdatePassword::display() {
	connect(this->ui.OK, SIGNAL(clicked(bool)), this, SLOT(change()));
	connect(this->ui.Cancel, SIGNAL(clicked(bool)), this, SLOT(cancel()));
}

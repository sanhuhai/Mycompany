#include "insertDepartment.h"
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
insertDepartment::insertDepartment(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	display();
}

insertDepartment::~insertDepartment()
{
}

void insertDepartment::add() {
	QString NUM = this->ui.departmentNum->text();
	QString name = this->ui.departmentName->text();
	QString function = this->ui.departmentFunction->text();
	QString person = this->ui.departmentPrincipal->text();
	this->database.openDatabase();
	if (!this->database.database.open()) QMessageBox::critical(this, "严重错误", "数据库打开失败", "确认");
	qurey = QSqlQuery(this->database.database);
	this->insert = "insert into departmenttable values ('" + NUM + "','" + name + "','"+function + "'," + person + ") ;" ;
	qurey.exec(this->insert);
	QMessageBox::information(this, "提示", "添加成功 ","确认");
}

void insertDepartment::cancel() {
	this->close();
}

void insertDepartment::display() {
	connect(this->ui.AddDepartment, SIGNAL(clicked(bool)), this, SLOT(add()));
	connect(this->ui.Cancel, SIGNAL(clicked(bool)), this, SLOT(cancel()));
}
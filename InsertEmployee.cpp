#include "InsertEmployee.h"
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
InsertEmployee::InsertEmployee(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	display();
}

InsertEmployee::~InsertEmployee()
{
}

void InsertEmployee::signup() {
	QString name = this->ui.Employee_Name->text();
	QString password = this->ui.Password->text();
	QString firmPassword = this->ui.Password_Again->text();
	if (password != firmPassword) QMessageBox::critical(this, "���ش���", "ǰ�����벻һ��", "ȷ��");
	QString sex = "";
	sex = this->ui.Employee_Sex_Man->text();
	sex = this->ui.Employee_Sex_woman->text();
	QString Nationality = this->ui.Employee_Nationality->currentText();
	QString education = this->ui.employee_Education->text();
	QString TEL = this->ui.employee_Tel->text();
	QString salary = this->ui.employee_Salary->text();
	QString bonus= this->ui.employee_Bonus->text();
	QString departmentNum = this->ui.departmet_Num->currentText();
	QString departmentName = this->ui.department_Name->currentText();
	QString position = this->ui.employee_Position->currentText();
	this->database.openDatabase();
	if (!this->database.database.open()) QMessageBox::critical(this, "���ش���", "���ݿ��ʧ��", "ȷ��");
	qurey = QSqlQuery(this->database.database);
	this->insert = "SELECT max(employeeNum) FROM employeetable ;";
	this->qurey.exec(this->insert);
	qurey.next();
	int num = qurey.value(0).toString().toInt()+1;
	qDebug() <<num;
	QString Num = QString::number(num,10);
	this->insert = "insert into employeetable values("+ Num  +",'"+ name + "','" + sex + "','" + Nationality +"','" + education +"','" + TEL +"',"+ salary +"," + bonus + ",'" + departmentNum+ "','"+departmentName +  "','"+ position +"');";
	qDebug() << this->insert;
	if (qurey.exec(insert)) QMessageBox::information(this, "��ʾ", "ע��ɹ�,���Ա������:\n" + Num ,"ȷ��");
	this->insert = "insert into passwordtable values(" + QString(Num) + ",'" + password + "');";
	this->qurey.exec(this->insert);
}

void InsertEmployee::cancel() {
	this->close();
}

void InsertEmployee::display() {
	connect(this->ui.Login, SIGNAL(clicked(bool)), this, SLOT(signup()));
	connect(this->ui.Cancel, SIGNAL(clicked(bool)), this, SLOT(this->cancel()));
}
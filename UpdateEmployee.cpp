#include "UpdateEmployee.h"
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
UpdateEmployee::UpdateEmployee(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	init();
	display();
}

UpdateEmployee::~UpdateEmployee()
{
}

void UpdateEmployee::init() {
	QM[("员工号")] = "employeeNum";
	QM[("姓名")] = "employeeName";
	QM[("性别")] = "employeeSex";
	QM[("民族")] = "employeeNationality";
	QM[("学历")] = "employeeEducation";
	QM[("电话号码")] = "employeeTel";
	QM[("工资")] = "employeeSalary";
	QM[("奖金")] = "employeeBonus";
	QM[("部门编号")] = "departmentNum";
	QM[("部门名称")] = "departmentName";
	QM[("职位")] = "employeePosition";
	this->model = new QStandardItemModel;
	int cl = 0;
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("员工号"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("姓名"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("性别"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("民族"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("学历"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("电话号码"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("工资"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("奖金"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("部门编号"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("部门名称"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("职位"));
	this->ui.tableViewInformation->setModel(model);
}

void UpdateEmployee::updateInformation() {
	this->database.openDatabase();
	this->init();
	QString oldInformation = this->ui.oldInformation->text();
	QString updateInformation = this->ui.updateInformation->text();
	QString index = this->ui.choice->currentText();
	if (index != "员工号" && index != "工资" && index != "奖金") {
		oldInformation = "'" + oldInformation + "'";
		updateInformation = "'" + updateInformation + "'";
	}
	this->qurey = QSqlQuery(this->database.database);
	if (!this->database.database.open()) QMessageBox::critical(this, "严重错误", "数据库打开失败", "确认");
	else QMessageBox::information(this, "提示", "数据库打开成功", "确认");
	select = "update employeetable set " + QM[index] + " = " + updateInformation + "where " + QM[index] + " = " + oldInformation + " ;";
	qDebug() << QM[index] << endl << oldInformation;
	qurey.exec(select);
	select = "select * from employeetable ;";
	qurey.exec(select);
	int row = 0;
	while (qurey.next()) {
		for (int i = 0; i < qurey.record().count(); i++) this->model->setItem(row, i, new QStandardItem(qurey.value(i).toString()));
		row++;
	}
	this->database.closeDatabase();
}

void UpdateEmployee::display() {
	connect(this->ui.updateButton, SIGNAL(clicked(bool)), this, SLOT(updateInformation()));
}
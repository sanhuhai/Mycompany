#include "UpdateDepartment.h"
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
UpdateDepartment::UpdateDepartment(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	display();
}

UpdateDepartment::~UpdateDepartment()
{
}

void UpdateDepartment::init() {
	QM[("部门编号")] = "departmentNum";
	QM[("部门名称")] = "departmentName";
	QM[("部门职能")] = "departmentFunction";
	QM[("部门负责人")] = "departmentPrincipal";
	this->model = new QStandardItemModel;
	int cl = 0;
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("部门编号"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("部门名称"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("部门职能"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("部门负责人"));
	this->ui.tableViewInformation->setModel(model);
}

void UpdateDepartment::update() {
	init();
	this->database.openDatabase();
	if (!this->database.database.open()) QMessageBox::critical(this, "严重错误", "数据库打开失败", "确认");
	//else QMessageBox::information(this, "提示", "数据库打开成功", "确认");
	this->qurey = QSqlQuery(this->database.database);
	QString index = this->ui.choice->currentText();
	QString oldInformation = this->ui.oldInformation->text();
	QString updateInformation = this->ui.updateInformation->text();
	
	if (index != "负责人编号") {
		oldInformation = "'" + oldInformation + "'";
		updateInformation = "'" + updateInformation + "'";
	}
	insert = "update departmenttable set " + QM[index] + " = " + updateInformation + "where " + QM[index] + " = " + oldInformation + " ;";
	//qDebug() << QM[index] << endl << oldInformation;
	qDebug() << insert;
	qurey.exec(insert);
	insert = "select * from departmenttable ;";
	qurey.exec(insert);
	int row = 0;
	while (qurey.next()) {
		for (int i = 0; i < qurey.record().count(); i++) this->model->setItem(row, i, new QStandardItem(qurey.value(i).toString()));
		row++;
	}
	this->database.closeDatabase();
}
void UpdateDepartment::display() {
	connect(this->ui.updateButton, SIGNAL(clicked(bool)), this, SLOT(update()));
}
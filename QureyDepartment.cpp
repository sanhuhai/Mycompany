#include "QureyDepartment.h"
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
QureyDepartment::QureyDepartment(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	display();
}

QureyDepartment::~QureyDepartment()
{
}

void QureyDepartment::init() {
	QM[("部门编号")] = "departmentNum";
	QM[("部门名称")] = "departmentName";
	QM[("部门职能")] = "departmentFunction";
	QM[("负责人编号")] = "departmentPrincipal";
	this->model = new QStandardItemModel;
	int cl = 0;
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("部门编号"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("部门名称"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("部门职能"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("负责人编号"));
	this->ui.tableViewInformation->setModel(model);
}

void QureyDepartment::search() {
	this->database.openDatabase();
	if (!this->database.database.open()) QMessageBox::critical(this, "严重错误", "数据库打开失败", "确认");
	this->init();
	QString information = this->ui.inputInformation->text();
	QString index = this->ui.choice->currentText();
	if (index != "负责人编号") information = "'" + information + "'";
	this->qurey = QSqlQuery(this->database.database);
	insert = "select * from departmenttable where " + QM[index] + " = " + information + " ;";
	qDebug() << insert;
	qurey.exec(insert);
	int row = 0;
	while (qurey.next()) {
		for (int i = 0; i < qurey.record().count(); i++) this->model->setItem(row, i, new QStandardItem(qurey.value(i).toString()));
		row++;
	}
}

void QureyDepartment::display() {
	connect(this->ui.searchButton, SIGNAL(clicked(bool)), this, SLOT(search()));
}
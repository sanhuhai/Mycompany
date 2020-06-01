#include "DeleteEmployee.h"
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
DeleteEmployee::DeleteEmployee(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	init();
	display();
}

DeleteEmployee::~DeleteEmployee()
{
}


void DeleteEmployee::init() {
	QM[("Ա����")] = "employeeNum";
	QM[("����")] = "employeeName";
	QM[("�Ա�")] = "employeeSex";
	QM[("����")] = "employeeNationality";
	QM[("ѧ��")] = "employeeEducation";
	QM[("�绰����")] = "employeeTel";
	QM[("����")] = "employeeSalary";
	QM[("����")] = "employeeBonus";
	QM[("���ű��")] = "departmentNum";
	QM[("��������")] = "departmentName";
	QM[("ְλ")] = "employeePosition";
	this->model = new QStandardItemModel;
	int cl = 0;
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("Ա����"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("����"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("�Ա�"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("����"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("ѧ��"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("�绰����"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("����"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("����"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("���ű��"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("��������"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("ְλ"));
	this->ui.tableViewInformation->setModel(model);
}

void DeleteEmployee::deleteInformation() {
	this->database.openDatabase();
	this->init();
	QString information = this->ui.inputInformation->text();
	QString index = this->ui.choice->currentText();
	if (index != "Ա����" && index != "����" && index != "����")  information = "'" + information + "'";
	this->qurey = QSqlQuery(this->database.database);
	if (!this->database.database.open()) QMessageBox::critical(this,"���ش���", "���ݿ��ʧ��", "ȷ��");
	select = "delete from employeetable where " + QM[index] + " = " + information + " ;";
	qDebug() << select;
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

void DeleteEmployee::display() {
	connect(this->ui.deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteInformation()));
}
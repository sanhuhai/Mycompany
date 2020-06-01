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

void UpdateEmployee::updateInformation() {
	this->database.openDatabase();
	this->init();
	QString oldInformation = this->ui.oldInformation->text();
	QString updateInformation = this->ui.updateInformation->text();
	QString index = this->ui.choice->currentText();
	if (index != "Ա����" && index != "����" && index != "����") {
		oldInformation = "'" + oldInformation + "'";
		updateInformation = "'" + updateInformation + "'";
	}
	this->qurey = QSqlQuery(this->database.database);
	if (!this->database.database.open()) QMessageBox::critical(this, "���ش���", "���ݿ��ʧ��", "ȷ��");
	else QMessageBox::information(this, "��ʾ", "���ݿ�򿪳ɹ�", "ȷ��");
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
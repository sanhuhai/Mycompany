#include "QueryInformation.h"
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
QueryInformation::QueryInformation(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	init();
	display();

}

QueryInformation::~QueryInformation()
{
}

void QueryInformation::init() {
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
	this->model->setHorizontalHeaderItem( cl++,new QStandardItem("Ա����"));
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

void QueryInformation::search() {
	this->database.openDatabase();
	if (!this->database.database.open()) QMessageBox::critical(this, "���ش���", "���ݿ��ʧ��", "ȷ��");
	this->init();
	QString information = this->ui.inputInformation->text();
	QString index = this->ui.choice->currentText();
	this->qurey = QSqlQuery(this->database.database);
	if (index != "Ա����" && index != "����" && index != "����")  information = "'" + information + "'";
	select = "select * from employeetable where " + QM[index] + " = "+ information + " ;";
	qurey.exec(select);
	int row = 0;
	while (qurey.next()) {
		for (int i = 0; i < qurey.record().count(); i++) this->model->setItem(row, i ,new QStandardItem(qurey.value(i).toString()));
		row ++ ;
	}
}

void QueryInformation::display() {
	connect(this->ui.searchButton, SIGNAL(clicked(bool)), this, SLOT(search()));
}
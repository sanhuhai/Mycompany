#include "DeleteDepartment.h"
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
DeleteDepartment::DeleteDepartment(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	init();
	display();
}

DeleteDepartment::~DeleteDepartment()
{
}

void DeleteDepartment::init() {
	QM[("���ű��")] = "departmentNum";
	QM[("��������")] = "departmentName";
	QM[("����ְ��")] = "departmentFunction";
	QM[("���Ÿ�����")] = "departmentPrincipal";
	this->model = new QStandardItemModel;
	int cl = 0;
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("���ű��"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("��������"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("����ְ��"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("���Ÿ�����"));
	this->ui.tableViewInformation->setModel(model);
}

void DeleteDepartment::del() {
	init();
	this->database.openDatabase();
	if (!this->database.database.open()) QMessageBox::critical(this, "���ش���", "���ݿ��ʧ��", "ȷ��");
	//else QMessageBox::information(this, "��ʾ", "���ݿ�򿪳ɹ�", "ȷ��");
	this->qurey = QSqlQuery(this->database.database);
	QString index = this->ui.choice->currentText();
	QString inputInformation = this->ui.inputInformation->text();

	if (index != "�����˱��") inputInformation = "'" + inputInformation + "'";
	insert = "delete from departmenttable where " + QM[index] + " = " + inputInformation + " ;";
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

void DeleteDepartment::display() {
	connect(this->ui.deleteButton, SIGNAL(clicked(bool)), this, SLOT(del()));
}

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

void UpdateDepartment::update() {
	init();
	this->database.openDatabase();
	if (!this->database.database.open()) QMessageBox::critical(this, "���ش���", "���ݿ��ʧ��", "ȷ��");
	//else QMessageBox::information(this, "��ʾ", "���ݿ�򿪳ɹ�", "ȷ��");
	this->qurey = QSqlQuery(this->database.database);
	QString index = this->ui.choice->currentText();
	QString oldInformation = this->ui.oldInformation->text();
	QString updateInformation = this->ui.updateInformation->text();
	
	if (index != "�����˱��") {
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
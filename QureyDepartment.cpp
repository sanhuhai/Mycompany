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
	QM[("���ű��")] = "departmentNum";
	QM[("��������")] = "departmentName";
	QM[("����ְ��")] = "departmentFunction";
	QM[("�����˱��")] = "departmentPrincipal";
	this->model = new QStandardItemModel;
	int cl = 0;
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("���ű��"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("��������"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("����ְ��"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("�����˱��"));
	this->ui.tableViewInformation->setModel(model);
}

void QureyDepartment::search() {
	this->database.openDatabase();
	if (!this->database.database.open()) QMessageBox::critical(this, "���ش���", "���ݿ��ʧ��", "ȷ��");
	this->init();
	QString information = this->ui.inputInformation->text();
	QString index = this->ui.choice->currentText();
	if (index != "�����˱��") information = "'" + information + "'";
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
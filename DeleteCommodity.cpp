#include "DeleteCommodity.h"
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
DeleteCommodity::DeleteCommodity(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	init();
	display();
}

DeleteCommodity::~DeleteCommodity()
{
}

void DeleteCommodity::init() {
	QM[("���")] = "commodityNum";
	QM[("����")] = "commodityName";
	QM[("����")] = "commodityClassify";
	QM[("��;")] = "commodityUsage";
	QM[("�����")] = "commodityStock";
	QM[("�ֿ����ڵ�")] = "packageLocation";
	QM[("�ֿ���")] = "packageNum";
	this->model = new QStandardItemModel;
	int cl = 0;
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("���"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("����"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("����"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("��;"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("�����"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("�ֿ����ڵ�"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("�ֿ���"));
	this->ui.tableViewInformation->setModel(model);
}

void DeleteCommodity::deleteCommodity() {
	this->database.openDatabase();
	if (!this->database.database.open()) QMessageBox::critical(this, "���ش���", "���ݿ��ʧ��", "ȷ��");
	this->init();
	QString information = this->ui.inputInformation->text();
	QString index = this->ui.choice->currentText();
	if (index != "�����") information = "'" + information + "'";
	this->qurey = QSqlQuery(this->database.database);
	insert = "delete from commoditytable where " + QM[index] + " = " + information + " ;";
	qDebug() << insert;
	qurey.exec(insert);
	insert = "select * from commoditytable ;";
	qurey.exec(insert);
	int row = 0;
	while (qurey.next()) {
		for (int i = 0; i < qurey.record().count(); i++) this->model->setItem(row, i, new QStandardItem(qurey.value(i).toString()));
		row++;
	}
}

void DeleteCommodity::cancel() {
	this->close();
}

void DeleteCommodity::display() {
	connect(this->ui.deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteCommodity()));
}
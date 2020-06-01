#include "QueryCommodity.h"
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
QueryCommodity::QueryCommodity(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	display();
}

QueryCommodity::~QueryCommodity()
{
}

void QueryCommodity::init() {
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

void QueryCommodity::search() {
	this->database.openDatabase();
	if (!this->database.database.open()) QMessageBox::critical(this, "���ش���", "���ݿ��ʧ��", "ȷ��");
	//else QMessageBox::information(this, "��ʾ", "���ݿ�򿪳ɹ�", "ȷ��");
	this->qurey = QSqlQuery(this->database.database);
	QString inputInformation = this->ui.inputInformation->text();
	QString index = this->ui.choice->currentText();
	if (inputInformation != "�����") inputInformation = "'" + inputInformation + "'";
	insert = "select * from  commoditytable where " + QM[index] + " = " + inputInformation + " ;";
	qDebug() << QM[index] << endl << inputInformation;
	//qurey.exec(insert);
	//insert = "select * from commoditytable ;";
	qurey.exec(insert);
	init();
	int row = 0;
	while (qurey.next()) {
		for (int i = 0; i < qurey.record().count(); i++) this->model->setItem(row, i, new QStandardItem(qurey.value(i).toString()));
		row++;
	}
	this->database.closeDatabase();
}

void QueryCommodity::display() {
	connect(this->ui.searchButton, SIGNAL(clicked(bool)), this, SLOT(search()));
}
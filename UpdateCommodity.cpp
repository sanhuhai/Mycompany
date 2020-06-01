#include "UpdateCommodity.h"
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
UpdateCommodity::UpdateCommodity(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	init();
	display();
}

UpdateCommodity::~UpdateCommodity()
{
}

void UpdateCommodity::init() {
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

void UpdateCommodity::update() {
	this->database.openDatabase();
	;
	if (!this->database.database.open()) QMessageBox::critical(this, "���ش���", "���ݿ��ʧ��", "ȷ��");
	//else QMessageBox::information(this, "��ʾ", "���ݿ�򿪳ɹ�", "ȷ��");
	this->qurey = QSqlQuery(this->database.database);
	QString oldInformation = this->ui.oldInformation->text();
	QString updateInformation = this->ui.updateInformation->text();
	QString index = this->ui.choice->currentText();
	if (oldInformation != "�����") {
		oldInformation = "'" + oldInformation + "'";
		updateInformation = "'" + updateInformation + "'";
	}
	insert = "update commoditytable set " + QM[index] + " = " + updateInformation + "where " + QM[index] + " = " + oldInformation + " ;";
	//qDebug() << QM[index] << endl << oldInformation;
	qurey.exec(insert);
	insert = "select * from commoditytable ;";
	qurey.exec(insert);
	int row = 0;
	while (qurey.next()) {
		for (int i = 0; i < qurey.record().count(); i++) this->model->setItem(row, i, new QStandardItem(qurey.value(i).toString()));
		row++;
	}
	this->database.closeDatabase();
}
void UpdateCommodity::display() {
	connect(this->ui.updateButton, SIGNAL(clicked(bool)), this, SLOT(update()));
 }
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
	QM[("编号")] = "commodityNum";
	QM[("名称")] = "commodityName";
	QM[("分类")] = "commodityClassify";
	QM[("用途")] = "commodityUsage";
	QM[("库存量")] = "commodityStock";
	QM[("仓库所在地")] = "packageLocation";
	QM[("仓库编号")] = "packageNum";
	this->model = new QStandardItemModel;
	int cl = 0;
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("编号"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("名称"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("分类"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("用途"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("库存量"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("仓库所在地"));
	this->model->setHorizontalHeaderItem(cl++, new QStandardItem("仓库编号"));
	this->ui.tableViewInformation->setModel(model);
}

void DeleteCommodity::deleteCommodity() {
	this->database.openDatabase();
	if (!this->database.database.open()) QMessageBox::critical(this, "严重错误", "数据库打开失败", "确认");
	this->init();
	QString information = this->ui.inputInformation->text();
	QString index = this->ui.choice->currentText();
	if (index != "库存量") information = "'" + information + "'";
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
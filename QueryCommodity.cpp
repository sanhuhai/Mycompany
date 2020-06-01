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

void QueryCommodity::search() {
	this->database.openDatabase();
	if (!this->database.database.open()) QMessageBox::critical(this, "严重错误", "数据库打开失败", "确认");
	//else QMessageBox::information(this, "提示", "数据库打开成功", "确认");
	this->qurey = QSqlQuery(this->database.database);
	QString inputInformation = this->ui.inputInformation->text();
	QString index = this->ui.choice->currentText();
	if (inputInformation != "库存量") inputInformation = "'" + inputInformation + "'";
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
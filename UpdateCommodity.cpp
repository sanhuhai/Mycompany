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

void UpdateCommodity::update() {
	this->database.openDatabase();
	;
	if (!this->database.database.open()) QMessageBox::critical(this, "严重错误", "数据库打开失败", "确认");
	//else QMessageBox::information(this, "提示", "数据库打开成功", "确认");
	this->qurey = QSqlQuery(this->database.database);
	QString oldInformation = this->ui.oldInformation->text();
	QString updateInformation = this->ui.updateInformation->text();
	QString index = this->ui.choice->currentText();
	if (oldInformation != "库存量") {
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
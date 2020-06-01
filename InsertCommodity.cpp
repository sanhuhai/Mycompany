#include "InsertCommodity.h"
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
InsertCommodity::InsertCommodity(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	display();
}

InsertCommodity::~InsertCommodity()
{
}

void InsertCommodity::add() {
	QString NUM = this->ui.commodityNum->text();
	QString name = this->ui.commodityName->text();
	QString classify = this->ui.commodityClassify->currentText();
	QString usage = this->ui.commodityUsage->text();
	QString stock = this->ui.commodityStock->text();
	QString packageLocation = this->ui.packageLocation->currentText();
	QString packageNum = this->ui.packageNum->currentText();
	this->database.openDatabase();
	if (!this->database.database.open()) QMessageBox::critical(this, "严重错误", "数据库打开失败", "确认");
	qurey = QSqlQuery(this->database.database);
	this->insert = "insert into commoditytable values('" + NUM + "','" + name + "','" + classify + "','" + usage + "'," + stock + ",'" + packageLocation + "','" + packageNum + "');";
	qDebug() << this->insert;
	if (qurey.exec(insert)) QMessageBox::information(this, "提示", "数据插入成功", "确认");
}

void InsertCommodity::cancel() {
	this->close();
}

void InsertCommodity::display() {
	connect(this->ui.AddCommodity, SIGNAL(clicked(bool)), this, SLOT(add()));
	connect(this->ui.Cancel, SIGNAL(clicked(bool)), this, SLOT(this->cancel()));
}
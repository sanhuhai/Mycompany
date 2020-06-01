#include "AddCommodity.h"
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
AddCommodity::AddCommodity(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	display();
}

AddCommodity::~AddCommodity()
{
}

void AddCommodity::add() {
	this->database.openDatabase();
	this->qurey = QSqlQuery(this->database.database);
	if (!this->database.database.open()) QMessageBox::critical(this, "严重错误", "数据库打开失败", "确认");
	QString PL = this->ui.packageLocation->currentText();
	QString PN = this->ui.packageNum->currentText();
	QString CNUM = this->ui.commodityNum->text();
	QString CNAME = this->ui.commodityName->text();
	QString CPV = this->ui.commodityPurchaseVolume->text();
	QString CPUP = this->ui.commodityPurchaseUnitPprice->text();
	qDebug() << PL << endl << PN << endl << CNUM << endl << CNAME << endl << CPV << endl << CPUP;
	insert = "select commodityStock from recordtable  where  packageLocation = '" + PL + "' and packageNum = '" + PN + "' and commodityNum = '" + CNUM + "';";
	if (!qurey.exec(insert)); {
		insert = "insert into recordtable values('"+ PL +"','" + PN  + "','" + CNUM  +"','" + CNAME + "',0,0,0,0,0,0,0); ";
		qurey.exec(insert);
	}
	QString stock;
	while(qurey.next() ) stock = qurey.value(0).toString();
	double STO = CPV.toDouble() + stock.toDouble();
	double price = STO * CPUP.toDouble();
	QString STOCK = QString::number(STO);
	QString PRICE = QString::number(price,'f', 10);
	

	insert = "update recordtable set commodityPurchaseVolume = " + CPV + " ,commodityPurchaseUnitPprice =  "+ CPUP + " ,commodityPurchaseMoney =  " + PRICE + " ,commodityStock =  " + STOCK + " where  packageLocation = '" + PL + "' and packageNum = '" + PN + "' and commodityNum = '" +CNUM + "';";
	qDebug() << insert;
		QMessageBox::information(this, "提示", "进货成功", "确定");
		insert = "update commoditytable set commodityStock =  " + STOCK + " where  packageLocation = '" + PL + "' and packageNum = '" + PN + "' and commodityNum = '" + CNUM + "';";
		qDebug() << insert;
		qurey.exec(insert);
}

void AddCommodity::cancel() {
	this->close();
}

void AddCommodity::display() {
	connect(this->ui.OK, SIGNAL(clicked(bool)), this, SLOT(add()));
	connect(this->ui.Cancel, SIGNAL(clicked(bool)), this, SLOT(Cancel()));
}
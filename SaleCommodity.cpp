#include "SaleCommodity.h"

#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
SaleCommodity::SaleCommodity(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	display();
}

SaleCommodity::~SaleCommodity()
{
}

void SaleCommodity::sale() {
	this->database.openDatabase();
	this->qurey = QSqlQuery(this->database.database);
	if (!this->database.database.open()) QMessageBox::critical(this, "���ش���", "���ݿ��ʧ��", "ȷ��");
	QString PL = this->ui.packageLocation->currentText();
	QString PN = this->ui.packageNum->currentText();
	QString CNUM = this->ui.commodityNum->text();
	QString CNAME = this->ui.commodityName->text();
	QString CPV = this->ui.commoditySales->text();
	QString CPUP = this->ui.commoditySalesUnitPrice->text();
	qDebug() << PL << endl << PN << endl << CNUM << endl << CNAME << endl << CPV << endl << CPUP;
	insert = "select commodityStock from recordtable  where  packageLocation = '" + PL + "' and packageNum = '" + PN + "' and commodityNum = '" + CNUM + "';";
	qurey.exec(insert);
	QString stock;
	while (qurey.next()) stock = qurey.value(0).toString();
	double STO = stock.toDouble() - CPV.toDouble();
	if (STO < 0) {
		QMessageBox::critical(this, "����", "���С��������������ʧ��", "ȷ��");
		this->close();
	}
	QString STOCK = QString::number(STO);
	insert = "update recordtable set commoditySales = " + CPV + " ,commoditySalesUnitPrice =  " + CPUP + " ,commodityStock =  " + STOCK + " where  packageLocation = '" + PL + "' and packageNum = '" + PN + "' and commodityNum = '" + CNUM + "';";
	qDebug() << insert;
	if (qurey.exec(insert)) {
		QMessageBox::information(this, "��ʾ", "���۳ɹ�", "ȷ��");
		insert = "update commoditytable set commodityStock =  " + STOCK + " where  packageLocation = '" + PL + "' and packageNum = '" + PN + "' and commodityNum = '" + CNUM + "';";
		qDebug() << insert;
		qurey.exec(insert);
	}
	else QMessageBox::critical(this, "����", "����ʧ��", "ȷ��");
}

void SaleCommodity::cancel() {
	this->close();
}

void SaleCommodity::display() {
	connect(this->ui.OK, SIGNAL(clicked(bool)), this, SLOT(sale()));
	connect(this->ui.Cancel, SIGNAL(clicked(bool)), this, SLOT(Cancel()));
}
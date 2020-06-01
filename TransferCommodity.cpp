#include "TransferCommodity.h"
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
TransferCommodity::TransferCommodity(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	display();
}

TransferCommodity::~TransferCommodity()
{
}

void TransferCommodity::transfer() {
	this->database.openDatabase();
	this->qurey = QSqlQuery(this->database.database);
	if (!this->database.database.open()) QMessageBox::critical(this, "���ش���", "���ݿ��ʧ��", "ȷ��");
	QString packageLocationFrom = this->ui.packageLocationFrom->currentText();
	QString packageNumFrom = this->ui.packageNumFrom->currentText();
	QString commodityNum = this->ui.commodityNum->text();
	QString information = this->ui.inputInformation->text();
	QString packageLocationTo = this->ui.packageLocationTo->currentText();
	QString packageNumTo = this->ui.packageNumTo->currentText();
	if (packageLocationFrom == packageLocationTo && packageNumFrom == packageNumTo) {
		QMessageBox::information(this, "��ʾ", "ͬһ���ֿ⣬����ת��", "ȷ��");
		exit(0);
	}
	insert = "select commodityStock from recordtable  where  packageLocation = '" + packageLocationFrom + "' and packageNum = '" + packageNumFrom + "' and commodityNum = '" + commodityNum + "';";
	qurey.exec(insert);
	QString stock;
	while (qurey.next()) stock = qurey.value(0).toString();
	double STO = stock.toDouble();
	if (STO == 0) {
		QMessageBox::information(this, "����", "�����Ϊ0������ת��", "ȷ��");
		exit(0);
	}
	QString STOCK;
	if (STO < information.toDouble()) {
		QMessageBox::information(this, "��ʾ", "�����С��ת����,ȫ��ת��", "ȷ��"); {
			information = stock;
			STOCK = "0";
		}
		
	}
	else {
		double temp = (STO-information.toDouble());
		STOCK = QString::number(temp,'f', 10);
		qDebug() << STOCK;
	}
	insert = "select commodityStock from recordtable  where  packageLocation = '" + packageLocationTo + "' and packageNum = '" + packageNumTo + "' and commodityNum = '" + commodityNum + "';";
	qurey.exec(insert);
	QString newInformation;
	while (qurey.next()) newInformation = qurey.value(0).toString();
	qDebug() << newInformation;
	if (newInformation == "" ) {
		insert = "select * from commoditytable where commodityNum = '" + commodityNum + "';";
		qurey.exec(insert);
		qurey.next();
		QString commodityName = qurey.value(1).toString();
		QString commodityClassify =  qurey.value(2).toString();
		QString commodityUsage = qurey.value(3).toString();
		QString commodityStock = qurey.value(4).toString();
		QString packageLocation = qurey.value(5).toString();
		QString packageNum = qurey.value(6).toString();
		insert = " insert into  commoditytable values('" + commodityNum + "','" + commodityName + "','" + commodityClassify + "','" + commodityUsage  + "'," + STOCK + ",'" +  packageLocationTo + "','" + packageNumTo + "');";
		qurey.exec(insert);
		insert = "insert into  recordtable values('"+ packageLocationTo + "','" + packageNumTo + "','" + commodityNum + "','" + commodityName + "',0,0,0,0,0);" ;
		qurey.exec(insert);
	}
	double temp = newInformation.toDouble() + information.toDouble();
	newInformation = QString::number(temp, 'f', 10);

	insert = "update recordtable set commodityStock = " + STOCK +  " where  packageLocation = '" + packageLocationFrom + "' and packageNum = '" + packageNumFrom + "' and commodityNum = '" + commodityNum + "';";
	qurey.exec(insert);
	qDebug() << insert;
	insert = "update recordtable set commodityStock = " + newInformation + " where  packageLocation = '" + packageLocationTo + "' and packageNum = '" + packageNumTo + "' and commodityNum = '" + commodityNum + "';";
	qurey.exec(insert);
	qDebug() << insert;
	if (qurey.exec(insert)) {
		insert = "update commoditytable set commodityStock =  " + STOCK + " where  packageLocation = '" + packageLocationFrom + "' and packageNum = '" + packageNumFrom + "' and commodityNum = '" + commodityNum + "';";
		qurey.exec(insert);
		qDebug() << insert;
		insert = "update commoditytable set commodityStock =  " + newInformation + " where  packageLocation = '" + packageLocationTo + "' and packageNum = '" + packageNumTo + "' and commodityNum = '" + commodityNum + "';";
		qurey.exec(insert);
		qDebug() << insert;
		QMessageBox::information(this, "��ʾ", "ת�Ƴɹ�", "ȷ��");
	}
	else QMessageBox::critical(this, "����", "ת��ʧ��", "ȷ��");
	
	
}

void TransferCommodity::cancel() {
	this->close();
}

void TransferCommodity::display() {
	connect(this->ui.OK, SIGNAL(clicked(bool)), this, SLOT(transfer()));
	connect(this->ui.Cancel, SIGNAL(clicked(bool)), this, SLOT(cancel()));
}
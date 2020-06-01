#include "MyCompany.h"

#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif

MyCompany::MyCompany(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	display();
}

void MyCompany::LoginAc(){
	this->LG.show();
	this->ui.LoginButton->setText("ÒÑµÇÂ¼");
	this->ok = true;
	display();
}

void MyCompany::QureyFm() {
	this->QF.show();
}

void MyCompany::InsertEm() {
	this->IE.show();
}

void MyCompany::DeleteEm() {
	this->DE.show();
}

void MyCompany::UpdateEm() {
	this->UE.show();
}

void MyCompany::InsertCo() {
	this->IC.show();
}

void MyCompany::DeleteCo() {
	this->DC.show();
}

void MyCompany::UpdateCo() {
	this->UC.show();
}

void MyCompany::QueryCo() {
	this->QC.show();
}

void MyCompany::insertDe() {
	this->ID.show();
}

void MyCompany::UpdateDe() {
	this->UD.show();
}

void  MyCompany::QureyDe() {
	this->QD.show();
}

void  MyCompany::DeleteDe() {
	this->DD.show();
}

void  MyCompany::UpdatePa() {
	this->UP.show();
}

void  MyCompany::AddCo() {
	this->AC.show();
}

void  MyCompany::SaleCo() {
	this->SC.show();
}
void  MyCompany::TransferCo() {
	this->TC.show();
}

void MyCompany::display() {
	if (!ok)  {
		connect(this->ui.LoginButton, SIGNAL(clicked()), this, SLOT(LoginAc()));
	}
		connect(this->ui.actionAddEmployee, SIGNAL(triggered()), this, SLOT(InsertEm()));
		connect(this->ui.actionAddCommoditytable, SIGNAL(triggered()), this, SLOT(InsertCo()));
		connect(this->ui.actionAddDepartment, SIGNAL(triggered()), this, SLOT(insertDe()));
		connect(this->ui.actionUpdateEmployee, SIGNAL(triggered()), this, SLOT(UpdateEm()));
		connect(this->ui.actionUpdateCommodity, SIGNAL(triggered()), this, SLOT(UpdateCo()));
		connect(this->ui.actionUpdateDepartment, SIGNAL(triggered()), this, SLOT(UpdateDe()));
		connect(this->ui.actionQueryEmployee, SIGNAL(triggered()), this, SLOT(QureyFm()));
		connect(this->ui.actionQueryCommodity, SIGNAL(triggered()), this, SLOT(QueryCo()));
		connect(this->ui.actionQureyDepartment, SIGNAL(triggered()), this, SLOT(QureyDe()));
		connect(this->ui.actionDeleteEmployee, SIGNAL(triggered()), this, SLOT(DeleteEm()));
		connect(this->ui.actionDeleteCommodity, SIGNAL(triggered()), this, SLOT(DeleteCo()));
		connect(this->ui.actionDeleteDepartment, SIGNAL(triggered()), this, SLOT(DeleteDe()));
		connect(this->ui.actionAddCommodity, SIGNAL(triggered()), this, SLOT(AddCo()));
		connect(this->ui.actionSaleCommodity, SIGNAL(triggered()), this, SLOT(SaleCo()));
		connect(this->ui.actionTransferCommodity, SIGNAL(triggered()), this, SLOT(TransferCo()));
		connect(this->ui.actionUpdatePassword, SIGNAL(triggered()), this, SLOT(UpdatePa()));

		
		/*connect(this->ui.actionAddEmployee, SIGNAL(triggered()), this, SLOT(InsertEm()));
		connect(this->ui.actionAddCommoditytable, SIGNAL(triggered()), this, SLOT(InsertCo()));
		connect(this->ui.actionAddDepartment, SIGNAL(triggered()), this, SLOT(insertDe()));
		connect(this->ui.actionUpdateEmployee, SIGNAL(triggered()), this, SLOT(UpdateEm()));
		connect(this->ui.actionUpdateCommodity, SIGNAL(triggered()), this, SLOT(UpdateCo()));
		connect(this->ui.actionUpdateDepartment, SIGNAL(triggered()), this, SLOT(UpdateDe()));
		connect(this->ui.actionQueryEmployee, SIGNAL(triggered()), this, SLOT(QureyFm()));
		connect(this->ui.actionQueryCommodity, SIGNAL(triggered()), this, SLOT(QueryCo()));
		connect(this->ui.actionQureyDepartment, SIGNAL(triggered()), this, SLOT(QureyDe()));
		connect(this->ui.actionDeleteEmployee, SIGNAL(triggered()), this, SLOT(DeleteEm()));
		connect(this->ui.actionDeleteCommodity, SIGNAL(triggered()), this, SLOT(DeleteCo()));
		connect(this->ui.actionDeleteDepartment, SIGNAL(triggered()), this, SLOT(DeleteDe()));
		connect(this->ui.actionAddCommodity, SIGNAL(triggered()), this, SLOT(AddCo()));
		connect(this->ui.actionSaleCommodity, SIGNAL(triggered()), this, SLOT(SaleCo()));
		connect(this->ui.actionTransferCommodity, SIGNAL(triggered()), this, SLOT(TransferCo()));
		connect(this->ui.actionUpdatePassword, SIGNAL(triggered()), this, SLOT(UpdatePa()));*/
}

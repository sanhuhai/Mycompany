#pragma once
#include "Login.h"
#include "QueryInformation.h"
#include "InsertEmployee.h"
#include "DeleteEmployee.h"
#include "UpdateEmployee.h"
#include "InsertCommodity.h"
#include "DeleteCommodity.h"
#include "UpdateCommodity.h"
#include "QueryCommodity.h"
#include "insertDEpartment.h"
#include "UpdateDepartment.h"
#include "QureyDepartment.h"
#include "DeleteDepartment.h"
#include "UpdatePassword.h"
#include "AddCommodity.h"
#include "SaleCommodity.h"
#include "TransferCommodity.h"
#include "QueryInformation.h"
#include "ui_MyCompany.h"
#include <QtWidgets/QMainWindow>

class MyCompany : public QMainWindow
{
	Q_OBJECT

	public:
		MyCompany(QWidget *parent = Q_NULLPTR);
		void display();
	private slots:
		void LoginAc();
		void QureyFm();
		void InsertEm();
		void DeleteEm();
		void UpdateEm();
		void InsertCo();
		void DeleteCo();
		void UpdateCo();
		void QueryCo();
		void insertDe();
		void UpdateDe();
		void QureyDe();
		void DeleteDe();
		void UpdatePa();
		void AddCo();
		void SaleCo();
		void TransferCo();
	private:
		Ui::MyCompany ui;
		Login LG;
		QueryInformation QF;
		InsertEmployee IE;
		DeleteEmployee DE;
		UpdateEmployee UE;
		InsertCommodity IC;
		DeleteCommodity DC;
		UpdateCommodity UC;
		QueryCommodity QC;
		insertDepartment ID;
		UpdateDepartment UD;
		QureyDepartment QD;
		DeleteDepartment DD;
		UpdatePassword UP;
		AddCommodity AC;
		SaleCommodity SC;
		TransferCommodity TC;
		int ok = false;
};

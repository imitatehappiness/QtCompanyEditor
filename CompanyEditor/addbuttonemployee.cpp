#include "addbuttonemployee.h"
#include "ui_addbuttonemployee.h"

#include "employeewidgeteditor.h"
#include "employee.h"
#include "company.h"

AddButtonEmployee::AddButtonEmployee(Department& department,QWidget *parent ) :
    QWidget(parent),
    mDepartment(department),
    ui(new Ui::AddButtonEmployee){

    ui->setupUi(this);
}

AddButtonEmployee::~AddButtonEmployee(){
    delete ui;
}

void AddButtonEmployee::on_pB_addEmployee_clicked(){
     EmployeeWidgetEditor ewe;
     Employee employee = ewe.getEmployee();
     if(ewe.getIsApply()){
         mDepartment.addEmployee(employee);
     }
}

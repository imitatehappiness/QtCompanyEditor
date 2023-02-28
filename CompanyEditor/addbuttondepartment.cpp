#include "addbuttondepartment.h"
#include "ui_addbuttondepartment.h"
#include "department.h"
#include "company.h"
AddButtonDepartment::AddButtonDepartment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddButtonDepartment){

    ui->setupUi(this);
}

AddButtonDepartment::~AddButtonDepartment(){
    delete ui;
}

void AddButtonDepartment::on_pB_addDepartment_clicked(){
    Department department;
    department.setName("New department");
    Company::getInstance()->addDepartment(department);
}

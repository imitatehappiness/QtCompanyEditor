#include "employeewidgeteditor.h"
#include "ui_employeewidgeteditor.h"

EmployeeWidgetEditor::EmployeeWidgetEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmployeeWidgetEditor){

    ui->setupUi(this);
}

EmployeeWidgetEditor::~EmployeeWidgetEditor(){
    delete ui;
}

Employee EmployeeWidgetEditor::getEmployee(const Employee* employee){
    if(employee != nullptr){
        ui->lE_name->setText(employee->getName());
        ui->lE_surname->setText(employee->getSurname());
        ui->lE_middlename->setText(employee->getMiddleName());
        ui->lE_function->setText(employee->getFunction());
        ui->sB_salary->setValue(employee->getSalary());
    }
    //setModal(true);
    //exec();
    Employee newEmployee;
    if(getIsApply()){
        newEmployee.setName(ui->lE_name->text());
        newEmployee.setSurname(ui->lE_surname->text());
        newEmployee.setMiddleName(ui->lE_middlename->text());
        newEmployee.setFunction(ui->lE_function->text());
        newEmployee.setSalary(ui->sB_salary->value());
    }
    return newEmployee;
}

void EmployeeWidgetEditor::on_pB_cancel_clicked(){
    isApply = false;
    close();
}

void EmployeeWidgetEditor::on_pB_apply_clicked(){
    isApply = true;
    if(ui->lE_name->text() == ""){
       ui->lE_name->setStyleSheet("border-color: red");
       isApply = false;
    }
    if(ui->lE_surname->text() == ""){
       ui->lE_surname->setStyleSheet("border-color: red");
       isApply = false;
    }
    if(ui->lE_middlename->text() == ""){
       ui->lE_middlename->setStyleSheet("border-color: red");
       isApply = false;
    }
    if(ui->lE_function->text() == ""){
       ui->lE_function->setStyleSheet("border-color: red");
       isApply = false;
    }
    if(isApply){
        ui->lE_name->setStyleSheet("");
        ui->lE_surname->setStyleSheet("");
        ui->lE_middlename->setStyleSheet("");
        ui->lE_function->setStyleSheet("");
        close();
    }
}

bool EmployeeWidgetEditor::getIsApply() const{
    return isApply;
}

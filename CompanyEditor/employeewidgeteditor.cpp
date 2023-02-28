#include "employeewidgeteditor.h"
#include "ui_employeewidgeteditor.h"

EmployeeWidgetEditor::EmployeeWidgetEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeWidgetEditor){

    ui->setupUi(this);
    QObject::connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(acceptEWE()));
    QObject::connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(rejectEWE()));
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
    setModal(true);
    exec();
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

void EmployeeWidgetEditor::rejectEWE(){
    isApply = false;
    reject();
}

void EmployeeWidgetEditor::acceptEWE(){
    isApply = true;
    accept();
}

bool EmployeeWidgetEditor::getIsApply() const{
    return isApply;
}

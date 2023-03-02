#include "employeewidgeteditor.h"
#include "ui_employeewidgeteditor.h"

#include <notification.h>
EmployeeWidgetEditor::EmployeeWidgetEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeWidgetEditor){

    setWindowTitle("Edit employee");
    ui->setupUi(this);
    QObject::connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(acceptEWE()));
    QObject::connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(rejectEWE()));

}

EmployeeWidgetEditor::~EmployeeWidgetEditor(){
    delete ui;
}

void EmployeeWidgetEditor::rejectEWE(){
    isApply = false;
    reject();
}

void EmployeeWidgetEditor::acceptEWE(){
    isApply = true;
    if(ui->lE_name->text() == "" || ui->lE_surname->text() == "" ||
       ui->lE_middlename->text() == "" || ui->lE_function->text() == "" || ui->sB_salary->value() == 0 ){
        Notification* mNotification = new Notification(this);
        mNotification->setNotificationText("Fill in all the fields!");
        mNotification->show();
        isApply = false;
    }
    if(isApply){
        accept();
    }
}

bool EmployeeWidgetEditor::getIsApply() const{
    return isApply;
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



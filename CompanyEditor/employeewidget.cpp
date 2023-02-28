#include "employeewidget.h"
#include "ui_employeewidget.h"

#include "company.h"
#include "employeewidgeteditor.h"

EmployeeWidget::EmployeeWidget(Employee* employee, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmployeeWidget),
    mEmployee(employee){

    ui->setupUi(this);

    updateUI();
    QObject::connect(mEmployee, SIGNAL(changed()), this, SLOT(updateUI()));
}

EmployeeWidget::~EmployeeWidget(){
    delete ui;
    hide();
}

void EmployeeWidget::updateUI(){
    ui->l_name->setText(mEmployee->getFullName());
    ui->l_function->setText(mEmployee->getFunction());
    ui->l_salary->setText(QString::number(mEmployee->getSalary()) + " rub.");
    emit changed();
}

void EmployeeWidget::on_pB_edit_clicked(){
    EmployeeWidgetEditor ewe;
    Employee newEmployee = ewe.getEmployee(mEmployee);
    if(!newEmployee.equals(*mEmployee) && ewe.getIsApply()){
        mEmployee->set(newEmployee);
    }
}

void EmployeeWidget::on_pB_delete_clicked(){
    auto indexes = Company::getInstance()->findIndexesOfEmp(*mEmployee);
    int depIndex = indexes.first;
    int empIndex = indexes.second;

    Employee* employee = Company::getInstance()->getEmpFromDepByIndexes(depIndex, empIndex);
    if(employee){
       emit employee->deleteEmployee(employee);
    }
}

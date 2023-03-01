#include "employeewidget.h"
#include "ui_employeewidget.h"

#include <QMessageBox>

#include "company.h"
#include "employeewidgeteditor.h"

EmployeeWidget::EmployeeWidget(Employee* employee, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmployeeWidget)
    /*mEmployee(employee)*/{

    mEmployee = new Employee(*employee);
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
        auto indexes = Company::getInstance()->findIndexesOfEmp(*mEmployee);
        int depIndex = indexes.first;
        int empIndex = indexes.second;
        Employee* employee = Company::getInstance()->getEmpFromDepByIndexes(depIndex, empIndex);
        if(employee){
            employee->set(newEmployee);
            mEmployee->set(newEmployee);
        }
    }
}

#include <QDebug>

void EmployeeWidget::on_pB_delete_clicked(){

    QMessageBox mBox;
    mBox.setWindowIcon(QIcon("resources/icons/win_icon.png"));
    mBox.setIcon(QMessageBox::Question);
    mBox.setText("The employee will be deleted.");
    mBox.setInformativeText("Are you sure?");
    mBox.setStandardButtons(QMessageBox::Discard | QMessageBox::Ok);
    mBox.setButtonText(QMessageBox::Discard, "No");
    mBox.setButtonText(QMessageBox::Ok, "Yes");

    if(mBox.exec() == QMessageBox::Ok){
        auto indexes = Company::getInstance()->findIndexesOfEmp(*mEmployee);
        int depIndex = indexes.first;
        int empIndex = indexes.second;
        qDebug() << "delete: " << depIndex << " " << empIndex;
        Employee* employee = Company::getInstance()->getEmpFromDepByIndexes(depIndex, empIndex);
        if(employee){
            emit employee->deleteEmployee(employee);
        }
    }

}

#include "departmentheaderwidget.h"
#include "ui_departmentheaderwidget.h"
#include <QInputDialog>
#include <QLineEdit>

DepartmentHeaderWidget::DepartmentHeaderWidget(Department& department, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DepartmentHeaderWidget),
    mDepartment(department){

    ui->setupUi(this);
    updateUI();
}

DepartmentHeaderWidget::~DepartmentHeaderWidget(){
    delete ui;
}

void DepartmentHeaderWidget::updateName(){
    ui->l_departmentName->setText(mDepartment.getName());
}

void DepartmentHeaderWidget::updateUI(){
    updateName();
    int avgSalary = 0;
    for(auto iter = mDepartment.getEmployments().begin(); iter != mDepartment.getEmployments().end(); ++iter){
        avgSalary += iter->getSalary();
    }
    int depEmpCount = mDepartment.getEmployments().size();
    avgSalary /= depEmpCount;
    ui->l_countPeople_value->setText(QString::number(depEmpCount));
    if(mDepartment.getEmployments().size()){
        ui->l_averageSalary_value->setText(QString::number(avgSalary));
    } else {
        ui->l_averageSalary_value->setText("-");
    }
}

void DepartmentHeaderWidget::on_pB_edit_clicked(){
    bool ok;
    QString newDepName = QInputDialog::getText(this, tr("Edit"),
                                        tr("Department name:"),
                                        QLineEdit::Normal, ui->l_departmentName->text(), &ok);
    if(Department::isCorrectDepartmentName(newDepName) && ok){
        mDepartment.setName(newDepName);
        updateName();
    }
}

void DepartmentHeaderWidget::on_pB_delete_clicked(){
    emit mDepartment.deleteDepartment(&mDepartment);
}

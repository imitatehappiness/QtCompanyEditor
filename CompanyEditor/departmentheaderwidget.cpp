#include "departmentheaderwidget.h"
#include "ui_departmentheaderwidget.h"
#include <QInputDialog>
#include <QLineEdit>
#include <QMessageBox>

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
    avgSalary = depEmpCount == 0 ? 0 : int(avgSalary / depEmpCount);
    ui->l_countPeople_value->setText(QString::number(depEmpCount));
    if(mDepartment.getEmployments().size()){
        ui->l_averageSalary_value->setText(QString::number(avgSalary));
    } else {
        ui->l_averageSalary_value->setText("-");
    }
}
#include <QDebug>
void DepartmentHeaderWidget::on_pB_edit_clicked(){
    bool ok;
    QString newDepName = QInputDialog::getText(this, tr("Edit"),
                                        tr("Department name:"),
                                        QLineEdit::Normal, ui->l_departmentName->text(), &ok);
    if(Department::isCorrectDepartmentName(newDepName) && ok){
        mDepartment.setName(newDepName);
        updateName();
    }
    qDebug() << ui->l_departmentName->text() << ": " << mDepartment.getEmployments().size();
}

void DepartmentHeaderWidget::on_pB_delete_clicked(){

    QMessageBox mBox;
    mBox.setWindowIcon(QIcon("resources/icons/win_icon.png"));
    mBox.setIcon(QMessageBox::Question);
    mBox.setText("The department will be deleted.");
    mBox.setInformativeText("Are you sure?");
    mBox.setStandardButtons(QMessageBox::Discard | QMessageBox::Ok);
    mBox.setButtonText(QMessageBox::Discard, "No");
    mBox.setButtonText(QMessageBox::Ok, "Yes");

    if(mBox.exec() == QMessageBox::Ok){
        emit mDepartment.deleteDepartment(&mDepartment);
    }
}

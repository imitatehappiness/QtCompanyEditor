#include "departmentwidget.h"
#include "addbuttonemployee.h"


DepartmentWidget::DepartmentWidget(Department& department, QWidget* parent) :
    QWidget(parent),
    mDepartment(department){

    mHeader = new DepartmentHeaderWidget(mDepartment);
    setFixedWidth(mHeader->width() + 35);
    mLayout = new QVBoxLayout(this);
    mLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    mLayout->addWidget(mHeader);
    updateUI();
    QObject::connect(&mDepartment, SIGNAL(changed()), this, SLOT(updateUI()));
}

void DepartmentWidget::addEmployeeWidget(Employee& employee){
    EmployeeWidget* employeeWidget = new EmployeeWidget(&employee);
    QObject::connect(employeeWidget, SIGNAL(changed()), mHeader, SLOT(updateUI()));
    mEmployeesLayout->addWidget(employeeWidget);
}

void DepartmentWidget::updateUI(){
    if(mLayout->count() >= 2){
        mLayout->removeWidget(mLayout->itemAt(1)->widget());
    }
    mHeader->updateUI();
    QScrollArea* scrollArea = new QScrollArea();
    QWidget* listWidget = new QWidget();
    mEmployeesLayout = new QVBoxLayout(listWidget);
    AddButtonEmployee* btn = new AddButtonEmployee(mDepartment);
    btn->setMinimumWidth(scrollArea->geometry().width() - scrollArea->geometry().width() / 4.6);
    mEmployeesLayout->addWidget(btn);

    QList<Employee> departments = mDepartment.getEmployments();
    for(auto it = departments.begin(); it != departments.end(); ++it){
        addEmployeeWidget(*it);
    }

    scrollArea->setWidget(listWidget);
    mLayout->addWidget(scrollArea, 1);
    scrollArea->setFixedHeight(scrollArea->geometry().height() - scrollArea->geometry().height() / 10);
}

DepartmentWidget::~DepartmentWidget(){
    hide();
    while(auto item = mEmployeesLayout->takeAt(0)){
        delete item;
    }
    while(auto item = mLayout->takeAt(0)){
        delete item;
    }
    delete mLayout;
    delete mEmployeesLayout;
}

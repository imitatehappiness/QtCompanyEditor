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
    auto employeeWidget = new EmployeeWidget(&employee);
    QObject::connect(&employee, SIGNAL(changed()), mHeader, SLOT(updateUI()));
    mListLayout->addWidget(employeeWidget);
}

void DepartmentWidget::updateUI(){
    if(mLayout->count() == 2){
        mLayout->removeWidget(mLayout->itemAt(1)->widget());
    }
    mHeader->updateUI();
    QScrollArea* scrollArea = new QScrollArea();
    QWidget* listWidget = new QWidget();
    mListLayout = new QVBoxLayout(listWidget);
    QList<Employee> departments = mDepartment.getEmployments();
    for(auto it = departments.begin(); it != departments.end(); ++it){
        addEmployeeWidget(*it);
    }
    mListLayout->addWidget(new AddButtonEmployee(mDepartment));
    scrollArea->setFixedHeight(400);
    scrollArea->setWidget(listWidget);
    mLayout->addWidget(scrollArea, 1);
}

DepartmentWidget::~DepartmentWidget(){
    hide();
    while(auto item = mListLayout->takeAt(0)){
        delete item;
    }
    while(auto item = mLayout->takeAt(0)){
        delete item;
    }
    delete mLayout;
    delete mListLayout;
}

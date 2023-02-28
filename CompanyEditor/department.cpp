#include "department.h"

Department::Department(const Department &department){
    *this = department;
}

QString Department::getName() const{
    return mName;
}

void Department::setName(const QString &name){
    mName = name;
}

const QList<Employee>& Department::getEmployments() const{
    return mEmployments;
}

void Department::addEmployee(Employee employee, int index){
    if(index == -1){
        mEmployments.append(employee);
        QObject::connect(&mEmployments.back(), SIGNAL(deleteEmployee(Employee*)), this, SLOT(applyDeleting(Employee*)));
    } else {
        mEmployments.insert(index, employee);
        QObject::connect(&mEmployments[index], SIGNAL(deleteEmployee(Employee*)), this, SLOT(applyDeleting(Employee*)));
    }
    emit changed();
}

Department &Department::operator=(const Department &department){
    mName = department.mName;
    mEmployments = department.mEmployments;
    return *this;
}

bool Department::operator==(const Department &department){
    return mName == department.mName && mEmployments == department.mEmployments;
}

bool Department::isCorrectDepartmentName(const QString &name){
    return name.size() != 0;
}

Employee *Department::getEmpByIndex(int index){
    Employee* result = nullptr;
    if(index < mEmployments.size()){
        result = &mEmployments[index];
    }
    return result;
}

int Department::findIndexOfEmp(const Employee &employee){
    return mEmployments.indexOf(employee);
}

void Department::removeEmpByIndex(int index){
    mEmployments.removeAt(index);
    //emit mEmployments[index].deleteEmployee(&mEmployments[index]);
    emit changed();
}

void Department::applyDeleting(Employee *employee){
    if(mEmployments.removeOne(*employee)){
        emit changed();
    }
}

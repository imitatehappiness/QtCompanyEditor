#include "company.h"

Company* company = nullptr;

Company* Company::getInstance(){
    if(company == nullptr){
        company = new Company();
    }
    return company;
}

Department* Company::getDepByIndex(int index){
    Department* result = nullptr;
    if(index < departments.size()){
        result = &departments[index];
    }
    return result;
}

Employee* Company::getEmpFromDepByIndexes(int depIndex, int empIndex){
    Employee* employee = nullptr;
    Department* dep = getDepByIndex(depIndex);
    if(dep){
        employee = dep->getEmpByIndex(empIndex);
    }
    return employee;
}

void Company::setSettings(){
    for(auto dep = departments.begin(); dep != departments.end();++dep){
        QObject::connect(&*dep, SIGNAL(deleteDepartment(Department*)), this, SLOT(applyDeleting(Department*)));
        for(auto emp = dep->getEmployments().begin(); emp != dep->getEmployments().end(); ++emp){
            QObject::connect(&*emp, SIGNAL(deleteEmployee(Employee*)), &*dep, SLOT(applyDeleting(Employee*)));
        }
    }
}

void Company::setData(QList<Department> data){
    departments = data;
}

void Company::clear(){
    departments.clear();
    emit dataChanged();
}

void Company::addDepartment(Department department, int index){
    if(index == -1){
        departments.append(department);
        QObject::connect(&departments.back(), SIGNAL(deleteDepartment(Department*)), this, SLOT(applyDeleting(Department*)));
    } else {
        departments.insert(index, department);
        QObject::connect(&departments[index], SIGNAL(deleteDepartment(Department*)), this, SLOT(applyDeleting(Department*)));
    }

    emit dataChanged();
}

void Company::removeDepByIndex(int index){
    if(index < departments.size()){
        QObject::disconnect(&departments[index], SIGNAL(deleteDepartment(Department*)), this, SLOT(applyDeleting(Department*)));
        departments.removeAt(index);
        emit dataChanged();
    }
}

int Company::findIndexOfDep(const Department &department){
    return departments.indexOf(department);
}

QPair<int, int> Company::findIndexesOfEmp(const Employee &employee){
    int depIndex = -1;
    int empIndex = -1;

    for(int i = 0; i < departments.size(); ++i){
        empIndex = departments[i].findIndexOfEmp(employee);
        if(empIndex != -1){
            depIndex = i;
            break;
        }
    }
    return QPair<int, int>(depIndex, empIndex);
}

void Company::applyDeleting(Department* department){
    if(departments.removeOne(*department)){
        emit dataChanged();
    }
}

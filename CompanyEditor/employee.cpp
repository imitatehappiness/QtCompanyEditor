#include "employee.h"

Employee::Employee(const Employee& employee){
    set(employee);

}

QString Employee::getName() const{
    return mName;
}

QString Employee::getSurname() const{
    return mSurname;
}

QString Employee::getMiddleName() const{
    return mMiddlename;
}

QString Employee::getFunction() const{
    return mFunction;
}

int Employee::getSalary() const{
    return mSalary;
}

void Employee::setName(const QString &name){
    mName = name;
}

void Employee::setSurname(const QString &surname){
    mSurname = surname;
}

void Employee::setMiddleName(const QString &middlename){
    mMiddlename = middlename;
}

void Employee::setFunction(const QString &function){
    mFunction = function;
}

void Employee::setSalary(int salary){
    mSalary = salary;
}

QString Employee::getFullName(){
    return mSurname + " " + mName + " " + mMiddlename;
}

bool Employee::equals(const Employee& employee){
    return  mName == employee.getName() &&
            mSurname == employee.getSurname() &&
            mMiddlename == employee.getMiddleName() &&
            mFunction == employee.getFunction() &&
            mSalary == employee.getSalary();
}

void Employee::set(const Employee& employee){
    if(!equals(employee)){
        setName(employee.getName());
        setFunction(employee.getFunction());
        setMiddleName(employee.getMiddleName());
        setSalary(employee.getSalary());
        setSurname(employee.getSurname());
        emit changed();
    }
}

bool Employee::operator==(const Employee& employee){
    return equals(employee);
}

Employee &Employee::operator=(const Employee& employee){
    set(employee);
    return *this;
}

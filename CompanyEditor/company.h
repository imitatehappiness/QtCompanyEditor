#pragma once

#include <QObject>

#include "department.h"

/*!
 * \class Company
 * \brief Класс объединяющий в себе все отделы
 */
class Company : public QObject {
    Q_OBJECT
public:
    /// Список отделов
    QList<Department> departments;
public:
    /// Получение указателя на экземпляр Company
    static Company *getInstance();
    /// Получение отдела по индексу
    Department* getDepByIndex(int index);
    /// Получение сотрудника по индексу отедла и сотрудника
    Employee* getEmpFromDepByIndexes(int depIndex, int empIndex);
    /// Установка настроек
    void setSettings();
    /// Установка данных
    void setData(QList<Department> data);
    /// Удаление всех отделов
    void clear();
    /// Добавить отдел
    void addDepartment(Department department, int index = -1);
    /// Удалить отдел по индексу
    void removeDepByIndex(int index);
    /// Найти индекс отдела
    int findIndexOfDep(const Department& department);
    /// Найти индекс сотрудника и его отдела
    QPair<int,int> findIndexesOfEmp(const Employee &employee);
public slots:
    /// Cлот, который принимает сигнал от отдела и удаляет его
    void applyDeleting(Department* department);
signals:
    /// Данные изменились
    void dataChanged();
private:
    /// Конструктор
    Company() = default;
    /// Оператор копирования
    Company( const Company& );
    /// Оператор присваивания
    Company& operator=( Company& );
};

/// Компания
extern Company* company;

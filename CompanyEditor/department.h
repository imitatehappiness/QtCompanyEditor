#pragma once

#include <QObject>

#include "employee.h"

/*!
 * \class Department
 * \brief Класс конкретного отдела:
 *        Cодержит данные: имя отдела, список сотрудников
 */
class Department : public QObject{
    Q_OBJECT
public:
    /// Конструктор по умолчанию
    Department() = default;
    /// Конструктор с параметрами
    Department(const Department& department);
    /// Получение имени отдела
    QString getName() const;
    /// Установка имени отдела
    void setName(const QString& name);
    /// Получение списка сотрудников отдела
    const QList<Employee>& getEmployments() const;
    /// Добавление сотрудника
    void addEmployee(Employee employee, int index = -1);
    /// Оператор присваивания
    Department &operator=(const Department& department);
    /// Операор сравнивания
    bool operator==(const Department& department);
    /// Проверяет название отдела
    static bool isCorrectDepartmentName(const QString& name);
    /// Получение сотрудника по индексу в списке
    Employee *getEmpByIndex(int index);
    /// Получение индекса по сотруднику
    int findIndexOfEmp(const Employee& employee);
    /// Удаление сотрудника по индексу
    void removeEmpByIndex(int index);
public slots:
    /// Слот, который принимает сигнал от работника и удаляет его
    void applyDeleting(Employee* employee);
signals:
    /// Сигнал удаления отдела
    void deleteDepartment(Department*);
    /// Сигнал редактирования данных объекта
    void changed();
private:
    /// Имя отдела
    QString mName;
    /// Список сотрудников
    QList<Employee> mEmployments;
};

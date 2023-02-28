#pragma once

#include<QObject>

/*!
 * \class Employee
 * \brief Класс конкретного сотрудника компании
 *        содержит данные: Имя, фамилия, отчество, должность, зарплата
 */
class Employee : public QObject{
    Q_OBJECT
public:
    /// Конструктор по умолчанию
    Employee() = default;
    /// Конструктор с параметрами
    Employee(const Employee& employee);
    /// Получение имени объекта
    QString getName() const;
    /// Получение фамилии объекта
    QString getSurname() const;
    /// Получение отчества объекта
    QString getMiddleName() const;
    /// Получение должности объекта
    QString getFunction() const;
    /// Получение зарплаты объекта
    int getSalary() const;
    /// Установка имени объекта
    void setName(const QString& name);
    /// Установка фамилии объекта
    void setSurname(const QString& surname);
    /// Установка отчества объекта
    void setMiddleName(const QString& middlename);
    /// Установка должности объекта
    void setFunction(const QString& function);
    /// Установка зарплаты объекта
    void setSalary(int salary);
    /// Возвращает полное имя работника (ФИО)
    QString getFullName();
    /// Проверка на равенство
    bool equals(const Employee& employee);
    /// Копирование данных из объекта
    void set(const Employee& employee);
    /// Оператор равенства
    bool operator==(const Employee& employee);
    /// Оператор присваивания
    Employee& operator=(const Employee& employee);
signals:
    /// Сигнал, который посылается объектом, если он должен быть удален
    void deleteEmployee(Employee* employee);
    /// Сигнал редактирования данных объекта
    void changed();
private:
    /// Имя Обьекта
    QString mName = "";
    /// Фамилия Обьекта
    QString mSurname = "";
    /// Отчество Обьекта
    QString mMiddlename = "";
    /// Функция (Должность) Обьекта
    QString mFunction = "";
    /// Зарплата Обьекта
    int mSalary = 0;
};

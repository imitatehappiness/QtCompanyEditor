#pragma once
#include <QWidget>

#include "department.h"

namespace Ui {
class AddButtonEmployee;
}

/*!
 * \class AddButtonEmployee
 * \brief Визулазиция кнопки "Add employee"
 */
class AddButtonEmployee : public QWidget{
    Q_OBJECT
public:
    /// Конструктор с параметрами
    explicit AddButtonEmployee(Department& department,QWidget *parent = nullptr);
    ~AddButtonEmployee();
private slots:
    /// Добавить сотрудника
    void on_pB_addEmployee_clicked();
private:
    Ui::AddButtonEmployee *ui;
    /// Отдел
    Department& mDepartment;
};


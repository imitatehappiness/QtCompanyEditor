#pragma once

#include <QObject>
#include <QtWidgets>

#include "departmentheaderwidget.h"
#include "department.h"
#include "employeewidget.h"

/*!
 * \class DepartmentWidget
 * \brief Виджет объединяющий в себе виджет хедера отдела и виджеты сотрудников
 */
class DepartmentWidget : public QWidget{
    Q_OBJECT
public:
    /// Конструктор с параметрами
    explicit DepartmentWidget(Department& department, QWidget* parent = nullptr);
    ~DepartmentWidget();
    /// Добавление виджета сотрудника
    void addEmployeeWidget(Employee& employee);
public slots:
    /// Обновление формы
    void updateUI();
private:
    /// Отдел
    Department& mDepartment;
    /// Виджет хедера отдела
    DepartmentHeaderWidget* mHeader;
    /// Список сотрудников отдела
    QVBoxLayout* mEmployeesLayout;
    /// хедер и список сотрудников
    QVBoxLayout* mLayout;
};

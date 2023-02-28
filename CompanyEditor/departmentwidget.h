#pragma once

#include <QObject>
#include <QtWidgets>

#include "departmentheaderwidget.h"
#include "department.h"
#include "employeewidget.h"

class DepartmentWidget : public QWidget{
    Q_OBJECT
public:
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
    /// Список слоев
    QVBoxLayout* mListLayout;
    /// Слой
    QVBoxLayout* mLayout;
};

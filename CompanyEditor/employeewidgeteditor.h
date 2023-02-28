#pragma once

#include <QDialog>

#include "employee.h"

namespace Ui {
class EmployeeWidgetEditor;
}

/*!
 * \class EmployeeWidgetEditor
 * \brief Виджет редактирования данных сотрудника
 */
class EmployeeWidgetEditor : public QDialog{
    Q_OBJECT

public:
    /// Конструктор
    explicit EmployeeWidgetEditor(QWidget *parent = 0);
    ~EmployeeWidgetEditor();
    /// Возвращает новый экземпляр работника
    Employee getEmployee(const Employee* employee = nullptr);
    /// Получение значения isApply
    bool getIsApply() const;
private slots:
    /// Применить имзенения
    void acceptEWE();
    /// Отменить изменений
    void rejectEWE();
private:
    Ui::EmployeeWidgetEditor *ui;
    /// Можно ли применить изменения
    bool isApply = false;
};

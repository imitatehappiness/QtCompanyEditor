#pragma once

#include <QWidget>

#include <employee.h>

namespace Ui {
class EmployeeWidgetEditor;
}

/*!
 * \class EmployeeWidgetEditor
 * \brief Виджет редактирования данных сотрудника
 */
class EmployeeWidgetEditor : public QWidget{
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
    /// Отменить изменений
    void on_pB_cancel_clicked();
    /// Применить имзенения
    void on_pB_apply_clicked();
private:
    Ui::EmployeeWidgetEditor *ui;
    /// Можно ли применить изменения
    bool isApply = false;
};

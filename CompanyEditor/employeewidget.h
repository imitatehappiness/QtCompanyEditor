#pragma once

#include <QWidget>

#include "employee.h"

namespace Ui {
class EmployeeWidget;
}

/*!
 * \class EmployeeWidget
 * \brief Виджет отображающий полное имя сотрудника,
 *           должность и зарплату
 */
class EmployeeWidget : public QWidget{
    Q_OBJECT

public:
    /// Конструктор с парметрами
    explicit EmployeeWidget(Employee* employee, QWidget *parent = 0);
    ~EmployeeWidget();
private slots:
    /// Обновление виджета
    void updateUI();
    /// Слот редактирования данных сотрудника
    void on_pB_edit_clicked();
    /// Слот удаления сотрудника
    void on_pB_delete_clicked();
signals:
    /// Сигнал изменение данных
    void changed();
    /// Сигнал удаление сотрудника
    void deleted(Employee* employee);
private:
    Ui::EmployeeWidget *ui;
    /// Объект сотрудника
    Employee* mEmployee = nullptr;
};


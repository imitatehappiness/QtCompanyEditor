#pragma once

#include <QWidget>

#include "department.h"

namespace Ui {
class DepartmentHeaderWidget;
}

/*!
 * \class DepartmentHeaderWidget
 * \brief Виджет отображающий название отдела, кол-во сотрудников и среднюю зарплату
 */
class DepartmentHeaderWidget : public QWidget{
    Q_OBJECT
public:
    /// Конструктор с параметрами
    explicit DepartmentHeaderWidget(Department& department, QWidget *parent = nullptr);
    ~DepartmentHeaderWidget();
public slots:
    /// Обновление имени отдела
    void updateName();
    /// Обносление средней зарпаты и кол-ва сотрудников отдела
    void updateUI();
private slots:
    /// Слот редактирования отдела
    void on_pB_edit_clicked();
    /// Слот удаления отдела
    void on_pB_delete_clicked();
private:
    Ui::DepartmentHeaderWidget *ui;
    /// Объект отдела
    Department& mDepartment;
};

#pragma once

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "company.h"
#include "departmentwidget.h"

/*!
 * \class CompanyWidget
 * \brief Виджет объединяющий в себе виджеты отделов
 */
class CompanyWidget : public QWidget{
    Q_OBJECT
public:
    /// Конструктор с параметрами
    CompanyWidget(QList<Department>& company, QWidget* parent = nullptr);
    /// Добавить виджет отдела
    void addDepartmentWidget(Department& department);
public:
    /// Расположение c виджетами
    QHBoxLayout* layout = nullptr;
    /// Виджет в расположении
    QWidget* layoutWidget = nullptr;
public slots:
    /// Обновление формы
    void updateUI();
signals:
    /// Сигнал об изменении
    void changed();
private:
    /// Компания
    QList<Department>& mCompany;
    /// Список виджетов отделов
    QList<DepartmentWidget*> mDepWidgets;
};

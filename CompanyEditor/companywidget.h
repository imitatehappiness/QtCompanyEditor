#pragma once

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "company.h"
#include "departmentwidget.h"

class CompanyWidget : public QWidget{
    Q_OBJECT
public:
    void addDepartmentWidget(Department& department);
    /// Конструктор с параметрами
    CompanyWidget(QList<Department>& company, QWidget* parent = nullptr);
public:
    QHBoxLayout* layout = nullptr;
    QWidget* layoutWidget = nullptr;
public slots:
    /// Обновление формы
    void updateUI();
signals:
    /// Сигнал об изменении
    void changed();
private:
    void deleteHLayoutWidgets();
private:
    /// Компания
    QList<Department>& mCompany;
    /// Виджеты отделов
    QList<DepartmentWidget*> mDepWidgets;
};

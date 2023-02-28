#pragma once

#include <QWidget>

namespace Ui {
class AddButtonDepartment;
}

class AddButtonDepartment : public QWidget{
    Q_OBJECT
public:
    explicit AddButtonDepartment(QWidget *parent = nullptr);
    ~AddButtonDepartment();
private slots:
    /// Добавить отдел
    void on_pB_addDepartment_clicked();
private:
    Ui::AddButtonDepartment *ui;
};


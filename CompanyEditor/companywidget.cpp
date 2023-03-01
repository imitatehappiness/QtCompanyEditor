#include "companywidget.h"

#include <QSizePolicy>
#include <QWidget>

#include "departmentwidget.h"

CompanyWidget::CompanyWidget(QList<Department>& company, QWidget* parent):
    QWidget(parent),
    mCompany(company){

    QObject::connect(Company::getInstance(), SIGNAL(dataChanged()), this, SLOT(updateUI()));
    //LayoutWidget = new QWidget();
    //LayoutWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    updateUI();
}
void CompanyWidget::addDepartmentWidget(Department& department){
    auto widget = new DepartmentWidget(department);
    //setFixedHeight(530);
    //layoutWidget->setFixedHeight(550);
    //layoutWidget->setFixedWidth(layoutWidget->width() + widget->width());
    //setFixedWidth(layoutWidget->width());
    layout->addWidget(widget);
    mDepWidgets.append(widget);

    layoutWidget->setFixedWidth(layout->sizeHint().width());
    setFixedWidth(layoutWidget->width());
    setFixedHeight(layoutWidget->height() + layoutWidget->height() / 5);
}

void CompanyWidget::updateUI(){
    delete layoutWidget;
    layoutWidget = new QWidget();
    layout = new QHBoxLayout(layoutWidget);
    //layoutWidget->setFixedWidth(0);
    //setFixedWidth(0);
    layout->setAlignment(Qt::AlignLeft);
    for(auto iter = mCompany.begin();iter != mCompany.end(); ++iter){
        addDepartmentWidget(*iter);
    }
    //auto abd = new AddButtonDepartment();
    //layoutWidget->setFixedWidth(layoutWidget->width() + abd->width());
    //setFixedWidth(layoutWidget->width());
    //layout->addWidget(abd);
    layoutWidget->setParent(this);
    layoutWidget->show();
}

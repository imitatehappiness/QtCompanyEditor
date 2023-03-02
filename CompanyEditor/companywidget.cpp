#include "companywidget.h"

#include <QSizePolicy>
#include <QWidget>

#include "departmentwidget.h"

CompanyWidget::CompanyWidget(QList<Department>& company, QWidget* parent):
    QWidget(parent),
    mCompany(company){

    QObject::connect(Company::getInstance(), SIGNAL(dataChanged()), this, SLOT(updateUI()));
    updateUI();
}
void CompanyWidget::addDepartmentWidget(Department& department){
    auto widget = new DepartmentWidget(department);
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
    layout->setAlignment(Qt::AlignLeft);

    for(auto iter = mCompany.begin();iter != mCompany.end(); ++iter){
        addDepartmentWidget(*iter);
    }

    layoutWidget->setParent(this);
    layoutWidget->show();
}

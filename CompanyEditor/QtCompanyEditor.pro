#-------------------------------------------------
#
# Project created by QtCreator 2023-02-27T21:28:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
TARGET = CompanyEditor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    employee.cpp \
    department.cpp \
    company.cpp \
    employeewidget.cpp \
    employeewidgeteditor.cpp \
    departmentheaderwidget.cpp \
    departmentwidget.cpp \
    addbuttonemployee.cpp \
    companywidget.cpp \
    notification.cpp

HEADERS += \
        mainwindow.h \
    employee.h \
    department.h \
    company.h \
    employeewidget.h \
    employeewidgeteditor.h \
    departmentheaderwidget.h \
    departmentwidget.h \
    addbuttonemployee.h \
    companywidget.h \
    notification.h

FORMS += \
        mainwindow.ui \
    employeewidget.ui \
    employeewidgeteditor.ui \
    departmentheaderwidget.ui \
    addbuttonemployee.ui \

RESOURCES += \
    resources/resources.qrc

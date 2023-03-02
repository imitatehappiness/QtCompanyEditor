#pragma once

#include <QString>
#include<QXmlStreamReader>
#include<QTextStream>

#include "company.h"

/*!
 * \class XMLParser
 * \brief Класс для Сохранения и Считывания (Парсинга) XML файлов
 */
class XMLParser{
public:
    XMLParser() = default;
    QList<Department> parseFromPath(QString path);
    void saveToPath(QList<Department>& model, QString path);
public:
    /// Тег Отделов
    const QString DEPARTMENTS = "departments";
    /// Тег Отдела
    const QString DEPARTMENT = "department";
    /// Тег Сотрудников
    const QString EMPLOYMENTS = "employments";
    /// Тег Сотрудника
    const QString EMPLOYMENT = "employment";
    /// Тег Имени Сотрудника
    const QString NAME = "name";
    /// Тег Фамилии Сотрудника
    const QString SURNAME = "surname";
    /// Тег Отчества Сотрудника
    const QString MIDDLENAME = "middlename";
    /// Тег Должности Сотрудника
    const QString FUNCTION = "function";
    /// Тег зарплаты сотрудника
    const QString SALARY = "salary";
private:
    /// Генерация исключения
    std::invalid_argument* genExeception(QXmlStreamReader& reader);
    /// Чтение одного элемента
    QString readElement(QXmlStreamReader& reader);
    /// Генерация строки с мета информацией для XML файла
    QString meta();
    /// Генерация строки <text>
    QString getBlock(const QString& text);
    /// Генерация строки <text name="name">
    QString getBlockWithName(const QString& text, const QString& name);
    /// Генерация строки </text>
    QString getCloseBlock(const QString& text);
    /// Запись информации в out, отступая от начала строки level символов '\t'
    void writeTo(QTextStream& out, int level, const QString& text);
    /// Запись информации с тегами в out, отступая от начала строки level символов '\t'
    void writeBlockWithValue(QTextStream& out, int level, const QString& atr, const QString& value);
    /// Разбор отдела
    void parseDepartment(QList<Department>& to, QXmlStreamReader& reader);
    /// Разбор сотрудника
    Employee parseEmployee(QXmlStreamReader& reader);
    /// Сохранение в out отдел
    void saveDep(QTextStream& out, const Department& department);
    /// Сохранение в out сотрудника
    void saveEmpl(QTextStream& out, const Employee& employee);
};


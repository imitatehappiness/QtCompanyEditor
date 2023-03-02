#include "xmlparser.h"

#include <QFile>

std::invalid_argument* XMLParser::genExeception(QXmlStreamReader& reader){
    QString er = reader.errorString();
    return new std::invalid_argument(reader.errorString().toStdString());
}

QString XMLParser::readElement(QXmlStreamReader& reader){
    reader.readNext();
    if(reader.tokenType() != QXmlStreamReader::Characters) {
        return QString();
    }
    return reader.text().toString();
}

QList<Department> XMLParser::parseFromPath(QString path){
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly| QIODevice::Text)){
        throw new std::invalid_argument("Cannot read the file!");
    }
    QXmlStreamReader reader(file.readAll());
    QList<Department> result;
    while(!reader.atEnd() && !reader.hasError()){
        QXmlStreamReader::TokenType token = reader.readNext();
        if(token == QXmlStreamReader::StartDocument){
            continue;
        }
        if(token == QXmlStreamReader::StartElement){
            if(reader.name() == DEPARTMENT){
                parseDepartment(result, reader);
            }
        }
    }
    if(reader.hasError()){
        throw genExeception(reader);
    }
    reader.clear();
    return result;
}

void XMLParser::saveToPath(QList<Department>& model, QString path){
    QFile fileStream(path);
    if(!fileStream.open(QIODevice::WriteOnly)){
        throw std::invalid_argument("Invalid path");
    }

    QTextStream out(&fileStream);
    out.setCodec("UTF-8");
    writeTo(out, 0, meta());
    writeTo(out, 0, getBlock(DEPARTMENTS));
    if(model.size()){
        for(int i = 0;i<model.size();++i){
            Department& department = model[i];
            saveDep(out, department);
        }
    }
    writeTo(out, 0, getCloseBlock(DEPARTMENTS));
}

QString XMLParser::meta(){
    return "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
}

QString XMLParser::getBlock(const QString &text){
    return "<" + text + ">";
}

QString XMLParser::getBlockWithName(const QString &text, const QString &name){
    return "<" + text + " " + NAME + "=\"" + name +"\">";
}

QString XMLParser::getCloseBlock(const QString &text){
    return "</" + text + ">";
}

void XMLParser::writeTo(QTextStream &out, int level, const QString &text){
    for(int i = 0; i < level; ++i){
        out << "\t";
    }
    out << text << "\n";
}

void XMLParser::writeBlockWithValue(QTextStream &out, int level, const QString &atr, const QString &value){
    for(int i = 0;i<level;++i){
        out << "\t";
    }
    out << getBlock(atr) << value << getCloseBlock(atr) << "\n";
}

void XMLParser::parseDepartment(QList<Department> &to, QXmlStreamReader &reader){
    to.push_back(Department());
    QXmlStreamAttributes atr = reader.attributes();
    if(atr.hasAttribute(NAME)){
        to.back().setName(atr.value(NAME).toString());
    }
    while(!reader.atEnd() && !reader.hasError()){
        QXmlStreamReader::TokenType token = reader.readNext();
        if(token ==  QXmlStreamReader::StartElement){
            if(reader.name() == EMPLOYMENT){
                to.back().addEmployee(parseEmployee(reader));
            }
        }
        else {
            if(reader.name() == DEPARTMENT){
                break;
            }
        }
    }
    if(reader.hasError()){
        throw genExeception(reader);
    }
}

Employee XMLParser::parseEmployee(QXmlStreamReader &reader){
    Employee employee;
    while(!reader.atEnd() && !reader.hasError()){
        QXmlStreamReader::TokenType token = reader.readNext();
        if(token ==  QXmlStreamReader::StartElement){
            if(reader.name() == SURNAME){
                employee.setSurname(readElement(reader));
            }
            if(reader.name() == NAME){
                employee.setName(readElement(reader));
            }
            if(reader.name() == MIDDLENAME){
                employee.setMiddleName(readElement(reader));
            }
            if(reader.name() == FUNCTION){
                employee.setFunction(readElement(reader));
            }
            if(reader.name() == SALARY){
                employee.setSalary(readElement(reader).toInt());
            }
        } else {
            if(reader.name() == EMPLOYMENT){
                break;
            }
        }
    }
    if(reader.hasError()){
        throw genExeception(reader);
    }
    return employee;
}

void XMLParser::saveDep(QTextStream &out, const Department &department){
    writeTo(out, 1, getBlockWithName(DEPARTMENT, department.getName()));
    writeTo(out, 2, getBlock(EMPLOYMENTS));
    if(department.getEmployments().size() > 0){
        QList<Employee> employees = department.getEmployments();
        for(int i = 0; i < employees.size(); ++i){
            const Employee& employee = employees[i];
            saveEmpl(out, employee);
        }
    }
    writeTo(out, 2, getCloseBlock(EMPLOYMENTS));
    writeTo(out, 1, getCloseBlock(DEPARTMENT));
}

void XMLParser::saveEmpl(QTextStream &out, const Employee &employee){
    writeTo(out, 3, getBlock(EMPLOYMENT));
    writeBlockWithValue(out, 4, SURNAME, employee.getSurname());
    writeBlockWithValue(out, 4, NAME, employee.getName());
    writeBlockWithValue(out, 4, MIDDLENAME, employee.getMiddleName());
    writeBlockWithValue(out, 4, FUNCTION, employee.getFunction());
    writeBlockWithValue(out, 4, SALARY, QString::number(employee.getSalary()));
    writeTo(out, 3, getCloseBlock(EMPLOYMENT));
}

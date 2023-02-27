#pragma once

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    /// Загрузка (парсинг) данных из файла
    void openFile();
    /// Сохранение данных в файл
    void saveFile();
    /// Закрытие приложение через меню бар
    void close();
private:
    Ui::MainWindow *ui;
};

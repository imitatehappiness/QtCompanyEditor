#pragma once

#include <memory>
#include <QMainWindow>
#include <QFileDialog>

#include "notification.h"

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
    /// Сохранение файла
    void saveFile();
    /// Закрытие приложение через меню бар
    void close();
private slots:
    /// Добавление департамента
    void on_pB_addDeparment_clicked();
private:
    Ui::MainWindow *ui;
    /// Всплывающее окно с уведомлением
    Notification *mNotification;
    /// Указатель для работы с файлами (Сохранение/Запись)
    std::shared_ptr<QFileDialog> mFileDialog = std::make_shared<QFileDialog>(new QFileDialog());
};

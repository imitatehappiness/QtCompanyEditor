#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenu>
#include <QMenuBar>
#include <QDebug>
#include <QMessageBox>

#include "company.h"
#include "companywidget.h"
#include "xmlparser.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){

    ui->setupUi(this);
    QMenu *menu = menuBar()->addMenu("&File");

    auto *close = new QAction("&Close", this);
    auto *open = new QAction("&Open", this);
    auto *save = new QAction("&Save", this);

    open->setIcon(QIcon("resources/icons/open_file.png"));
    save->setIcon(QIcon("resources/icons/save_file.png"));
    close->setIcon(QIcon("resources/icons/close_file.png"));

    menu->addAction(open);
    menu->addAction(save);
    menu->addAction(close);

    connect(open, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(save, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(close, SIGNAL(triggered()), this, SLOT(close()));

    auto cw = new CompanyWidget(Company::getInstance()->departments);
    ui->scrollArea->setWidget(cw);

    mNotification = new Notification(this);
}

MainWindow::~MainWindow(){
    delete ui;
    delete Company::getInstance();
}

void MainWindow::openFile(){
    XMLParser xmlParser;

    mFileDialog->setAcceptMode(QFileDialog::AcceptMode::AcceptOpen);
    mFileDialog->setNameFilter(tr("XML Files (*.xml)"));
    if(mFileDialog->exec()){
        try{
            auto result = xmlParser.parseFromPath(mFileDialog->selectedFiles()[0]);
            Company::getInstance()->setData(std::move(result));
            Company::getInstance()->setSettings();
        } catch(...){
            QMessageBox mBox;
            mBox.setWindowIcon(QIcon("resources/icons/win_icon.png"));
            mBox.setText("File reading error!");
            mBox.setButtonText(QMessageBox::Ok, "Ok");
            mBox.exec();
        }
    }
    activateWindow();
}

/*!
 * \enum SaveStatus
 * \brief статус для уведомления при сохранении файла
 */
enum SaveStatus{
  ok,
  error,
  wrongName,
};

void MainWindow::saveFile(){

    XMLParser xmlParser;
    SaveStatus status = SaveStatus::wrongName;
    auto url = mFileDialog->getExistingDirectoryUrl();
    if(!url.isEmpty()){
        QString fileName = QInputDialog::getText(this, tr("Save file"), tr("Enter the file name:"), QLineEdit::Normal);

        if(fileName.size() > 0){
            try{
                xmlParser.saveToPath(Company::getInstance()->departments,
                                url.toString(QUrl::RemoveScheme | QUrl::PreferLocalFile) + "/" + fileName + ".xml");
                status = SaveStatus::ok;
            } catch(...){
                status = SaveStatus::error;
                QMessageBox mBox;
                mBox.setWindowIcon(QIcon("resources/icons/win_icon.png"));
                mBox.setIcon(QMessageBox::Warning);
                mBox.setText("File writing error!");
                mBox.setButtonText(QMessageBox::Ok, "Ok");
                mBox.exec();
            }
        }else{
            status = SaveStatus::wrongName;
        }
    }
    activateWindow();

    if(status == SaveStatus::ok){
        mNotification->setNotificationText("File saved.");
    }else if(status == SaveStatus::wrongName){
        mNotification->setNotificationText("File not saved.");
    }else if (status == SaveStatus::error){
        mNotification->setNotificationText("Error saving the file. File is not saved.");
    }
    mNotification->show();
}

void MainWindow::close(){
    QMessageBox mBox;
    mBox.setWindowIcon(QIcon("resources/icons/win_icon.png"));
    mBox.setIcon(QMessageBox::Question);
    mBox.setText("The file will be closed.");
    mBox.setInformativeText("Save changes?");
    mBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Discard );
    mBox.setButtonText(QMessageBox::Ok, "Save");
    mBox.setButtonText(QMessageBox::Discard, "Don't save");

    if(mBox.exec() == QMessageBox::Ok){
        saveFile();
    }

    Company::getInstance()->clear();
}

void MainWindow::on_pB_addDeparment_clicked(){
    Department department;
    department.setName("New department");
    Company::getInstance()->addDepartment(department);
}

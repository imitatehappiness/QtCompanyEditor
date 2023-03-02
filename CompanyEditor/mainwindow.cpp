#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenu>
#include <QMenuBar>
#include <QDebug>
#include <QMessageBox>

#include "company.h"
#include "companywidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){

    ui->setupUi(this);
    QMenu *menu = menuBar()->addMenu("&Settings");

    auto *close = new QAction("&Close File", this);
    auto *open = new QAction("&Open file", this);
    auto *save = new QAction("&Save file", this);

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
    qDebug() << "open File";
}

void MainWindow::saveFile(){
    auto url = mFileDialog->getExistingDirectoryUrl();
    if(!url.isEmpty()){
        QString fileName = QInputDialog::getText(this, tr("Save file"), tr("Enter the file name:"), QLineEdit::Normal);

        if(fileName.size() > 0){
            try{
//                CompanyModelXMLParser().saveModeltoPath(CompanyModel::Company::getInstance()->departments,
//                                Url.toString(QUrl::RemoveScheme|QUrl::PreferLocalFile)+"/" + fileName + ".xml");
            } catch(...){
                QMessageBox mBox;
                mBox.setWindowIcon(QIcon("resources/icons/win_icon.png"));
                mBox.setIcon(QMessageBox::Warning);
                mBox.setText("File writing error!");
                mBox.setButtonText(QMessageBox::Ok, "Ok");
                mBox.exec();
            }
        }
    }
    activateWindow();

    mNotification->setNotificationText("File saved.");
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

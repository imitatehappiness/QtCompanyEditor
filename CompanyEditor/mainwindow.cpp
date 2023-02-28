#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenu>
#include <QMenuBar>
#include <QDebug>
#include <QMessageBox>

#include "company.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){

    ui->setupUi(this);
    QMenu *menu = menuBar()->addMenu("&Settings");

    auto *quit = new QAction("&Quit", this);
    auto *open = new QAction("&Open file", this);
    auto *save = new QAction("&Save file", this);

    menu->addAction(open);
    menu->addAction(save);
    menu->addAction(quit);

    connect(open, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(save, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(quit, SIGNAL(triggered()), this, SLOT(close()));
}

MainWindow::~MainWindow(){
    delete ui;
    delete Company::getInstance();
}

void MainWindow::openFile(){
    qDebug() << "open File";
}

void MainWindow::saveFile(){
    qDebug() << "save File";
}

void MainWindow::close(){
    QMessageBox mBox;
    mBox.setIcon(QMessageBox::Question);
    mBox.setText("The file will be closed.");
    mBox.setInformativeText("Save changes?");
    mBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Discard );
    mBox.setButtonText(QMessageBox::Ok, "Save");
    mBox.setButtonText(QMessageBox::Discard, "Don't save");

    if(mBox.exec() == QMessageBox::Ok){
        saveFile();
    }

    qApp->quit();
}

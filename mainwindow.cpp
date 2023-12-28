#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <qmessagebox.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{
    const auto& tmp = ui->lineEdit->text();

    if(QString("") == tmp){
        QMessageBox::information(this, "Error", "No prompt provided");
    }
    else{
        QMessageBox::information(this, "Info", "Starting new thread with your prompt");
    }
}


void MainWindow::on_pushButton_2_pressed()
{
    QMessageBox::information(this, "Info", "Save button has been pressed");
}


void MainWindow::on_pushButton_3_pressed()
{
    // QMessageBox::information(this, "Info", ui->textEdit1->toPlainText());
}

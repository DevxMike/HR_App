#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <qmessagebox.h>
#include "utils.h"


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

    if(is_string_empty(tmp)){
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
    const auto col1_text = ui->textEdit1->toPlainText();
    const auto col2_text = ui->textEdit1_2->toPlainText();
    const auto col3_text = ui->textEdit1_3->toPlainText();
    const auto col4_text = ui->textEdit1_4->toPlainText();
}

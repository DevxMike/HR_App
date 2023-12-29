#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <qmessagebox.h>
#include "utils.h"
#include <vector>
#include <fstream>
#include <qinputdialog.h>

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
        QMessageBox::information(this, "Info", "Passing prompt to GPT");
        // TODO
        // create new thread and prompt AI
        // then update textEdit objects
    }
}


void MainWindow::on_pushButton_2_pressed()
{
    auto fname = QInputDialog::getText(this, "Enter file name", "File name:", QLineEdit::Normal, "");

    if(is_string_empty(fname)){
        QMessageBox::information(this, "Error", "No file name provided!");
        return;
    }
    else{
        // QMessageBox::information(this, "Info", fname);
        std::vector<QString> text_content{
            ui->textEdit1->toPlainText(),
            ui->textEdit1_2->toPlainText(),
            ui->textEdit1_3->toPlainText(),
            ui->textEdit1_4->toPlainText()
        };

        std::ofstream htmlFile(fname.toStdString());

        if(htmlFile.is_open()){
            htmlFile << "<!DOCTYPE html>\n";
            htmlFile << "<html>\n";
            htmlFile << "<head>\n";
            htmlFile << "<title>Table with offer</title>\n";
            htmlFile << "<style>\n";
            htmlFile << "body { width: 21cm; margin: 0 auto; }\n"; // Set the width of the body to match A4
            htmlFile << "table { width: 100%; border-collapse: collapse; height: 29.7cm; }\n"; // Set the height of the entire table
            htmlFile << "td { border: 1px solid black; padding: 8px; }\n";
            htmlFile << "</style>\n";
            htmlFile << "</head>\n";
            htmlFile << "<body>\n";
            htmlFile << "<table>\n"; // No need for border=\"1\" if you are using CSS for styling



            for(const auto& s : text_content){
                htmlFile << "<tr>\n";
                htmlFile << "<td>" << s.toStdString() << "</td>\n";
                htmlFile << "</tr>\n";
            }

            htmlFile << "</table>\n";
            htmlFile << "</body>\n";
            htmlFile << "</html>\n";

            htmlFile.close();
        }
        else{
            QMessageBox::information(this, "Error", "Could not open the file!");
        }
    }
    // std::ofstream html_output("")
}


void MainWindow::on_pushButton_3_pressed()
{
    QMessageBox::information(this, "Info", "Analysis button has been pressed");
}

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <qmessagebox.h>
#include "utils.h"
#include <vector>
#include <fstream>
#include <qinputdialog.h>
#include <QtPrintSupport/qprinter.h>
#include <string>

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

        std::ofstream htmlFile(fname.toStdString() + ".html");

        if(htmlFile.is_open()){
            std::string html_content = "";
            html_content += "<!DOCTYPE html>\n";
            html_content += "<html>\n";
            html_content += "<head>\n";
            html_content += "<title>Table with offer</title>\n";
            html_content += "<style>\n";
            html_content += "body { width: 21cm; margin: 0 auto; }\n"; // Set the width of the body to match A4
            html_content += "table { width: 100%; border-collapse: collapse; height: 29.7cm; }\n"; // Set the height of the entire table
            html_content += "td { border: 1px solid black; padding: 8px; }\n";
            html_content += "</style>\n";
            html_content += "</head>\n";
            html_content += "<body>\n";
            html_content += "<table>\n"; // No need for border=\"1\" if you are using CSS for styling

            for(const auto& s : text_content){
                html_content += "<tr>\n";
                html_content += "<td>" + s.toStdString() + "</td>\n";
                html_content += "</tr>\n";
            }

            html_content += "</table>\n";
            html_content += "</body>\n";
            html_content += "</html>\n";

            htmlFile << html_content;
            htmlFile.close();

            QMessageBox msgBox;
            msgBox.setText("Do you want to create a PDF file?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);

            if(msgBox.exec() == QMessageBox::Yes){
                QMessageBox::information(this, "Info", "Saving to PDF");
                QTextDocument document;
                QPrinter printer;

                document.setHtml(QString::fromStdString(html_content));

                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setOutputFileName(fname + ".pdf");

                document.setPageSize(QSizeF(210, 297));
                document.setDocumentMargin(0);

                document.print(&printer);
            }
        }
        else{
            QMessageBox::information(this, "Error", "Could not open the file!");
        }
    }
}


void MainWindow::on_pushButton_3_pressed()
{
    QMessageBox::information(this, "Info", "Analysis button has been pressed");
}

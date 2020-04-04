#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <fstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    find_from_file_(""),
    find_what_(""),
    status_("")
{
    ui->setupUi(this);

    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::reset_button_clicked);

    connect(ui->FindPushButton, &QPushButton::clicked, this, &MainWindow::     );
    connect(ui->matchCheckBox, &QCheckBox::pressed, this, &MainWindow::)
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_FindPushButton_clicked()
{
    ifstream file_object(ui->fileLineEdit){
        ui->textBrowser->     ("File found")
    }else{
        ui->textBrowser->     ("File not found")
    }
    if(find(ui->keyLineEdit) == std::npos){
        ui->textBrowser->     ("File found")
    }else{
        ui->textBrowser->     ("File not found")
    }
}

void MainWindow::on_matchCheckBox_clicked(bool checked)
{

}

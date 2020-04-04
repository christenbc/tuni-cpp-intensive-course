#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    timer(new QTimer(this)),

    ui(new Ui::MainWindow),

    seconds_(0),
    minutes_(0)
{
    ui->setupUi(this);

    connect(timer, &QTimer::timeout, this, &MainWindow::second_passed);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::reset_button_clicked);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::stop_button_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startButton_clicked()
{
    timer->start(1000);
    ui->lcdNumberMin->setStyleSheet("background-color: darkCyan");
    ui->lcdNumberSec->setStyleSheet("background-color: green");

}

void MainWindow::second_passed()
{
    ++seconds_;
    ui->lcdNumberSec->display(seconds_);
    if(seconds_ == 60){
        seconds_ = 0;
        ++minutes_;
        ui->lcdNumberMin->display((minutes_));
        ui->lcdNumberSec->display(seconds_);
    }
}

void MainWindow::reset_button_clicked()
{
    seconds_ = 0;
    minutes_ = 0;
    ui->lcdNumberMin->display((minutes_));
    ui->lcdNumberSec->display(seconds_);
}

void MainWindow::stop_button_clicked()
{
    timer->stop();
    ui->lcdNumberMin->setStyleSheet("background-color: lightGray");
    ui->lcdNumberSec->setStyleSheet("background-color: lightGray");
}

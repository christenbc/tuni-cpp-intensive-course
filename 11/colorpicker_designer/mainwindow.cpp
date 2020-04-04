#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSlider>
#include <QSpinBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->horizontalSliderRed->setMinimum(0);
    ui->horizontalSliderRed->setMaximum(RGB_VALUE_MAX);

    ui->horizontalSliderGreen->setMinimum(0);
    ui->horizontalSliderGreen->setMaximum(RGB_VALUE_MAX);

    ui->horizontalSliderBlue->setMinimum(0);
    ui->horizontalSliderBlue->setMaximum(RGB_VALUE_MAX);

    ui->spinBoxRed->setMinimum(0);
    ui->spinBoxRed->setMaximum(RGB_VALUE_MAX);
    ui->spinBoxGreen->setMinimum(0);
    ui->spinBoxGreen->setMaximum(RGB_VALUE_MAX);
    ui->spinBoxBlue->setMinimum(0);
    ui->spinBoxBlue->setMaximum(RGB_VALUE_MAX);

    connect(ui->horizontalSliderRed, &QSlider::valueChanged, this, &MainWindow::onColorChanged); //this is the same as self in Python
    connect(ui->horizontalSliderGreen, &QSlider::valueChanged, this, &MainWindow::onColorChanged);
    connect(ui->horizontalSliderBlue, &QSlider::valueChanged, this, &MainWindow::onColorChanged);

    //connect(ui->horizontalSliderGreen, &QSlider::valueChanged, this, &MainWindow::greenSliderChanged);
    //connect(ui->spinBoxGreen, &QSpinBox::valueChanged, this, &MainWindow::greenSpinboxChanged);
    //connect(ui->spinBoxGreen, &QSpinBox::valueChanged, ui->horizontalSliderGreen, &QSlider::setValue); //alternative way, send signal
    connect(ui->horizontalSliderGreen, SIGNAL(valueChanged(int)), ui->spinBoxGreen, SLOT(setValue(int)));
    connect(ui->spinBoxGreen, SIGNAL(valueChanged(int)), ui->horizontalSliderGreen, SLOT(setValue(int)));
    connect(ui->horizontalSliderBlue, SIGNAL(valueChanged(int)), ui->spinBoxBlue, SLOT(setValue(int)));
    connect(ui->spinBoxBlue, SIGNAL(valueChanged(int)), ui->horizontalSliderBlue, SLOT(setValue(int)));


    onColorChanged();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onColorChanged() //it goes in the private slots
{
    //qDebug() << "onColorChanged";
    QColor selectedColor(ui->horizontalSliderRed->value(),
                         ui->horizontalSliderGreen->value(),
                         ui->horizontalSliderBlue->value());

    QPixmap colorMap(64, 64);
    colorMap.fill(selectedColor);
    ui->colorLabel->setPixmap(colorMap);
}
/*
void MainWindow::greenSliderChanged()
{
    int green_value = ui->horizontalSliderGreen->value();
    ui->spinBoxGreen->setValue(green_value);
}

void MainWindow::greenSpinboxChanged()
{
    int green_value = ui->spinBoxGreen->value();
    ui->horizontalSliderGreen->setValue(green_value);
}
*/

void MainWindow::on_spinBoxBlue_valueChanged(int new_value)
{
    ui->horizontalSliderBlue->setValue(new_value);
}

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <cmath>

#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include <QVBoxLayout>

int convert(QString input);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    layout = new QVBoxLayout(ui->centralwidget);
     ui ->label3 -> setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onButtonClicked()
{
    // Меняем текст метки
    // ui->label1->setText("Кнопка нажата!");
    QString input = ui->lineEdit->text();
    // Добавляем новую кнопку в layout
    // QPushButton *newButton = new QPushButton("Новая кнопка", this);
    // layout->addWidget(newButton);
    try{
        int result = convert(input);
        ui -> label3 -> setText(QString::number(result));
    } catch(const std::exception &e){
        QMessageBox::critical(this, "Ошибка", e.what());
    }

}


int convert(QString input){
    if(input.size()>8)
        throw std::length_error("Длина превышает 8");
    int decimal=0;
    for(int i = 0; i < input.size(); ++i){
        if(input[i]=='1')
            decimal += pow(2,input.size()-1-i);
        else if(input[i]=='0')
            decimal += 0;
        else
            throw std::logic_error("Неверный аргумент");
    }
    return decimal;
}


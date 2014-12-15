#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <stdlib.h>

#include <QGraphicsItem>
#include <QPaintEvent>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QMap>

//#include <osmium/io/any_input.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     resize(800,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    QMainWindow::close();
}

void MainWindow::on_pushButton_clicked()
{

    char alma[100] = "halott vagy";

    ui->textEdit->toPlainText();
    ui->textEdit->setPlainText("");
    ui->textEdit_2->setPlainText(alma);
    /*Majd*/
}

void MainWindow::on_textEdit_textChanged()
{

}

void MainWindow::on_frame_destroyed()
{
 /*   google::protobuf::ShutdownProtobufLibrary();

    map = new Map(buffer, nodes, scene());
    map->clean_buffer();
    map->draw_map();*/
}

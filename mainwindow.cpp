#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "subwindows/addattributedialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    NodeContainer b1;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AddAtribute_clicked()
{
    AddAttributeDialog *wa = new AddAttributeDialog(this);
    wa->show();
}

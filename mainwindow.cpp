#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "staffwriter.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Staff temp;
    ui->typeCombo->addItems(temp.staffTypes());

    connect(ui->processButton, SIGNAL(clicked()), this, SLOT(process()));
}

void MainWindow::process()
{
    QString name = ui->name->text();
    QDate date = ui->date->date();
    QString type = ui->typeCombo->currentText();

    Staff *staff = new Staff(name, date, type);
    list.addStaff(staff);

    ui->name->clear();
    ui->date->setDate(QDate(2000, 01, 01));
    ui->typeCombo->setCurrentIndex(0);
    ui->name->setFocus();

    StaffWriter writer;
    if (writer.writeToFile(staff))
        QMessageBox::information(this, "Output", "Staff detail saved and written to file");
    else
        QMessageBox::information(this, "Output", "Staff detail saved and not written to file");
}

MainWindow::~MainWindow()
{
    delete ui;
}

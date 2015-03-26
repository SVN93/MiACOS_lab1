#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::nameOfFileFromFileDialog()
{
    QString filename = QFileDialog::getOpenFileName(
            this,
            tr("Open wav file"),
            QDir::currentPath(),
            tr("Wav file (*.wav);;All files (*.*)") );

    return filename;
}

void MainWindow::on_choseFileButton_clicked()
{
    QString filename = nameOfFileFromFileDialog();

    ui->fileSourceLabel->setText(filename);
}

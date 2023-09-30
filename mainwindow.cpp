#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->com_serialList->addItem("--");
}



void MainWindow:: on_btn_updateList_clicked(){
    serialList = QSerialPortInfo::availablePorts();

    ui->com_serialList->clear();
    for (int i = 0; i < serialList.size(); i++){
        QString str = serialList[i].portName()+=' ';
        str+=serialList[i].description();
        ui->com_serialList->addItem( str );
    }
    ui->com_serialList->setEnabled(1);
    ui->btn_openPort->setEnabled(1);
}

void MainWindow:: on_btn_openPort_clicked(){
    std::cout<< ui->com_serialList->currentIndex() << std::endl;
    serialPort.setPort(serialList[ui->com_serialList->currentIndex()]);
    std::cout<< serialPort.portName().toStdString() << std::endl;
    ui->btn_send->setEnabled(1);
    serialPort.setBaudRate(9600);
    serialPort.open(QIODevice::ReadWrite);
}

void MainWindow:: on_btn_send_clicked(){
    QString str = ui->lin_message->text();
    if (ui->che_newLine->isChecked() == true)
        str += '\n';
    if (ui->che_return->isChecked() == true)
        str += '\r';
    std::cout<< str.toStdString() << std::endl;
    serialPort.write( str.toStdString().c_str() );
    if (ui->che_clearAfterTransmission->isChecked() == true)
        ui->lin_message->clear();
}

void MainWindow:: on_lin_message_returnPressed(){
    on_btn_send_clicked();
}


MainWindow::~MainWindow()
{
    delete ui;
}


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSerialPort>
#include <QSerialPortInfo>
#include <iostream>

//my libraries

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QList <QSerialPortInfo> serialList;
    QSerialPort serialPort;

private slots:
    void on_btn_openPort_clicked();
    void on_btn_updateList_clicked();
    void on_btn_send_clicked();
    void on_lin_message_returnPressed();
};
#endif // MAINWINDOW_H

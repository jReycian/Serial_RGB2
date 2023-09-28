#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //    arduino = new QSerialPort;

    //    qDebug () << "Number of available ports: " << QSerialPortInfo::availablePorts().length();
    //    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    //    {
    //        qDebug() << "\nHas vendor ID: " << serialPortInfo.hasVendorIdentifier();
    //        if (serialPortInfo.hasVendorIdentifier())
    //        {
    //            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
    //        }
    //        qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
    //        if (serialPortInfo.hasProductIdentifier())
    //        {
    //            qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
    //        }
    //    }

    ui->label_rgb_value->setDisabled(true);
    ui->label_red_name->setStyleSheet(QString("QLabel{color:rgb(255,0,0);}"));
    ui->label_green_name->setStyleSheet(QString("QLabel{color:rgb(0,255,0);}"));
    ui->label_blue_name->setStyleSheet(QString("QLabel{color:rgb(0,0,255);}"));

}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_red_horizontalSlider_valueChanged(int value)
{
    value = ui->red_horizontalSlider->value();
    ui->label_red->setText(QString::number(value).arg(1));
    red = value;
    RGBValue(red, green, blue);
}


void Dialog::on_green_horizontalSlider_valueChanged(int value)
{
    value = ui->green_horizontalSlider->value();
    ui->label_green->setText(QString::number(value).arg(1));
    green = value;
    RGBValue(red, green, blue);
}


void Dialog::on_blue_horizontalSlider_valueChanged(int value)
{
    value = ui->blue_horizontalSlider->value();
    ui->label_blue->setText(QString::number(value).arg(1));
    blue = value;
    RGBValue(red, green, blue);
}

void Dialog::RGBValue(int red, int green, int blue)
{
   ui->label_rgb_value->setText("RGB: {" + QString::number(red) + "," + QString::number(green) + "," + QString::number(blue)+ "}");

   QString r =  QString::number(red);
   QString g =  QString::number(green);
   QString b =  QString::number(blue);

   ui->label_Header->setStyleSheet(QString("QLabel{color: rgb("+r+","+g+","+b+");}"));
}

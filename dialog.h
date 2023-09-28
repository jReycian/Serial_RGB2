#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_red_horizontalSlider_valueChanged(int value);

    void on_green_horizontalSlider_valueChanged(int value);

    void on_blue_horizontalSlider_valueChanged(int value);

    void RGBValue(int red, int green, int blue);

private:
    Ui::Dialog *ui;
    QSerialPort *arduino;
    int red = 0, green = 0, blue = 0;
};
#endif // DIALOG_H

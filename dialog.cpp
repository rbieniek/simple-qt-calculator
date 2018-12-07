#include "dialog.h"
#include "ui_dialog.h"
#include "cmath"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_1_clicked()
{
    ui->lineEdit_Eingabe->insert(QString("1"));
}

void Dialog::on_pushButton_2_clicked()
{
    ui->lineEdit_Eingabe->insert(QString("2"));

}

void Dialog::on_pushButton_3_clicked()
{
    ui->lineEdit_Eingabe->insert(QString("3"));

}

void Dialog::on_pushButton_4_clicked()
{
    ui->lineEdit_Eingabe->insert(QString("4"));

}

void Dialog::on_pushButton_5_clicked()
{
    ui->lineEdit_Eingabe->insert(QString("5"));

}

void Dialog::on_pushButton_6_clicked()
{
    ui->lineEdit_Eingabe->insert(QString("6"));

}

void Dialog::on_pushButton_7_clicked()
{
    ui->lineEdit_Eingabe->insert(QString("7"));

}

void Dialog::on_pushButton_8_clicked()
{
    ui->lineEdit_Eingabe->insert(QString("8"));

}

void Dialog::on_pushButton_9_clicked()
{
    ui->lineEdit_Eingabe->insert(QString("9"));

}

void Dialog::on_pushButton_komma_clicked()
{
    ui->lineEdit_Eingabe->insert(QString(","));

}

void Dialog::on_pushButton_0_clicked()
{
    ui->lineEdit_Eingabe->insert(QString("0"));

}

void Dialog::on_pushButton_negativ_clicked()
{
    ui->lineEdit_Eingabe->insert(QString("-"));

}

void Dialog::on_pushButton_plus_clicked()
{
    ui->lineEdit_Eingabe->insert(QString("+"));

}

void Dialog::on_pushButton_minus_clicked()
{
    ui->lineEdit_Eingabe->insert(QString("-"));

}

void Dialog::on_pushButton_mal_clicked()
{
    ui->lineEdit_Eingabe->insert(QString("*"));

}

void Dialog::on_pushButto_geteilt_clicked()
{
    ui->lineEdit_Eingabe->insert(QString("/"));

}

void Dialog::on_pushButton_gleich_clicked()
{
    double E;
          E = ui->lineEdit_Eingabe->text().toDouble();

}

void Dialog::on_pushButton_loeschen_clicked()
{
    ui->lineEdit_Eingabe->backspace();

}

void Dialog::on_pushButton_neu_clicked()
{
ui->lineEdit_Eingabe->clear();
ui->textEdit_Rechenschritte->clear();


}

#include <qtextstream.h>
#include "dialog.h"
#include "ui_dialog.h"
#include "cmath"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    loesche_eingabe_zeile();
    vorherige_operation = NONE;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_1_clicked()
{
    ziffer_hinzufuegen('1');
}

void Dialog::on_pushButton_2_clicked()
{
    ziffer_hinzufuegen('2');
}

void Dialog::on_pushButton_3_clicked()
{
    ziffer_hinzufuegen('3');
}

void Dialog::on_pushButton_4_clicked()
{
    ziffer_hinzufuegen('4');
}

void Dialog::on_pushButton_5_clicked()
{
    ziffer_hinzufuegen('5');
}

void Dialog::on_pushButton_6_clicked()
{
    ziffer_hinzufuegen('6');
}

void Dialog::on_pushButton_7_clicked()
{
    ziffer_hinzufuegen('7');
}

void Dialog::on_pushButton_8_clicked()
{
    ziffer_hinzufuegen('8');
}

void Dialog::on_pushButton_9_clicked()
{
    ziffer_hinzufuegen('9');
}

void Dialog::on_pushButton_komma_clicked()
{
    komma_hinzufuegen();
}

void Dialog::on_pushButton_0_clicked()
{
    ziffer_hinzufuegen('0');
}

void Dialog::on_pushButton_negativ_clicked()
{
    wechel_vorzeichen();
}

void Dialog::on_pushButton_plus_clicked()
{
    operation_ausfuehren(PLUS);
}

void Dialog::on_pushButton_minus_clicked()
{
    operation_ausfuehren(MINUS);
}

void Dialog::on_pushButton_mal_clicked()
{
    operation_ausfuehren(MULT);
}

void Dialog::on_pushButto_geteilt_clicked()
{
    operation_ausfuehren(DIV);
}

void Dialog::on_pushButton_gleich_clicked()
{
    berechne_gesamt();
}

void Dialog::on_pushButton_loeschen_clicked()
{
    loesche_eingabe_zeile();
    vorherige_operation = NONE;
}

void Dialog::on_pushButton_neu_clicked()
{
    loesche_eingabe_zeile();
    vorherige_operation = NONE;
    ui->plainTextEdit_Rechenschritte->clear();
}

void Dialog::komma_verriegeln() {
    ui->pushButton_komma->setEnabled(false);
}

void Dialog::komma_entriegeln() {
    ui->pushButton_komma->setEnabled(true);
}

void Dialog::vorzeichen_verriegeln() {
    ui->pushButton_negativ->setEnabled(false);
}

void Dialog::vorzeichen_entriegeln() {
    ui->pushButton_negativ->setEnabled(true);
}

void Dialog::operation_verriegeln() {
    ui->pushButto_geteilt->setEnabled(false);
    ui->pushButton_mal->setEnabled(false);
    ui->pushButton_minus->setEnabled(false);
    ui->pushButton_plus->setEnabled(false);
    ui->pushButton_power2->setEnabled(false);
    ui->pushButton_sqrt->setEnabled(false);
}

void Dialog::operationen_entriegeln() {
    ui->pushButto_geteilt->setEnabled(true);
    ui->pushButton_mal->setEnabled(true);
    ui->pushButton_minus->setEnabled(true);
    ui->pushButton_plus->setEnabled(true);
    ui->pushButton_power2->setEnabled(true);
    ui->pushButton_sqrt->setEnabled(true);
}

void Dialog::ergebnis_berechnen_entriegeln() {
    ui->pushButton_gleich->setEnabled(true);
}

void Dialog::ergebnis_berechnen_verriegeln() {
    ui->pushButton_gleich->setEnabled(false);
}

void Dialog::ausdruck_anzeigen(const QString& expression) {
    ui->plainTextEdit_Rechenschritte->appendPlainText(expression);
}

void Dialog::on_pushButton_sqrt_clicked()
{

}

void Dialog::on_pushButton_power2_clicked()
{

}

// Controller operationen
void Dialog::operation_ausfuehren(int operation) {
    bool valid = false;
    double eingabe_wert = eingabe_zeile.toDouble(&valid);

    if(valid) {
        if(vorherige_operation != NONE) {
            double ergebnis = berechne(eingabe_wert);

            operation_anzeigen(eingabe_wert, ergebnis);
            zwischen_ergebnis = ergebnis;
        } else {
            zwischen_ergebnis = eingabe_wert;
        }

        vorherige_operation = operation;
        loesche_eingabe_zeile();
    }
}

void Dialog::berechne_gesamt() {
    bool valid = false;
    double eingabe_wert = eingabe_zeile.toDouble(&valid);

    if(valid) {
        double ergebnis = berechne(eingabe_wert);

        operation_anzeigen(eingabe_wert, ergebnis);
        vorherige_operation = NONE;
        loesche_eingabe_zeile();
    }

}

double Dialog::berechne(const double operand) {
    double ergebnis = 0.0;

    switch (vorherige_operation) {
    case DIV:
        ergebnis = zwischen_ergebnis / operand;
        break;
    case MINUS:
        ergebnis = zwischen_ergebnis - operand;
        break;
    case MULT:
        ergebnis = zwischen_ergebnis * operand;
        break;
    case PLUS:
        ergebnis = zwischen_ergebnis + operand;
        break;
    default:
        break;
    }

    return ergebnis;
}

void Dialog::berechne_power2() {

}

void Dialog::berechne_sqrt() {

}

// Model operationen
void Dialog::ziffer_hinzufuegen(const QChar digit) {
    eingabe_zeile.append(digit);

    if(!(eingabe_zeile.indexOf('.') >= 0)) {
        komma_entriegeln();
    }

    ui->lineEdit_Eingabe->setText(eingabe_zeile_darstellen());
    vorzeichen_entriegeln();

    bool ok = false;
    double aktueller_wert = eingabe_zeile.toDouble(&ok);

    if(ok && (vorherige_operation != DIV || aktueller_wert != 0.0)) {
        operationen_entriegeln();

        if(vorherige_operation != NONE) {
            ergebnis_berechnen_entriegeln();
        }
    } else {
        operation_verriegeln();
        ergebnis_berechnen_verriegeln();
    }
}

void Dialog::komma_hinzufuegen() {
    eingabe_zeile.append('.');

    komma_verriegeln();
    ui->lineEdit_Eingabe->setText(eingabe_zeile_darstellen());
}

void Dialog::loesche_eingabe_zeile() {
    eingabe_zeile.clear();

    komma_verriegeln();
    vorzeichen_verriegeln();
    operation_verriegeln();
    ergebnis_berechnen_verriegeln();

    ui->lineEdit_Eingabe->setText(eingabe_zeile_darstellen());
}

void Dialog::wechel_vorzeichen() {
    if(eingabe_zeile.length() > 0) {
        if(eingabe_zeile.startsWith('-')) {
            eingabe_zeile.remove(0, 1);
        } else {
            eingabe_zeile.insert(0, '-');
        }

        ui->lineEdit_Eingabe->setText(eingabe_zeile_darstellen());
    }
}

void Dialog::operation_anzeigen(const double operand, const double ergebnis) {
    QString result;
    QTextStream(&result) << zwischen_ergebnis << vorherige_operation_drucken() << operand << "=" << ergebnis;

    ausdruck_anzeigen(result);
}

char Dialog::vorherige_operation_drucken() {
    switch (vorherige_operation) {
    case DIV:
        return '/';
    case MINUS:
        return '-';
    case MULT:
        return '*';
    case PLUS:
        return '+';
    default:
        return ' ';
    }
}

QString Dialog::eingabe_zeile_darstellen() {
    if(vorherige_operation != NONE) {
        QString new_input_line;

        QTextStream(&new_input_line) << zwischen_ergebnis << vorherige_operation_drucken() << eingabe_zeile;

        return new_input_line;
    } else {
        return eingabe_zeile;
    }

}

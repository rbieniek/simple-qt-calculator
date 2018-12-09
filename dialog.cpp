#include <qtextstream.h>
#include "dialog.h"
#include "ui_dialog.h"
#include "cmath"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    clear_input_line();
    clear_vorherige_operation();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_1_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("1"));
    add_digit('1');
}

void Dialog::on_pushButton_2_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("2"));

    add_digit('2');
}

void Dialog::on_pushButton_3_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("3"));

    add_digit('3');
}

void Dialog::on_pushButton_4_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("4"));

    add_digit('4');
}

void Dialog::on_pushButton_5_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("5"));

    add_digit('5');
}

void Dialog::on_pushButton_6_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("6"));

    add_digit('6');
}

void Dialog::on_pushButton_7_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("7"));

    add_digit('7');
}

void Dialog::on_pushButton_8_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("8"));

    add_digit('8');
}

void Dialog::on_pushButton_9_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("9"));

    add_digit('9');
}

void Dialog::on_pushButton_komma_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString(","));

    add_comma();
}

void Dialog::on_pushButton_0_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("0"));

    add_digit('0');
}

void Dialog::on_pushButton_negativ_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("-"));
    toggle_sign();
}

void Dialog::on_pushButton_plus_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("+"));
    operation_ausfuehren(operation_t::PLUS);
}

void Dialog::on_pushButton_minus_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("-"));
    operation_ausfuehren(operation_t::MINUS);
}

void Dialog::on_pushButton_mal_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("*"));
    operation_ausfuehren(operation_t::MULT);
}

void Dialog::on_pushButto_geteilt_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("/"));
    operation_ausfuehren(operation_t::DIV);
}

void Dialog::on_pushButton_gleich_clicked()
{
//    double E;
//          E = ui->lineEdit_Eingabe->text().toDouble();
    berechne_gesamt();
}

void Dialog::on_pushButton_loeschen_clicked()
{
//    ui->lineEdit_Eingabe->backspace();
    clear_input_line();
    clear_vorherige_operation();
}

void Dialog::on_pushButton_neu_clicked()
{
// ui->lineEdit_Eingabe->clear();
// ui->textEdit_Rechenschritte->clear();

    clear_input_line();
    clear_vorherige_operation();
    ui->plainTextEdit_Rechenschritte->clear();
}

void Dialog::disable_comma() {
    ui->pushButton_komma->setEnabled(false);
}

void Dialog::enable_comma() {
    ui->pushButton_komma->setEnabled(true);
}

void Dialog::update_input_line(const QString& input_line) {
    ui->lineEdit_Eingabe->setText(input_line);
}

void Dialog::disable_negativ() {
    ui->pushButton_negativ->setEnabled(false);
}

void Dialog::enable_negativ() {
    ui->pushButton_negativ->setEnabled(true);
}

void Dialog::disable_operationen() {
    ui->pushButto_geteilt->setEnabled(false);
    ui->pushButton_mal->setEnabled(false);
    ui->pushButton_minus->setEnabled(false);
    ui->pushButton_plus->setEnabled(false);
    ui->pushButton_power2->setEnabled(false);
    ui->pushButton_sqrt->setEnabled(false);
}

void Dialog::enable_operationen() {
    ui->pushButto_geteilt->setEnabled(true);
    ui->pushButton_mal->setEnabled(true);
    ui->pushButton_minus->setEnabled(true);
    ui->pushButton_plus->setEnabled(true);
    ui->pushButton_power2->setEnabled(true);
    ui->pushButton_sqrt->setEnabled(true);
}

void Dialog::enable_equal() {
    ui->pushButton_gleich->setEnabled(true);
}

void Dialog::disable_equal() {
    ui->pushButton_gleich->setEnabled(false);
}

void Dialog::show_expression(const QString& expression) {
    ui->plainTextEdit_Rechenschritte->appendPlainText(expression);
}

void Dialog::on_pushButton_sqrt_clicked()
{

}

void Dialog::on_pushButton_power2_clicked()
{

}

// Controller operationen
void Dialog::operation_ausfuehren(const operation_t operation) {
    bool valid = false;
    double eingabe_wert = get_eingabe_wert(&valid);

    if(valid) {
        if(get_vorherige_operation_vorhanden()) {
            double ergebnis = berechne(eingabe_wert);

            operation_anzeigen(eingabe_wert, ergebnis);
            set_zwischen_ergebnis(ergebnis);
        } else {
            set_zwischen_ergebnis(eingabe_wert);
        }

        set_vorherige_operation(operation);
        clear_input_line();
    }
}

void Dialog::berechne_gesamt() {
    bool valid = false;
    double eingabe_wert = get_eingabe_wert(&valid);

    if(valid) {
        double ergebnis = berechne(eingabe_wert);

        operation_anzeigen(eingabe_wert, ergebnis);
        clear_vorherige_operation();
        clear_input_line();
    }

}

double Dialog::berechne(const double operand) {
    double ergebnis = 0.0;

    switch (get_vorherige_operation()) {
    case DIV:
        ergebnis = get_zwischen_ergebnis() / operand;
        break;
    case MINUS:
        ergebnis = get_zwischen_ergebnis() - operand;
        break;
    case MULT:
        ergebnis = get_zwischen_ergebnis() * operand;
        break;
    case PLUS:
        ergebnis = get_zwischen_ergebnis() + operand;
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
void Dialog::add_digit(const QChar digit) {
    m_input_line.append(digit);

    if(!(m_input_line.indexOf(',') >= 0)) {
        enable_comma();
    }

    update_input_line(build_input_line());
    enable_negativ();

    bool ok = false;
    double aktueller_wert = m_input_line.toDouble(&ok);

    if(ok && (m_vorherige_operation != operation_t::DIV || aktueller_wert != 0.0)) {
        enable_operationen();

        if(get_vorherige_operation_vorhanden()) {
            enable_equal();
        }
    } else {
        disable_operationen();
        disable_equal();
    }
}

void Dialog::add_comma() {
    m_input_line.append('.');

    disable_comma();
    update_input_line(build_input_line());
}

void Dialog::clear_input_line() {
    m_input_line.clear();

    disable_comma();
    disable_negativ();
    disable_operationen();
    disable_equal();

    update_input_line(build_input_line());
}

void Dialog::toggle_sign() {
    if(m_input_line.length() > 0) {
        if(m_input_line.startsWith('-')) {
            m_input_line.remove(0, 1);
        } else {
            m_input_line.insert(0, '-');
        }

        update_input_line(build_input_line());
    }
}

void Dialog::operation_anzeigen(const double operand, const double ergebnis) {
    QString result;
    QTextStream(&result) << m_zwischen_ergebnis << vorherige_operation_drucken() << operand << "=" << ergebnis;

    show_expression(result);
}

char Dialog::vorherige_operation_drucken() {
    switch (m_vorherige_operation) {
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

QString Dialog::build_input_line() {
    if(get_vorherige_operation_vorhanden()) {
        QString new_input_line;

        QTextStream(&new_input_line) << get_zwischen_ergebnis() << vorherige_operation_drucken() << m_input_line;

        return new_input_line;
    } else {
        return m_input_line;
    }

}

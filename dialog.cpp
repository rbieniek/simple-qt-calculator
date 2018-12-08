#include "dialog.h"
#include "ui_dialog.h"
#include "cmath"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    m_model = new Model(this);
    m_controller = new Controller(m_model);

    m_model->clear_input_line();
    m_model->clear_vorherige_operation();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_1_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("1"));
    m_model->add_digit('1');
}

void Dialog::on_pushButton_2_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("2"));

    m_model->add_digit('2');
}

void Dialog::on_pushButton_3_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("3"));

    m_model->add_digit('3');
}

void Dialog::on_pushButton_4_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("4"));

    m_model->add_digit('4');
}

void Dialog::on_pushButton_5_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("5"));

    m_model->add_digit('5');
}

void Dialog::on_pushButton_6_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("6"));

    m_model->add_digit('6');
}

void Dialog::on_pushButton_7_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("7"));

    m_model->add_digit('7');
}

void Dialog::on_pushButton_8_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("8"));

    m_model->add_digit('8');
}

void Dialog::on_pushButton_9_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("9"));

    m_model->add_digit('9');
}

void Dialog::on_pushButton_komma_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString(","));

    m_model->add_comma();
}

void Dialog::on_pushButton_0_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("0"));

    m_model->add_digit('0');
}

void Dialog::on_pushButton_negativ_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("-"));
    m_model->toggle_sign();
}

void Dialog::on_pushButton_plus_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("+"));
    m_controller->operation_ausfuehren(operation_t::PLUS);
}

void Dialog::on_pushButton_minus_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("-"));
    m_controller->operation_ausfuehren(operation_t::MINUS);
}

void Dialog::on_pushButton_mal_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("*"));
    m_controller->operation_ausfuehren(operation_t::MULT);
}

void Dialog::on_pushButto_geteilt_clicked()
{
//    ui->lineEdit_Eingabe->insert(QString("/"));
    m_controller->operation_ausfuehren(operation_t::DIV);
}

void Dialog::on_pushButton_gleich_clicked()
{
//    double E;
//          E = ui->lineEdit_Eingabe->text().toDouble();
    m_controller->berechne_gesamt();
}

void Dialog::on_pushButton_loeschen_clicked()
{
//    ui->lineEdit_Eingabe->backspace();
    m_model->clear_input_line();
}

void Dialog::on_pushButton_neu_clicked()
{
// ui->lineEdit_Eingabe->clear();
// ui->textEdit_Rechenschritte->clear();

    m_model->clear_input_line();
    m_model->clear_vorherige_operation();
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

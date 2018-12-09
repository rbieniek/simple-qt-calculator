#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#define NONE 0
#define PLUS 1
#define MINUS 2
#define MULT 3
#define DIV 4

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void update_input_line(const QString& input_line);
    void disable_comma();
    void enable_comma();
    void disable_negativ();
    void enable_negativ();
    void enable_operationen();
    void disable_operationen();
    void show_expression(const QString& expression);
    void enable_equal();
    void disable_equal();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_komma_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_negativ_clicked();

    void on_pushButton_plus_clicked();

    void on_pushButton_minus_clicked();

    void on_pushButton_mal_clicked();

    void on_pushButto_geteilt_clicked();

    void on_pushButton_gleich_clicked();

    void on_pushButton_loeschen_clicked();

    void on_pushButton_neu_clicked();

    void on_pushButton_sqrt_clicked();

    void on_pushButton_power2_clicked();

protected:
    Ui::Dialog *ui;

private:
    // model daten
    QString m_input_line;

    double m_zwischen_ergebnis;
    int m_vorherige_operation = NONE;

    char vorherige_operation_drucken();
    void add_digit(const QChar digit);
    void add_comma();
    void clear_input_line();
    void toggle_sign();
    QString build_input_line();
    void operation_anzeigen(const double operand, const double ergebnis);
    void operation_ausfuehren(int operation);
    void berechne_sqrt();
    void berechne_power2();
    void berechne_gesamt();
    double berechne(const double operand);
};

#endif // DIALOG_H

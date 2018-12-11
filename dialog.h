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

private:
    Ui::Dialog *ui;

    QString eingabe_zeile;

    double zwischen_ergebnis;
    int vorherige_operation = NONE;

    char vorherige_operation_drucken();
    void ziffer_hinzufuegen(const QChar digit);
    void komma_hinzufuegen();
    void loesche_eingabe_zeile();
    void wechel_vorzeichen();
    void operation_anzeigen(const double operand, const double ergebnis);
    void operation_ausfuehren(int operation);
    void berechne_sqrt();
    void berechne_power2();
    void berechne_gesamt();
    double berechne(const double operand);

    void komma_verriegeln();
    void komma_entriegeln();
    void vorzeichen_verriegeln();
    void vorzeichen_entriegeln();
    void operation_verriegeln();
    void operationen_entriegeln(bool eingabewer_positiv);
    void ausdruck_anzeigen(const QString& expression);
    void ergebnis_berechnen_entriegeln();
    void ergebnis_berechnen_verriegeln();

    QString eingabe_zeile_darstellen();
};

#endif // DIALOG_H

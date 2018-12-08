#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "model.h"
#include "controller.h"
#include "updater.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog, public Updater
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    virtual void update_input_line(const QString& input_line);
    virtual void disable_comma();
    virtual void enable_comma();
    virtual void disable_negativ();
    virtual void enable_negativ();
    virtual void enable_operationen();
    virtual void disable_operationen();
    virtual void show_expression(const QString& expression);
    virtual void enable_equal();
    virtual void disable_equal();

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
    Model* m_model;
    Controller* m_controller;
};

#endif // DIALOG_H

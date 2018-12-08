#include "controller.h"

Controller::Controller(Model* model) : m_model(model) {

}

void Controller::operation_ausfuehren(const operation_t operation) {
    bool valid = false;
    double eingabe_wert = m_model->get_eingabe_wert(&valid);

    if(valid) {
        if(m_model -> get_vorherige_operation_vorhanden()) {
            double ergebnis = berechne(eingabe_wert);

            m_model->operation_anzeigen(eingabe_wert, ergebnis);
            m_model->set_zwischen_ergebnis(ergebnis);
        } else {
            m_model->set_zwischen_ergebnis(eingabe_wert);
        }

        m_model->set_vorherige_operation(operation);
        m_model->clear_input_line();
    }
}

void Controller::berechne_gesamt() {
    bool valid = false;
    double eingabe_wert = m_model->get_eingabe_wert(&valid);

    if(valid) {
        double ergebnis = berechne(eingabe_wert);

        m_model->operation_anzeigen(eingabe_wert, ergebnis);
        m_model->clear_vorherige_operation();
        m_model->clear_input_line();
    }

}

double Controller::berechne(const double operand) {
    double ergebnis = 0.0;

    switch (m_model->get_vorherige_operation()) {
    case DIV:
        ergebnis = m_model->get_zwischen_ergebnis() / operand;
        break;
    case MINUS:
        ergebnis = m_model->get_zwischen_ergebnis() - operand;
        break;
    case MULT:
        ergebnis = m_model->get_zwischen_ergebnis() * operand;
        break;
    case PLUS:
        ergebnis = m_model->get_zwischen_ergebnis() + operand;
        break;
    default:
        break;
    }

    return ergebnis;
}

void Controller::berechne_power2() {

}

void Controller::berechne_sqrt() {

}

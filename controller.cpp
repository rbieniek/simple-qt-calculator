#include "controller.h"

Controller::Controller(Model* model) : m_model(model) {

}

void Controller::berechne_operation(const QChar operation) {
    bool valid = false;
    double eingabe_wert = m_model->get_eingabe_wert(&valid);

    if(valid) {
        if(m_model->get_zwischen_ergebnis_vorhanden()) {
            double ergebnis;

            if(operation == '+') {
                ergebnis = m_model->get_zwischen_ergebnis() + eingabe_wert;
            } else if(operation == '-') {
                ergebnis = m_model->get_zwischen_ergebnis() - eingabe_wert;
            } else if(operation == '*') {
                ergebnis = m_model->get_zwischen_ergebnis() * eingabe_wert;
            } else if(operation == '/') {
                ergebnis = m_model->get_zwischen_ergebnis() / eingabe_wert;
            }
        } else {
            m_model->set_zwischen_ergebnis(eingabe_wert);
        }
    }
}

void Controller::berechne_gesamt() {

}

void Controller::berechne_power2() {

}

void Controller::berechne_sqrt() {

}

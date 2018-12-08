#ifndef MODEL_H
#define MODEL_H

#include <qstring.h>
#include "updater.h"
#include "operation.h"

class Model {
public:
    Model(Updater* updater);

    void add_digit(const QChar digit);
    void add_comma();
    void clear_input_line();
    void toggle_sign();

    void operation_anzeigen(const double operand, const double ergebnis);

    double get_eingabe_wert(bool *ok=nullptr) {
        return m_input_line.toDouble(ok);
    }

    double get_zwischen_ergebnis() {
        return m_zwischen_ergebnis;
    }

    operation_t get_vorherige_operation() {
        return m_vorherige_operation;
    }

    bool get_vorherige_operation_vorhanden() {
        return m_vorherige_operation != operation_t::NONE;
    }

    void set_vorherige_operation(const operation_t operation) {
        m_vorherige_operation = operation;
    }

    void set_zwischen_ergebnis(double value) {
        m_zwischen_ergebnis = value;
    }

    void clear_vorherige_operation() {
        m_vorherige_operation = operation_t::NONE;
    }

private:
    Updater* m_updater;

    QString m_input_line;

    double m_zwischen_ergebnis;
    operation_t m_vorherige_operation = operation_t::NONE;

    char vorherige_operation_drucken();
};

#endif // MODEL_H

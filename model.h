#ifndef MODEL_H
#define MODEL_H

#include <qstring.h>
#include "updater.h"

class Model {
public:
    Model(Updater* updater);

    void add_digit(const QChar digit);
    void add_comma();
    void clear_input_line();
    void toggle_sign();

    double get_eingabe_wert(bool *ok=nullptr) {
        return m_input_line.toDouble(ok);
    }

    double get_zwischen_ergebnis() {
        return m_zwischen_ergebnis;
    }

    bool get_zwischen_ergebnis_vorhanden() {
        return m_zwischen_ergebnis_vorhanden;
    }

    bool get_division_erlaubt() {
        return m_zwischen_ergebnis != 0.0;
    }

    void set_zwischen_ergebnis(double value) {
        m_zwischen_ergebnis = value;
        m_zwischen_ergebnis_vorhanden = true;
    }

private:
    Updater* m_updater;

    QString m_input_line;

    double m_zwischen_ergebnis;
    bool m_zwischen_ergebnis_vorhanden = false;
};

#endif // MODEL_H

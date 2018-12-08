#include <qtextstream.h>
#include "model.h"

Model::Model(Updater* updater) : m_updater(updater) {

}

void Model::add_digit(const QChar digit) {
    m_input_line.append(digit);

    if(!(m_input_line.indexOf(',') >= 0)) {
        m_updater->enable_comma();
    }

    m_updater->update_input_line(build_input_line());
    m_updater->enable_negativ();

    bool ok = false;
    double aktueller_wert = m_input_line.toDouble(&ok);

    if(ok && (m_vorherige_operation != operation_t::DIV || aktueller_wert != 0.0)) {
        m_updater->enable_operationen();

        if(get_vorherige_operation_vorhanden()) {
            m_updater->enable_equal();
        }
    } else {
        m_updater->disable_operationen();
        m_updater->disable_equal();
    }
}

void Model::add_comma() {
    m_input_line.append('.');

    m_updater->disable_comma();
    m_updater->update_input_line(build_input_line());
}

void Model::clear_input_line() {
    m_input_line.clear();

    m_updater->disable_comma();
    m_updater->disable_negativ();
    m_updater->disable_operationen();
    m_updater->disable_equal();

    m_updater->update_input_line(build_input_line());
}

void Model::toggle_sign() {
    if(m_input_line.length() > 0) {
        if(m_input_line.startsWith('-')) {
            m_input_line.remove(0, 1);
        } else {
            m_input_line.insert(0, '-');
        }

        m_updater->update_input_line(build_input_line());
    }
}

void Model::operation_anzeigen(const double operand, const double ergebnis) {
    QString result;
    QTextStream(&result) << m_zwischen_ergebnis << vorherige_operation_drucken() << operand << "=" << ergebnis;

    m_updater->show_expression(result);
}

char Model::vorherige_operation_drucken() {
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

QString Model::build_input_line() {
    if(get_vorherige_operation_vorhanden()) {
        QString new_input_line;

        QTextStream(&new_input_line) << get_zwischen_ergebnis() << vorherige_operation_drucken() << m_input_line;

        return new_input_line;
    } else {
        return m_input_line;
    }

}

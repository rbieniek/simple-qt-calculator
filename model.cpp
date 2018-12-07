#include "model.h"

Model::Model(Updater* updater) : m_updater(updater) {

}

void Model::add_digit(const QChar digit) {
    m_input_line.append(digit);

    if(!(m_input_line.indexOf(',') >= 0)) {
        m_updater->enable_comma();
    }

    m_updater->update_input_line(m_input_line);
    m_updater->enable_negativ();
}

void Model::add_comma() {
    m_input_line.append(',');

    m_updater->disable_comma();
    m_updater->update_input_line(m_input_line);
}

void Model::clear_input_line() {
    m_input_line.clear();

    m_updater->disable_comma();
    m_updater->disable_negativ();
    m_updater->update_input_line(m_input_line);
}

void Model::toggle_sign() {
    if(m_input_line.length() > 0) {
        if(m_input_line.startsWith('-')) {
            m_input_line.remove(0, 1);
        } else {
            m_input_line.insert(0, '-');
        }

        m_updater->update_input_line(m_input_line);
    }
}

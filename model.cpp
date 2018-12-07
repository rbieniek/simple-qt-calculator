#include "model.h"

Model::Model(Updater* updater) : m_updater(updater) {

}

void Model::add_digit(const QChar digit) {
    m_input_line.append(digit);

    if(!(m_input_line.indexOf(',') >= 0)) {
        m_updater->enable_comma();
    }

    m_updater->update_input_line(m_input_line);
}

void Model::add_comma() {
    m_input_line.append(',');

    m_updater->disable_comma();
    m_updater->update_input_line(m_input_line);
}

void Model::clear_input_line() {
    m_input_line.clear();

    m_updater->disable_comma();
    m_updater->update_input_line(m_input_line);
}

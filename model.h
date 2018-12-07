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

private:
    Updater* m_updater;

    QString m_input_line;
};

#endif // MODEL_H

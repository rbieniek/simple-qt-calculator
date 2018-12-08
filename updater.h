#ifndef UPDATER_H
#define UPDATER_H

#include <qstring.h>

class Updater {
public:
    virtual ~Updater();

    virtual void update_input_line(const QString& input_line) = 0;
    virtual void disable_comma() = 0;
    virtual void enable_comma() = 0;
    virtual void disable_negativ() = 0;
    virtual void enable_negativ() = 0;
    virtual void enable_operationen() = 0;
    virtual void disable_operationen() = 0;
    virtual void enable_equal() = 0;
    virtual void disable_equal() = 0;
    virtual void show_expression(const QString& expression) = 0;
};

#endif // UPDATER_H

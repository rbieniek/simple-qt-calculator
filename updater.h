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
};

#endif // UPDATER_H

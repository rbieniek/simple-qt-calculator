#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"

class Controller {
public:
    Controller(Model* model);

    void berechne_operation(const QChar operation);
    void berechne_sqrt();
    void berechne_power2();
    void berechne_gesamt();
private:
    Model* m_model;
};

#endif // CONTROLLER_H

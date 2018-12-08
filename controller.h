#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"
#include "operation.h"

class Controller {
public:
    Controller(Model* model);

    void operation_ausfuehren(const operation_t operation);
    void berechne_sqrt();
    void berechne_power2();
    void berechne_gesamt();
private:
    Model* m_model;

    double berechne(const double operand);
};

#endif // CONTROLLER_H

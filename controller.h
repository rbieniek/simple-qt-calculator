#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"

class Controller {
public:
    Controller(Model* model);

private:
    Model* m_model;
};

#endif // CONTROLLER_H

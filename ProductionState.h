#ifndef PRODUCTIONSTATE_H
#define PRODUCTIONSTATE_H

#include <string>

class Production;

class ProductionState {
public:
    virtual void nextState(Production* p) = 0;
    virtual std::string getState() = 0;
    virtual ~ProductionState() {}
};

#endif
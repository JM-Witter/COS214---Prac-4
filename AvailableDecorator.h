#ifndef AVAILABILITYDECORATOR_H
#define AVAILABILITYDECORATOR_H

#include "ProductionComponent.h"
#include <iostream>
#include <string>

class AvailableDecorator : public ProductionComponent {
protected:
    ProductionComponent *component;

public:
    AvailableDecorator(ProductionComponent *pc) : ProductionComponent(pc->getName())
    {
        component = pc;
    }

    double getDevelopmentCost() const override {
        return component->getDevelopmentCost();
    }

    void display(int indent) const override
    {
        component->display(indent);
    }

    std::string getProgress() const override {    // Added for iterator class
        return component->getProgress();
    }

    virtual ~AvailableDecorator()
    {
        delete component;
    }
};

#endif
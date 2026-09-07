#ifndef AVAILABILITY_DECORATOR_H
#define AVAILABILITY_DECORATOR_H

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

    void display(int indent) const override
    {
        component->display(indent);
    }

    virtual ~AvailableDecorator()
    {
        delete component;
    }
};

#endif
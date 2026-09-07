#ifndef PLATFORMDECORATOR_H
#define PLATFORMDECORATOR_H

#include "ProductionComponent.h"
#include "AvailableDecorator.h"
#include <iostream>
#include <string>

class PlatformDecorator : public AvailableDecorator {
private:
    std::string platformName;
    std::string details;
    double cost;

public:
    PlatformDecorator(ProductionComponent *pc, std::string platform, std::string details, double cost) : AvailableDecorator(pc)
    {
        this->platformName = platform;
        this->details = details;
        this->cost = cost;
    }

    void display(int indent) const override
    {
        component->display(indent);

        for (int i = 0; i < indent; i++)
        {
            std::cout << "  ";
        }
        
        std::cout << " Available on: " << platformName << " (" << details << ") - Price: R" << cost << std::endl;
    }
};

#endif
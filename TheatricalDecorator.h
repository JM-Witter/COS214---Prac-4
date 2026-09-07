#ifndef THEATRICALDECORATOR_H
#define THEATRICALDECORATOR_H

#include "ProductionComponent.h"
#include "AvailableDecorator.h"
#include <iostream>
#include <string>

class TheatricalDecorator : public AvailableDecorator {
private:
    std::string theaterName;
    std::string type;
    double ticketPrice;

public:
    TheatricalDecorator(ProductionComponent *pc, std::string theater, std::string type, double price) : AvailableDecorator(pc) {
        this->theaterName = theater;
        this->type = type;
        this->ticketPrice = price;
    }

    void display(int indent) const override
    {
        component->display(indent);

        for (int i = 0; i < indent; i++)
        {
            std::cout << "  ";
        }
        
        std::cout << "  - Showing at: " << theaterName << " [" << type << "] - Ticket Price: R" << ticketPrice << std::endl;
    }
};

#endif
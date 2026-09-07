#ifndef RELEASEDSTATE_H
#define RELEASEDSTATE_H

#include "ProductionState.h"
#include <string>
#include <iostream>

class ReleasedState : public ProductionState {
public:
    void nextState(Production* p) override {
        std::cout << "Production is already released. No state change" << std::endl;
    }
    std::string getState() override { 
		return "Released"; 
	}
};

#endif
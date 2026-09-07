#ifndef PLANNINGSTATE_H
#define PLANNINGSTATE_H

#include "ProductionState.h"
#include <string>

class PlanningState : public ProductionState {
public:
    void nextState(Production* p) override;
	
    std::string getState() override { 
		return "Planning"; 
	}
};

#endif
#ifndef EDITINGSTATE_H
#define EDITINGSTATE_H

#include "ProductionState.h"
#include <string>

class EditingState : public ProductionState {
public:
    void nextState(Production* p) override;
	
    std::string getState() override { 
		return "Editing"; 
	}
};

#endif
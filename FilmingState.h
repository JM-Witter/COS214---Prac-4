#ifndef FILMINGSTATE_H
#define FILMINGSTATE_H

#include "ProductionState.h"
#include <string>

class FilmingState : public ProductionState {
public:
    void nextState(Production* p) override;
	
    std::string getState() override {
		return "Filming"; 
	}
};

#endif
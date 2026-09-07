#include "PlanningState.h"
#include "Production.h"
#include "FilmingState.h"
#include <iostream>

void PlanningState::nextState(Production* p) {
    p->setState(new FilmingState());
	
    std::cout << "Planning complete. Starting filming." << std::endl;
}
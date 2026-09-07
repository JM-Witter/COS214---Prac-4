#include "EditingState.h"
#include "Production.h"
#include "ReleasedState.h"
#include <iostream>

void EditingState::nextState(Production* p) {
    p->setState(new ReleasedState());
	
    std::cout << "Film is finished editing. Film is now released" << std::endl;
}
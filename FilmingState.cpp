#include "FilmingState.h"
#include "Production.h"
#include "EditingState.h"
#include <iostream>

void FilmingState::nextState(Production* p) {
    p->setState(new EditingState());
	
    std::cout << "Filming complete. Film is now being edited" << std::endl;
}
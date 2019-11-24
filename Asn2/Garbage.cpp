#include "Technician.h"
#include "Garbage.h"


void Garbage::Dispose(OilFilter* OldOilFilter) {
	std::cout << "Disposing old oil filter" << std::endl;
}

void Garbage::Dispose(AirFilter* OldAirFilter) {
	std::cout << "Disposing old air filter" << std::endl;
}
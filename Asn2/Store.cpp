#include "Technician.h"
#include "Store.h"

Store::Store() {
	NewOil = new Oil;
	NewOilFilter = new OilFilter;
	NewAirFilter = new AirFilter;
	NewTires = new Tires;
}

Store::~Store() {
	delete NewOil;
	delete NewOilFilter;
	delete NewAirFilter;
	delete NewTires;
}

Oil* Store::GetOil(std::string OilType, int Quantity) {
	NewOil->OilType = OilType;
	NewOil->OilLife = 100;
	std::cout << "Recieved new oil from store" << std::endl;
	return NewOil;
}

OilFilter* Store::GetOilFilter() {
	NewOilFilter->OilFilterType = "Best oil filter";
	NewOilFilter->OilFilterStatus = true;
	std::cout << "Recieved new oil filter from store" << std::endl;
	return NewOilFilter;
}

AirFilter* Store::GetAirFilter() {
	NewAirFilter->AirFilterType = "Best air filter";
	NewAirFilter->AirFilterStatus = true;
	std::cout << "Recieved new air filter from store" << std::endl;
	return NewAirFilter;
}

Tires* Store::GetTires(std::string Make, double Size, int Quantity) {
	NewTires->TireBrand = Make;
	NewTires->TireCondition = true;
	NewTires->TireQuantity = Quantity;
	std::cout << "Recieved " << Quantity << " new tires from store" << std::endl;
	return NewTires;
}
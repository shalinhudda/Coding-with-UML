#include "Car.h"
#include "Technician.h"
#include <stdio.h>
#include <stdlib.h>

Car::Car() {
	CurrentOil = new Oil;
	CurrentOilFilter = new OilFilter;
	CurrentAirFilter = new AirFilter;
	CurrentTires = new Tires;

	CurrentOil->OilType = "Synthetic";
	CurrentOil->OilLife = 20;

	CurrentOilFilter->OilFilterType = "Best oil filter";
	CurrentOilFilter->OilFilterStatus = false;
	CurrentAirFilter->AirFilterType = "Best air filter";
	CurrentAirFilter->AirFilterStatus = false;
	CurrentTires->TireBrand = "Michellen";
	CurrentTires->TireCondition = false;
	CurrentTires->TireQuantity = 4;
}

Car::~Car() {
	delete CurrentOil;
	delete CurrentOilFilter;
	delete CurrentAirFilter;
	delete CurrentTires;
}

Oil* Car::SwapOil(Oil* NewOil) {
	Oil* OldOil = CurrentOil;
	CurrentOil = NewOil;
	return OldOil;
}

OilFilter* Car::SwapOilFilter(OilFilter* NewOilFilter) {
	OilFilter* OldOilFilter = CurrentOilFilter;
	CurrentOilFilter = NewOilFilter;
	return OldOilFilter;
}

AirFilter* Car::SwapAirFilter(AirFilter* NewAirFilter) {
	AirFilter* OldAirFilter = CurrentAirFilter;
	CurrentAirFilter = NewAirFilter;
	return OldAirFilter;
}

bool Car::CheckTiresForWear() {
	if (!CurrentTires->TireCondition) {
		// If worn then return true
		return true;
	}
	else {
		// If not worn then return false
		return false;
	}
}

Tires* Car::SwapTires(Tires* NewTires) {
	Tires* OldTires = CurrentTires;
	CurrentTires = NewTires;
	return OldTires;
}

void Car::RotateTires() {
	std::cout << "Rotating tires" << std::endl;
}
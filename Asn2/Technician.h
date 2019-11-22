#pragma once
#ifndef __Technician__
#define __Technician__

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Receptionist;
class JobSheet;
class Store;
class Car;
class Garbage;
class Recycling;

struct Tires {
	std::string TireBrand;

	// Good is TRUE, Bad is FALSE
	bool TireCondition;
	int TireQuantity;
};

struct Oil {
	std::string OilType;
	int OilLife;
};

struct OilFilter {
	std::string OilFilterType;
	// good is true and bad is false
	bool OilFilterStatus;
};

struct AirFilter {
	std::string AirFilterType;
	// good is true and bad is false
	bool AirFilterStatus;
};

class Technician {

	Store* MyStore;
	Garbage* MyGarbage;
	Recycling* MyRecycling;

public:
	Tires OldTires;
	Receptionist* MyReceptionist;
	bool CustomerTireStatus = OldTires.TireCondition;
	JobSheet* CustomerJobSheet;
	Oil NewOil;
	OilFilter NewOilFilter;
	AirFilter NewAirFilter;
	Tires NewTires;
	Oil OldOil;
	OilFilter OldOilFilter;
	AirFilter OldAirFilter;
	Car* CustomerCar;

	Technician();
	void ServiceCar(Car* CarToService);
	~Technician();

};

#endif
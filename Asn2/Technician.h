#pragma once
#ifndef __Technician__
#define __Technician__

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Receptionist;

struct Tires {
	std::string TireBrand;

	// Good is TRUE, Bad is FALSE
	bool TireCondition;
};

struct Oil {
	std::string OilType;
	int OilLife;
};

struct OilFilter {
	std::string OilFilterType;
};

struct AirFilter {
	std::string AirFilterType;
};

class Technician {
	Receptionist* MyReceptionist;
public:
	Tires OldTires;
	bool CustomerTireStatus = OldTires.TireCondition;
	JobSheet* CustomerJobSheet;
	Oil NewOil;
	OilFilter NewOilFilter;
	AirFilter NewAirFilter;
	Tires NewTires;
	Oil OldOil;
	OilFilter OldOilFilter;
	AirFilter OldAirFilter;

	void ServiceCar(Car* CarToService);

	// Extra
	void AddReceptionist(Receptionist* GivenReceptionist);
};

#endif
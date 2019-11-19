#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct Tires;
struct Oil;
struct OilFilter;
struct AirFilter;

class Store {
public:
	Oil* NewOil;
	OilFilter* NewOilFilter;
	AirFilter* NewAirFilter;
	Tires* NewTires;

	Store();
	Oil* GetOil(std::string OilType, int Quantity);
	OilFilter* GetOilFilter();
	AirFilter* GetAirFilter();
	Tires* GetTires(std::string Make, double Size, int Quantity);
	~Store();
};
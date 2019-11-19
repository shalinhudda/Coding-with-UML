#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Tires;
struct Oil;
struct OilFilter;
struct AirFilter;

class Car {
public:
	Oil* CurrentOil;
	OilFilter* CurrentOilFilter;
	AirFilter* CurrentAirFilter;
	Tires* CurrentTires;

	Car();
	Oil* SwapOil(Oil* NewOil);
	OilFilter* SwapOilFilter(OilFilter* NewOilFilter);
	AirFilter* SwapAirFilter(AirFilter* NewAirFilter);
	bool CheckTiresForWear();
	Tires* SwapTires(Tires* NewTires);
	void RotateTires();
	~Car() {};
};
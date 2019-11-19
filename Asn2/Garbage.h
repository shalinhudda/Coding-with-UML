#pragma once

struct OilFilter;
struct AirFilter;

class Garbage {
public:

	void Dispose(OilFilter* OldOilFilter);
	void Dispose(AirFilter* OldAirFilter);
	~Garbage() {};
};
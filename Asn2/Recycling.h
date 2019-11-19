#pragma once

struct Oil;
struct Tires;

class Recycling {
public:

	void Recycle(Oil* OldOil);
	void Recycle(Tires* OldTires);
	~Recycling() {};
};

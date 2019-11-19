#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "LinkedList.h"

struct Data {
	int PartNumber = 0;
	int Quantity = 0;
	double Cost = 0;
	std::string Message;
};

class JobSheet {
	LinkedList<Data> JobSheetList;

	// Extra
	double TotalCost = 0;
public:
	void AddItem(int PartNumber, int Quantity, double Cost);
	void AddLabourItem(std::string LaboutItem, double Cost);

	// Extra
	LinkedList<Data> GetJobList();
	double GetTotalCost();
};


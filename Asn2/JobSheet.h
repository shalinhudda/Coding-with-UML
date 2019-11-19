#pragma once
#ifndef __JobSheet__
#define __JobSheet__

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "LinkedList.h"

class JobSheet {
	LinkedList* JobSheetList;

	// Extra
	double TotalCost = 0;
public:
	void AddItem(int PartNumber, int Quantity, double Cost);
	void AddLabourItem(std::string LaboutItem, double Cost);

	// Extra
	LinkedList* GetJobList();
	double GetTotalCost();
};

#endif

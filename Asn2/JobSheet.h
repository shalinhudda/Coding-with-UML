#pragma once
#ifndef __JobSheet__
#define __JobSheet__

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class LinkedList;

class JobSheet {
	LinkedList* JobSheetList;

	// Extra
	double TotalCost;
public:
	void AddItem(int PartNumber, int Quantity, double Cost);
	void AddLabourItem(std::string LaboutItem, double Cost);

	JobSheet();
	// Extra
	LinkedList* GetJobList();
	double GetTotalCost();
};

#endif

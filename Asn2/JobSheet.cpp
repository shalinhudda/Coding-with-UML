#include "JobSheet.h"
#include "LinkedList.h"

#define OIL_PN 1
#define TIRE_PN 2
#define OIL_FILTER_PN 3
#define AIR_FILTER_PN 4

JobSheet::JobSheet() {
	JobSheetList = new LinkedList;
	TotalCost = 0;
}

JobSheet::~JobSheet() {
	delete JobSheetList;
}

void JobSheet::AddItem(int PartNumber, int Quantity, double Cost) {
	Data MyData;
	MyData.PartNumber = PartNumber;
	MyData.Quantity = Quantity;
	MyData.Cost = Cost;
	if (PartNumber == OIL_PN) {
		MyData.Message = "New oil cost";
	}
	else if (PartNumber == OIL_FILTER_PN) {
		MyData.Message = "New oil filter cost";
	}
	else if (PartNumber == AIR_FILTER_PN) {
		MyData.Message = "New air filter cost";
	}
	else if (PartNumber == TIRE_PN) {
		MyData.Message = "New tire cost";
	}
	TotalCost = (Cost * Quantity) + TotalCost;
	JobSheetList->Insert(MyData);
}

void JobSheet::AddLabourItem(std::string LaboutItem, double Cost) {
	Data MyData;
	MyData.PartNumber = 0;
	MyData.Quantity = 1;
	MyData.Cost = Cost;
	MyData.Message = LaboutItem;
	TotalCost = TotalCost + Cost;
	JobSheetList->Insert(MyData);
}


// Extra
LinkedList* JobSheet::GetJobList() {
	return JobSheetList;
}

// Extra
double JobSheet::GetTotalCost() {
	return TotalCost;
}
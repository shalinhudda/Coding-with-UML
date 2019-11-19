#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

struct Data {
	int PartNumber;
	int Quantity;
	float Cost;
	char Message[200];
};

class JobSheet {
	LinkedList<Data> JobSheetList;
public:
	
};

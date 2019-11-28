#include <stdio.h>
#include <stdlib.h>
#include "Customer.h"
#include "Receptionist.h"
#include "Garbage.h"
#include "Technician.h"
#include "JobSheet.h"
#include "Car.h"
#include "Recycling.h"
#include "Store.h"
#include<assert.h>

#define OIL_PN 1
#define OIL_COST 5.5
#define OIL_QUANTITY 1
#define TIRE_PN 2
#define TIRE_COST 200
#define TIRE_QUANTITY 4
#define OIL_FILTER_PN 3
#define OIL_FILTER_COST 20
#define	OIL_FILTER_QUANTITY 1
#define AIR_FILTER_PN 4
#define AIR_FILTER_COST 15
#define AIR_FILTER_QUANTITY 1

#define LABOUR_COST_OIL_CHANGE 5
#define LABOUR_COST_OIL_FILTER_CHANGE 10
#define LABOUR_COST_AIR_FILTER_CHANGE 8
#define LABOUR_COST_TIRE_CHANGE 50
#define LABOUT_COST_TIRE_ROTATION 30

Technician::Technician() {
	CustomerJobSheet = new JobSheet();
	MyStore = new Store();
	MyGarbage = new Garbage;
	MyRecycling = new Recycling;
}

Technician::~Technician() {
	delete CustomerJobSheet;
	delete MyStore;
	delete MyGarbage;
	delete MyRecycling;
}

void Technician::ServiceCar(Car* CarToService) {
	if (CarToService != NULL) {
		CustomerCar = CarToService;
		cout << "Technician has the customer's car for servicing" << endl;

		cout << endl;
		cout << "Printing car status before starting to service the car" << endl;
		cout << "******************************************************************************************************" << endl;
		cout << "Current Oil type is: " << CustomerCar->CurrentOil->OilType << " and the oil life is: " << CustomerCar->CurrentOil->OilLife << endl;
		cout << "Current Oil filter brand is: " << CustomerCar->CurrentOilFilter->OilFilterType << "and the oil filter status is: " << CustomerCar->CurrentOilFilter->OilFilterStatus << endl;
		cout << "Current Air filter brand is: " << CustomerCar->CurrentAirFilter->AirFilterType << "and the air filter status is: " << CustomerCar->CurrentAirFilter->AirFilterStatus << endl;
		cout << "Current tire brand is: " << CustomerCar->CurrentTires->TireBrand << ", tire condition is: " << CustomerCar->CurrentTires->TireCondition << " and tire quantity is: " << CustomerCar->CurrentTires->TireQuantity << endl;
		cout << "******************************************************************************************************" << endl;
		cout << endl;

		NewOil = *MyStore->GetOil("Non-Synthetic", OIL_QUANTITY);
		assert(NewOil.OilType == "Non-Synthetic");
		assert(NewOil.OilLife == 100);
		CustomerJobSheet->AddItem(OIL_PN, OIL_QUANTITY, OIL_COST);
		NewAirFilter = *MyStore->GetAirFilter();
		assert(NewAirFilter.AirFilterStatus == true);
		assert(NewAirFilter.AirFilterType=="Best air filter");
		CustomerJobSheet->AddItem(AIR_FILTER_PN, AIR_FILTER_QUANTITY, AIR_FILTER_COST);
		NewOilFilter = *MyStore->GetOilFilter();
		assert(NewOilFilter.OilFilterType == "Best oil filter");
		assert(NewOilFilter.OilFilterStatus == true);
		CustomerJobSheet->AddItem(OIL_FILTER_PN, OIL_FILTER_QUANTITY, OIL_FILTER_COST);

		OldOil = *CustomerCar->SwapOil(&NewOil);
		assert(CustomerCar->CurrentOil->OilType == "Non-Synthetic");
		assert(CustomerCar->CurrentOil->OilLife == 100);
		MyRecycling->Recycle(&OldOil);
		CustomerJobSheet->AddLabourItem("Oil change labour", LABOUR_COST_OIL_CHANGE);

		OldOilFilter = *CustomerCar->SwapOilFilter(&NewOilFilter);
		
		MyGarbage->Dispose(&OldOilFilter);
		CustomerJobSheet->AddLabourItem("Oil filter change labour", LABOUR_COST_OIL_FILTER_CHANGE);

		OldAirFilter = *CustomerCar->SwapAirFilter(&NewAirFilter);
		MyGarbage->Dispose(&OldAirFilter);
		CustomerJobSheet->AddLabourItem("Air filter change labour", LABOUR_COST_AIR_FILTER_CHANGE);

		if (CustomerCar->CheckTiresForWear()) {
			NewTires = *MyStore->GetTires("Good Year", 18, 4);
			CustomerJobSheet->AddItem(TIRE_PN, TIRE_QUANTITY, TIRE_COST);
			OldTires = *CustomerCar->SwapTires(&NewTires);
			//assert(CustomerCar->CheckTiresForWear = true);
			MyRecycling->Recycle(&OldTires);
			CustomerJobSheet->AddLabourItem("Tire change labour", LABOUR_COST_TIRE_CHANGE);
		}
		else {
			CustomerCar->RotateTires();
			CustomerJobSheet->AddLabourItem("Tire rotation labour", LABOUT_COST_TIRE_ROTATION);
		}

		cout << endl;
		cout << "Printing car status after the car has been serviced" << endl;
		cout << "******************************************************************************************************" << endl;
		cout << "Current Oil type is: " << CustomerCar->CurrentOil->OilType << " and the oil life is: " << CustomerCar->CurrentOil->OilLife << endl;
		cout << "Current Oil filter brand is: " << CustomerCar->CurrentOilFilter->OilFilterType << "and the oil filter status is: " << CustomerCar->CurrentOilFilter->OilFilterStatus << endl;
		cout << "Current Air filter brand is: " << CustomerCar->CurrentAirFilter->AirFilterType << "and the air filter status is: " << CustomerCar->CurrentAirFilter->AirFilterStatus << endl;
		cout << "Current tire brand is: " << CustomerCar->CurrentTires->TireBrand << ", tire condition is: " << CustomerCar->CurrentTires->TireCondition << " and tire quantity is: " << CustomerCar->CurrentTires->TireQuantity << endl;
		cout << "******************************************************************************************************" << endl;
		cout << endl;
	}
}

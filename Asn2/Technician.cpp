#include <stdio.h>
#include <stdlib.h>
#include "Customer.h"
#include "Receptionist.h"
#include "Technician.h"
#include "JobSheet.h"
#include "Car.h"
#include "Store.h"

Technician::Technician() {
	CustomerJobSheet = new JobSheet();
	MyStore = new Store();
}

void Technician::ServiceCar(Car* CarToService) {
	CustomerCar = CarToService;
	cout <<  "Technician has the customer's car for servicing" << endl;
	cout << "Printing car status before starting to service the car" << endl;
	cout << "Current Oil type is: " << CustomerCar->CurrentOil->OilType << " and the oil life is: " << CustomerCar->CurrentOil->OilLife << endl;
	cout << "Current Oil filter brand is: " << CustomerCar->CurrentOilFilter->OilFilterType << "and the oil filter status is: " << CustomerCar->CurrentOilFilter->OilFilterStatus << endl;
	cout << "Current Air filter brand is: " << CustomerCar->CurrentAirFilter->AirFilterType << "and the air filter status is: " << CustomerCar->CurrentAirFilter->AirFilterStatus << endl;
	cout << "Current tire brand is: " << CustomerCar->CurrentTires->TireBrand << ", tire condition is: " << CustomerCar->CurrentTires->TireCondition << " and tire quantity is: " << CustomerCar->CurrentTires->TireQuantity << endl;

	NewOil = *MyStore->GetOil("Non-Synthetic", 1);
	NewOilFilter = *MyStore->GetOilFilter();
	NewAirFilter = *MyStore->GetAirFilter();

	if (CustomerCar->CheckTiresForWear()) {
		NewTires = *MyStore->GetTires("Good Year", 18, 4);
	}
	else {
		CustomerCar->RotateTires();
	}


}

// Extra
void Technician::AddReceptionist(Receptionist* GivenReceptionist) {
	MyReceptionist = GivenReceptionist;
}
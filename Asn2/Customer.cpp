#include <stdio.h>
#include <stdlib.h>
#include "Customer.h"
#include "Receptionist.h"
#include "Technician.h"
#include "JobSheet.h"
#include "Car.h"
#include <assert.h>

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


Customer::Customer() {
	MyNewServiceRecord;
	MyJobSheet = NULL;
	MyReceptionist = NULL;

	MyCar = new Car;
	MyOldServiceRecord = new ServiceRecord;
	Data Oil, OilFilter, AirFilter, Tires;
	
	// Adding old car properties
	Oil.PartNumber = OIL_PN;
	Oil.Cost = OIL_COST * OIL_QUANTITY;
	Oil.Quantity = OIL_QUANTITY;
	Oil.Message = "Oil";

	OilFilter.PartNumber = OIL_FILTER_PN;
	OilFilter.Cost = OIL_FILTER_COST * OIL_FILTER_QUANTITY;
	OilFilter.Quantity = OIL_FILTER_QUANTITY;
	OilFilter.Message = "Oil Filter";

	AirFilter.PartNumber = AIR_FILTER_PN;
	AirFilter.Cost = AIR_FILTER_COST * AIR_FILTER_QUANTITY;
	AirFilter.Quantity = AIR_FILTER_QUANTITY;
	AirFilter.Message = "Air Filter";

	Tires.PartNumber = TIRE_PN;
	Tires.Cost = TIRE_COST * TIRE_QUANTITY;
	Tires.Quantity = TIRE_QUANTITY;
	Tires.Message = "Tires";
	// End

	MyOldServiceRecord->JobSheetLL->Insert(Oil);
	MyOldServiceRecord->JobSheetLL->Insert(OilFilter);
	MyOldServiceRecord->JobSheetLL->Insert(AirFilter);
	MyOldServiceRecord->JobSheetLL->Insert(Tires);
	MyOldServiceRecord->Date = "11//11//19";
	MyOldServiceRecord->Stamped = true;

}

Customer::~Customer() {
	delete MyCar;
	delete MyOldServiceRecord;
}

void Customer::ComeBackLater() {
	if (MyReceptionist != NULL) {
		std::cout << "Customer going away, will come back later to pick up the car" << std::endl;
	}
}

void Customer::PrintInvoice() {
	if (MyReceptionist != NULL) {
		std::cout << "Total cost that customer needs to pay is " << MyReceptionist->JobSheetFromTech->GetTotalCost() << endl;

	}
}

void Customer::SetJobSheet() {
	if(MyReceptionist != NULL) {
		MyJobSheet = MyReceptionist->JobSheetFromTech->GetJobList();
		cout << "Job sheet recieved from the receptionist" << endl;
	}
}

void Customer::SetNewServiceRecord() {
	if (MyReceptionist != NULL) {
		MyNewServiceRecord = MyReceptionist->CustomerNewServiceRecord;
		cout << "New service record recieved from the receptionist" << endl;
	}
}

void Customer::GiveCarBack() {
	if (MyReceptionist != NULL) {
		MyCar = MyReceptionist->CustomerCar;
		cout << "Recieved serviced car back from the receptionist" << endl;
	}
}

void Customer::AddReceptionist(Receptionist* GivenReceptionist) {
	MyReceptionist = GivenReceptionist;
	MyReceptionist->MyCustomer = this;
}

int main() {

	Customer* TheCustomer = new Customer();
	
	Car* RandomCar = TheCustomer->MyCar;
	RandomCar->CurrentTires->TireCondition = true;
	TheCustomer->MyCar = RandomCar;


	Receptionist* TheReceptionist = new Receptionist();
	Technician* TheTechnician = new Technician;

	// Enabling objects to be able identify each other
	TheCustomer->AddReceptionist(TheReceptionist);
	TheReceptionist->AddTechnician(TheTechnician);

	TheReceptionist->GetOldServiceRecord();
	TheReceptionist->GetCarFromCustomer();

	TheTechnician->ServiceCar(TheReceptionist->CustomerCar);
	
	TheReceptionist->GetCarFromTech();
	TheReceptionist->GetJobSheetFromTech();
	TheReceptionist->GenerateInvoice();
	TheReceptionist->StampServiceRecord();

	TheCustomer->PrintInvoice();
	TheCustomer->SetJobSheet();

	cout << endl;
	cout << "Printing car job sheet after the car has been serviced" << endl;
	cout << "******************************************************************************************************" << endl;
	TheCustomer->MyJobSheet->Print();
	cout<< "Total Cost: " << TheReceptionist->JobSheetFromTech->GetTotalCost() << endl;
	cout << "******************************************************************************************************" << endl;
	cout << endl;

	TheCustomer->SetNewServiceRecord();
	assert(TheReceptionist->RequiredCustomerPayment == 93.5);
	TheReceptionist->GetPayment();
	TheCustomer->GiveCarBack();


}
#include <stdio.h>
#include <stdlib.h>
#include "Customer.h"
#include "Receptionist.h"
#include "Technician.h"
#include "JobSheet.h"
#include "Car.h"

Customer::Customer() {
	MyNewServiceRecord = NULL;
	MyJobSheet = NULL;
	MyReceptionist = NULL;

	// Setup MyCar here
	MyOldServiceRecord->JobSheetLL = NULL;
	MyOldServiceRecord->Date = "11//11//19";
	MyOldServiceRecord->Stamped = true;

}

void Customer::ComeBackLater() {
	std::cout << "Customer going away, will come back later to pick up the car" << std::endl;
}

void Customer::PrintInvoice() {
	std::cout << MyReceptionist->JobSheetFromTech->GetTotalCost() << endl;
}

void Customer::SetJobSheet() {
	MyJobSheet = MyReceptionist->JobSheetFromTech->GetJobList();
}

void Customer::SetNewServiceRecord() {
	MyNewServiceRecord = MyReceptionist->CustomerNewServiceRecord;
}

void Customer::GiveCarBack() {
	MyCar = MyReceptionist->CustomerCar;
}

//Extra
void Customer::AddReceptionist(Receptionist* GivenReceptionist) {
	MyReceptionist = GivenReceptionist;
}

int main() {

	Customer* TheCustomer = new Customer;
	Receptionist* TheReceptionist = new Receptionist;
	Technician* TheTechnician = new Technician;

	// Enabling objects to be able identify each other
	TheCustomer->AddReceptionist(TheReceptionist);
	TheReceptionist->AddCustomer(TheCustomer);
	TheReceptionist->AddTechnician(TheTechnician);
	TheTechnician->AddReceptionist(TheReceptionist);

}
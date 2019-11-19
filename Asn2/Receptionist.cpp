#include <stdio.h>
#include <stdlib.h>
#include "Customer.h"
#include "Receptionist.h"
#include "Technician.h"
#include "JobSheet.h"
#include "Car.h"


Receptionist::Receptionist() {
	CustomerCar = NULL;
	CustomerOldServiceRecord;
	CustomerNewServiceRecord = new ServiceRecord;
	JobSheetFromTech = NULL;
	RequiredCustomerPayment = 0;
}

void Receptionist::GetCarFromCustomer() {
	CustomerCar = MyCustomer->MyCar;
	cout << "Car recieved from customer" << endl;
}

void Receptionist::GetPayment() {
	cout << "Payment from customer recieved" << endl;
}

void Receptionist::GetOldServiceRecord() {
	
	CustomerOldServiceRecord = MyCustomer->MyOldServiceRecord;
	if (CustomerOldServiceRecord->Stamped == true) {
		cout << "Customer's old service record is valid" << endl;
	}
	else {
		cout << "Customer's old service record is not valid" << endl;
	}

	CustomerOldServiceRecord->JobSheetLL->Print();

}

void Receptionist::MakeCoffee() {
	cout << "Receptionist is making coffee" << endl;
}

void Receptionist::GetCarFromTech() {
	CustomerCar = MyTechnician->CustomerCar;
	cout << "Car recieved back from technician" << endl;
}

void Receptionist::GetJobSheetFromTech() {
	JobSheetFromTech = MyTechnician->CustomerJobSheet;
	cout << "New job sheet recieved from technician" << endl;
}

void Receptionist::GenerateInvoice() {
	RequiredCustomerPayment = JobSheetFromTech->GetTotalCost();
	cout << "Total payment required by the customer is " << RequiredCustomerPayment << endl;
}

void Receptionist::StampServiceRecord() {
	CustomerNewServiceRecord->JobSheetLL = JobSheetFromTech->GetJobList();
	CustomerNewServiceRecord->Date = "11/12/20";
	CustomerNewServiceRecord->Stamped = true;
	cout << "New service record created for the customer" << endl;
}

// Extra
void Receptionist::AddCustomer(Customer* GivenCustomer) {
	MyCustomer = GivenCustomer;
}

// Extra
void Receptionist::AddTechnician(Technician* GivenTechnician) {
	MyTechnician = GivenTechnician;
}

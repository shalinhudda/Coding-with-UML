#include <stdio.h>
#include <stdlib.h>
#include "Customer.h"
#include "Receptionist.h"
#include "Technician.h"
#include "JobSheet.h"
#include "Car.h"
#include <assert.h>


Receptionist::Receptionist() {
	CustomerCar = NULL;
	CustomerOldServiceRecord;
	CustomerNewServiceRecord = new ServiceRecord;
	JobSheetFromTech = NULL;
	RequiredCustomerPayment = 0;
}

Receptionist::~Receptionist() {
	delete CustomerNewServiceRecord;
}

void Receptionist::GetCarFromCustomer() {
	if (MyCustomer != NULL) {
		CustomerCar = MyCustomer->MyCar;
		cout << "Car recieved from customer" << endl;
	}
}

void Receptionist::GetPayment() {
	if (MyCustomer != NULL) {
		cout << "Payment from customer recieved" << endl;
	}
}

void Receptionist::GetOldServiceRecord() {
	if (MyCustomer != NULL) {
		CustomerOldServiceRecord = MyCustomer->MyOldServiceRecord;
		if (CustomerOldServiceRecord->Stamped == true) {
			cout << "Customer's old service record is valid" << endl;
		}
		else {
			cout << "Customer's old service record is not valid" << endl;
		}

		CustomerOldServiceRecord->JobSheetLL->Print();
	}
}

void Receptionist::MakeCoffee() {
	if (MyCustomer != NULL) {
		cout << "Receptionist is making coffee" << endl;
	}
}

void Receptionist::GetCarFromTech() {
	if (MyTechnician != NULL) {
		CustomerCar = MyTechnician->CustomerCar;
		cout << "Car recieved back from technician" << endl;
	}
}

void Receptionist::GetJobSheetFromTech() 
{
	if (MyTechnician != NULL) {
		JobSheetFromTech = MyTechnician->CustomerJobSheet;
		cout << "New job sheet recieved from technician" << endl;
	}
}

void Receptionist::GenerateInvoice() {
	if (JobSheetFromTech != NULL) {
		RequiredCustomerPayment = JobSheetFromTech->GetTotalCost();
		assert(RequiredCustomerPayment == 913.5);
		cout << "Total payment required by the customer is " << RequiredCustomerPayment << endl;
	}
}

void Receptionist::StampServiceRecord() {
	if (JobSheetFromTech != NULL) {
		CustomerNewServiceRecord->JobSheetLL = JobSheetFromTech->GetJobList();
		CustomerNewServiceRecord->Date = "11/12/20";
		CustomerNewServiceRecord->Stamped = true;
		cout << "New service record created for the customer" << endl;
	}
}

void Receptionist::AddTechnician(Technician* GivenTechnician) {
	MyTechnician = GivenTechnician;
	MyTechnician->MyReceptionist = this;
}

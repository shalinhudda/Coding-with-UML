#include <stdio.h>
#include <stdlib.h>
#include "Customer.h"
#include "Receptionist.h"
#include "Technician.h"
#include "JobSheet.h"
#include "Car.h"

void Receptionist::GetCarFromCustomer() {

}

void Receptionist::GetPayment() {

}

void Receptionist::GetOldServiceRecord() {

}

void Receptionist::MakeCoffee() {

}

void Receptionist::GetCarFromTech() {

}

void Receptionist::GetJobSheetFromTech() {

}

void Receptionist::GenerateInvoice() {

}

void Receptionist::StampServiceRecord() {

}

// Extra
void Receptionist::AddCustomer(Customer* GivenCustomer) {
	MyCustomer = GivenCustomer;
}

// Extra
void Receptionist::AddTechnician(Technician* GivenTechnician) {
	MyTechnician = GivenTechnician;
}

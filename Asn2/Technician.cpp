#include <stdio.h>
#include <stdlib.h>
#include "Customer.h"
#include "Receptionist.h"
#include "Technician.h"
#include "JobSheet.h"
#include "Car.h"

Technician::Technician() {

}

void Technician::ServiceCar(Car* CarToService) {
	cout <<  "Technician has the customer's car for servicing" << endl;
}

// Extra
void Technician::AddReceptionist(Receptionist* GivenReceptionist) {
	MyReceptionist = GivenReceptionist;
}
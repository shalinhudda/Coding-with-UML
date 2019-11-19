#include <stdio.h>
#include <stdlib.h>
#include "Customer.h"
#include "Receptionist.h"
#include "Technician.h"
#include "JobSheet.h"
#include "Car.h"

void Technician::ServiceCar(Car* CarToService) {

}

// Extra
void Technician::AddReceptionist(Receptionist* GivenReceptionist) {
	MyReceptionist = GivenReceptionist;
}
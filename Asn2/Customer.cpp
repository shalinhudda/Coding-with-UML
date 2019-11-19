#include <stdio.h>
#include <stdlib.h>
#include "Customer.h"
#include "Receptionist.h"

int main() {


	Customer* TheCustomer = new Customer;
	Receptionist* TheReceptionist = new Receptionist;

	TheCustomer->AddReceptionist(TheReceptionist);
	TheReceptionist->AddCustomer(TheCustomer);


}
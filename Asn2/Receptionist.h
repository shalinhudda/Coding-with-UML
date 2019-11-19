#pragma once
#ifndef __Receptionist__
#define __Receptionist__

class Customer;
class Receptionist {
	Customer* MyCustomer;

public:
	void AddCustomer(Customer* GivenCustomer);

	~Receptionist() {};
};

void Receptionist::AddCustomer(Customer* GivenCustomer) {
	MyCustomer = GivenCustomer;
}

#endif
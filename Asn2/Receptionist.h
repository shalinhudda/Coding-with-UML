#pragma once
#ifndef __Receptionist__
#define __Receptionist__

class Customer;
class Technician;
class JobSheet;
class Car;
class LinkedList;

struct ServiceRecord {
	LinkedList* JobSheetLL;
	std::string Date;
	bool Stamped;
};

class Receptionist {
	Customer* MyCustomer;
	Technician* MyTechnician;
public:
	Car* CustomerCar;
	double CustomerPayment = 0;
	ServiceRecord* CustomerOldServiceRecord;
	ServiceRecord* CustomerNewServiceRecord;
	JobSheet* JobSheetFromTech;

	void GetCarFromCustomer();
	void GetPayment();
	void GetOldServiceRecord();
	void MakeCoffee();
	void GetCarFromTech();
	void GetJobSheetFromTech();
	void GenerateInvoice();
	void StampServiceRecord();
	
	// Extra
	void AddCustomer(Customer* GivenCustomer);
	void AddTechnician(Technician* GivenTechnician);
	
	~Receptionist() {};
};



#endif
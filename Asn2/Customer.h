#pragma once
#ifndef __Customer__
#define __Customer__

#include <stdio.h>
#include <stdlib.h>
#include "JobSheet.h"
#include "Car.h"
#include "Receptionist.h"
#include "LinkedList.h"

struct ServiceRecord {
	LinkedList<Data> JobSheetLL;
	std::string Date = "11/11/19";
	bool Stamped = true;
};

class Customer {
public:
	ServiceRecord MyOldServiceRecord;
	ServiceRecord MyNewServiceRecord;
	LinkedList<Data> MyJobSheet;
	Receptionist* MyReceptionist;
	Car MyCar;

	void ComeBackLater();
	void PrintInvoice();
	void SetJobSheet();
	void SetNewServiceRecord();
	void GiveCarBack();
	~Customer() {};

	//Extra
	void AddReceptionist(Receptionist* GivenReceptionist);
};

void Customer::ComeBackLater() {
	std::cout << "Customer going away, will come back later to pick up the car" << std::endl;
}

void Customer::PrintInvoice() {

}

void Customer::SetJobSheet() {

}

void Customer::SetNewServiceRecord() {

}

void Customer::GiveCarBack() {

}

//Extra
void Customer::AddReceptionist(Receptionist* GivenReceptionist) {
	MyReceptionist = GivenReceptionist;
}
#endif
#pragma once
#ifndef __Customer__
#define __Customer__

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct ServiceRecord;
class Receptionist;
class Car;
class LinkedList;

class Customer {
public:
	ServiceRecord* MyOldServiceRecord;
	ServiceRecord* MyNewServiceRecord;
	LinkedList* MyJobSheet;
	Receptionist* MyReceptionist;
	Car* MyCar;


	Customer();
	void ComeBackLater();
	void PrintInvoice();
	void SetJobSheet();
	void SetNewServiceRecord();
	void GiveCarBack();
	~Customer();

	//Extra
	void AddReceptionist(Receptionist* GivenReceptionist);
};

#endif
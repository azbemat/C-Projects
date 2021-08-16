/* ------------------------------------------------------
Final Project Milestone 6
Module: Car
Filename : Car.h
Version 0.9
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date :				Reason :
2020 / 3 / 27		Preliminary release
2020 / 4 / 06		Updated
-----------------------------------------------------------
Name: Anas Bemat
ID: 165239187
mail: azbemat@myseneca.ca
------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__

#include <iostream>
#include"Vehicle.h"

using namespace std;

namespace sdds {

	class Car : public Vehicle {
		bool isCarWash;

	public:
		Car();
		Car(bool, const char[], const char*);

		Car(const Car& ) = delete;
		Car& operator=(const Car&) = delete;

		std::istream& read(std::istream&);
		std::ostream& write(std::ostream&) const;
	};
}
#endif
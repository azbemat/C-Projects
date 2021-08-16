/* ------------------------------------------------------
Final Project Milestone 6
Module: Motorcycle
Filename : Motorcycle.h
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

#ifndef SDDS_MOTORCYCLE_H__
#define SDDS_MOTORCYCLE_H__

#include <iostream>
#include"Vehicle.h"

using namespace std;

namespace sdds {

	class Motorcycle : public Vehicle {
		bool hasSideCar;

	public:
		Motorcycle();
		Motorcycle(bool, const char[], const char*);

		Motorcycle(const Motorcycle&) = delete;
		Motorcycle& operator=(const Motorcycle&) = delete;

		std::istream& read(std:: istream&);
		ostream& write(std::ostream&) const;

	};
}
#endif
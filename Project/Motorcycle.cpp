/* ------------------------------------------------------
Final Project Milestone 6
Module: Motorcycle
Filename : Motorcycle.cpp
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

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <iomanip>
#include <cstring>

#include"Motorcycle.h"

using namespace std;

namespace sdds {

	Motorcycle::Motorcycle() {
		hasSideCar = false;
	}

	Motorcycle::Motorcycle(bool side, const char licplate[] , const char* model) : Vehicle(licplate, model) {
		hasSideCar = (Vehicle::isEmpty()) ? false : side;
	}

	std::istream& Motorcycle::read(std::istream& in) {

		if (Vehicle::isCsv()) {
			Vehicle::read(in);
			in >> hasSideCar;
			in.ignore(2000, '\n');
		}
		else {
			char input, NL;
			bool result = false;
			cout << endl;
			cout << "Motorcycle information entry" << endl;
			Vehicle::read(in);
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";

			do {
				cin >> input;
				NL = in.get();

				if (NL != '\n')
					in.ignore(2000, '\n');
				if ((toupper(input) != 'Y' && toupper(input) != 'N') || NL != '\n')
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				else
					result = true;
			} while (!result);
			hasSideCar = toupper(input) == 'Y';
		}
		return in;

	}

	ostream& Motorcycle::write(std::ostream& os) const {
		if (Vehicle::isEmpty())
			os << "Invalid Motorcycle Object" << endl;
		else {
			
			if (Vehicle::isCsv())
				os << "M,";
			else
				os << "Vehicle type: Motorcycle" << endl;

			Vehicle::write(os);
			if (Vehicle::isCsv())
				os << hasSideCar << endl;
			else if(hasSideCar == true)
				os << "With Sidecar" << endl;
		}
		return os;
	}

}
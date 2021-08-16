/* ------------------------------------------------------
Final Project Milestone 6
Module: Car
Filename : Car.cpp
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

#include "Car.h"

using namespace std;

namespace sdds {

	Car::Car() {
		isCarWash = false;
	}

	Car::Car(bool wash, const char licplate[], const char* model) : Vehicle(licplate, model) {
		isCarWash = (Vehicle::isEmpty()) ? false : wash;
	}

	istream& Car::read(istream& in) {

		if (Vehicle::isCsv()) {
			Vehicle::read(in);
			in >> isCarWash;
			in.ignore(2000, '\n');
		}
		else {
			char input, NL;
			bool result = false;
			cout << endl;
			cout << "Car information entry" << endl;
			Vehicle::read(in);
			cout << "Carwash while parked? (Y)es/(N)o: ";

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
			isCarWash = toupper(input) == 'Y';
		}
		return in;
	}

	std::ostream& Car::write(std::ostream& os) const {
		if (Vehicle::isEmpty())
			os << "Invalid Car Object" << endl;
		else {
			
			if (Vehicle::isCsv())
				os << "C,";
			else
				os << "Vehicle type: Car" << endl;

			Vehicle::write(os);
			if (Vehicle::isCsv())
				os << isCarWash << endl;
			else
				os << ((isCarWash == true) ? "With Carwash" : "Without Carwash") << endl;
		}
		return os;
	}
}
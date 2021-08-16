/* ------------------------------------------------------
Final Project Milestone 6
Module: Vehicle
Filename: Vehicles.cpp
Version 1.0
Revision History
-----------------------------------------------------------
Date		Reason
2020/3/25	Preliminary release
2020/3/31	Updated
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

#include "Vehicle.h"

using namespace std;

namespace sdds {

	Vehicle::Vehicle() {
		makeAndModel = nullptr;
		lincensePlate[0] = '\0';

		delete[] makeAndModel;
		makeAndModel = nullptr;
		spotNo = 0;
	}

	void Vehicle::setEmpty() {
		lincensePlate[0] = '\0';
		delete[] makeAndModel;
		makeAndModel = nullptr;
		spotNo = -10;
	}

	Vehicle::Vehicle(const char licplate[], const char* model, int Spot) {
		if (licplate != nullptr && licplate[0] != '\0' && strlen(licplate) <= MAX_CHAR_IN_LICENSE_PLATE && model != nullptr && strlen(model) >= 2 && Spot >= 0) {

			strncpy(lincensePlate, licplate, MAX_CHAR_IN_LICENSE_PLATE);
			makeAndModel = new char[strlen(model) + 1];
			strcpy(makeAndModel, model);
			spotNo = Spot;
		}
		else			
			setEmpty();
	}

	Vehicle::~Vehicle() {
		delete[] makeAndModel;
		makeAndModel = nullptr;
	}

	int Vehicle::getParkingSpot() {
		return spotNo;
	}

	void Vehicle::setParkingSpot(int value) {
		if (value < 0)
			setEmpty();
		else
			spotNo = value;
	}

	bool Vehicle::operator==(const Vehicle& vehicle) const {
		return (strcmp(lincensePlate, vehicle.lincensePlate) == 0);
	}

	bool Vehicle::operator==(const char* plate) const {
		return (strcmp(lincensePlate, plate) == 0);
	}

	void Vehicle::toUpperCase(char* value) {
		for (int i = 0; value[i] != '\0'; i++)
			value[i] = toupper(value[i]);
	}

	bool Vehicle::isEmpty() const {
		return spotNo < 0;
	}

	const char* Vehicle::getLicensePlate() const {
		return lincensePlate;
	}

	const char* Vehicle::getMakeModel() const {
		return makeAndModel;
	}

	void Vehicle::setMakeModel(const char* model) {
		if (model != nullptr || strlen(model) > 2) {
			delete[] makeAndModel;
			makeAndModel = new char[strlen(model) + 1];
			strcpy(makeAndModel, model);
		}
		else
			setEmpty();
	}

	istream& Vehicle::read(istream& in) {
	
		if (!isCsv()) {
			bool result = false;

			cout << "Enter Licence Plate Number: ";
			do {
				in.get(lincensePlate, 9, '\n');
				if (in.get() != '\n') {
					cout << "Invalid Licence Plate, try again: ";
					in.clear();
					in.ignore(2000, '\n');
				}
				else
					result = true;
			} while (!result);

			char temp[61];
			result = false;

			cout << "Enter Make and Model: ";
			do {
				in.get(temp, 60, '\n');
				if (in.get() != '\n') {
					cout << "Invalid Make and model, try again: ";
					in.ignore(2000, '\n');
				}
				else if (strlen(temp) < 2)
					cout << "Invalid Make and model, try again: ";
				else
					result = true;
			} while (!result);

			delete[] makeAndModel;

			makeAndModel = new char[strlen(temp) + 1];
			strcpy(makeAndModel, temp);
			spotNo = 0;
		}
		else {

			in >> spotNo;
			in.ignore();
			in.get(lincensePlate, 9, ',');
			in.ignore();

			char temp[61];
			in.get(temp, 60, ',');

			delete[]makeAndModel;
			makeAndModel = new char[strlen(temp) + 1];
			strcpy(makeAndModel, temp);

			in.ignore();
		}
		toUpperCase(lincensePlate);

		if (in.fail())
			setEmpty();
		return in;
	}
	
	std::ostream& Vehicle::write(std::ostream& os) const {
		if (isEmpty())
			os << "Invalid Vehicle Object" << endl;
		else {
			if (isCsv())
				os << spotNo << "," << lincensePlate << "," << makeAndModel << ",";
			else {
				os << "Parking Spot Number: ";
				if (spotNo == 0)
					os << "N/A" << endl;
				else
					os << spotNo << endl;

				os << "Licence Plate: " << lincensePlate << endl;
				os << "Make and Model: " << makeAndModel << endl;
			}
		}
		return os;
	}
}
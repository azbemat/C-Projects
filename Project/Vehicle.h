/* ------------------------------------------------------
Final Project Milestone 5
Module: Vehicle
Filename: Vehicles.h
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

#ifndef SDDS_VEHICLE_H__
#define SDDS_VEHICLE_H__

#include <iostream>

#include"ReadWritable.h"

using namespace std;

namespace sdds {

	const int MAX_CHAR_IN_LICENSE_PLATE = 8;

	class Vehicle : public ReadWritable {

		char lincensePlate[MAX_CHAR_IN_LICENSE_PLATE + 1];
		char* makeAndModel;
		int spotNo;

	protected:
		void setEmpty();
		bool isEmpty() const;
		const char* getLicensePlate() const;
		const char* getMakeModel() const;
		void setMakeModel(const char*);

	public:
		Vehicle();
		Vehicle(const char[], const char*, int Spot = 0);
		~Vehicle();

		Vehicle(const Vehicle&) = delete;
		Vehicle& operator=(const Vehicle&) = delete;

		int getParkingSpot();
		void setParkingSpot(int);
		void toUpperCase(char*);

		bool operator==(const Vehicle&) const;
		bool operator==(const char*) const;

		istream& read(std::istream& in = cin);
		ostream& write(std::ostream& os = cout) const;
	
	};
}
#endif
/* ------------------------------------------------------
Final Project Milestone 6
Module: Parking
Filename: Parking.h
Version 1.0
Revision History
-----------------------------------------------------------
Date		Reason
2020/3/2	Preliminary release
2020/3/25	Updated
2020/4/15	Updated
-----------------------------------------------------------
Name: Anas Bemat
ID: 165239187
Mail: azbemat@myseneca.ca
------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_PARKING_H_
#define SDDS_PARKING_H_

#include <iostream>

#include "Menu.h"
#include "Car.h"
#include "Motorcycle.h"

using namespace std;

namespace sdds {

	const int MAX_NO_OF_PARKING_SPOT = 100;

	class Parking {
		char* m_name;
		Menu parkingMenu;
		Menu vehicleMenu;
		int noOfSpots;
		Vehicle* parkingSpots[MAX_NO_OF_PARKING_SPOT];
		int countVehicle;

		bool isEmpty() const;
		void setEmpty();
		void parkingStatus() const;
		void parkVehicle();
		void returnVehicle();
		void listParkVehicle() const;
		bool closeParking();
		bool exitParkingApp() const;
		bool loadDataFile();
		void saveData() const;

	public:
		Parking();
		Parking(const char*, int);
		~Parking();
		int run();

		Parking(const Parking& src) = delete;
		Parking& operator=(const Parking& src) = delete;

	};
}

#endif
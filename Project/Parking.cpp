/* ------------------------------------------------------
Final Project Milestone 2
Module: Parking
Filename: Parking.cpp
Version 1.0
Revision History
-----------------------------------------------------------
Date		Reason
2020/3/2	Preliminary release
2020/3/25	Updated
-----------------------------------------------------------
Name: Anas Bemat
ID: 165239187
Mail: azbemat@myseneca.ca
------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#include "Vehicle.h"
#include "Menu.h"
#include "Parking.h"
#include "Motorcycle.h"

using namespace std;

namespace sdds {

	Parking::Parking() {
		m_name = nullptr;
		noOfSpots = 0;
		countVehicle = 0;
		for (int i = 0; i < MAX_NO_OF_PARKING_SPOT; i++)
			parkingSpots[i] = nullptr;
	}

	Parking::Parking(const char* filename, int noOfSpots_) {
		if (filename != nullptr && filename[0] != '\0' && strlen(filename) > 0 && noOfSpots_ >= 10 && noOfSpots_ <= 100)
		{
			m_name = new char[strlen(filename) + 1];
			strcpy(m_name, filename);
			noOfSpots = noOfSpots_;
			countVehicle = 0;

			for (int i = 0; i < MAX_NO_OF_PARKING_SPOT; i++)
				parkingSpots[i] = nullptr;

			if (loadDataFile()) {
				parkingMenu = "Parking Menu, select an action:";
				parkingMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Close Parking (End of day)" << "Exit Program";

				vehicleMenu = Menu("Select type of the vehicle:", 1);
				vehicleMenu << "Car" << "Motorcycle" << "Cancel";
			}
			else {
				cout << "Error in data file" << endl;
				setEmpty();
			}
		}
		else
			setEmpty();
	}

	Parking::~Parking() {
		saveData();
		Parking::setEmpty();
	}

	int Parking::run()
	{
		int result = 0;
		if (!isEmpty())
		{
			while (result == 0)
			{
				parkingStatus();
				switch (parkingMenu.run())
				{
				case 1:
					parkVehicle();
					break;
				case 2:
					returnVehicle();
					break;
				case 3:
					listParkVehicle();
					break;
				case 4:
					result = closeParking() ? 1 : 0;
					break;
				case 5:
					result = exitParkingApp() ? 1 : 0;
					cout << "Exiting program!" << endl;
					break;
				}
			}
		}
		return result;
	}


	bool Parking::isEmpty() const {
		return (m_name == nullptr) ? true : false;
	}

	void Parking::setEmpty() {
		if (m_name != nullptr)
			delete[] m_name;

		m_name = nullptr;
		noOfSpots = 0;
		countVehicle = 0;

		for (int i = 0; i < MAX_NO_OF_PARKING_SPOT; i++) {
			delete parkingSpots[i];
			parkingSpots[i] = nullptr;
		}

	}

	void Parking::parkingStatus() const {
		cout << "****** Seneca Valet Parking ******" << endl;
		cout << "*****  Available spots: ";
		cout.width(4);
		cout.setf(ios::left);
		cout << noOfSpots - countVehicle;
		cout << " *****" << endl;
		cout.unsetf(ios::fixed);
	}

	void Parking::parkVehicle() {

		bool check = false;
		Vehicle* createVehicle = nullptr;

		if ((noOfSpots - countVehicle) < 1)
			cout << "Parking is full" << endl;
		else {
			int choice = vehicleMenu.run();

			if (choice == 1) {

				createVehicle = new Car();
				createVehicle->setCsv(false);
				createVehicle->read(cin);

				for (int i = 0; i < noOfSpots && !check; i++) {
					if (parkingSpots[i] == nullptr) {
						check = true;
						parkingSpots[i] = createVehicle;
						parkingSpots[i]->setParkingSpot(i + 1);

						cout << endl;
						cout << "Parking Ticket" << endl;

						parkingSpots[i]->write();
						cout << endl;
						countVehicle++;
					}
				}
			}
			else if (choice == 2) {
				createVehicle = new Motorcycle();
				createVehicle->setCsv(false);
				createVehicle->read();

				for (int i = 0; i < noOfSpots && !check; i++) {
					if (parkingSpots[i] == nullptr) {
						check = true;
						parkingSpots[i] = createVehicle;
						parkingSpots[i]->setParkingSpot(i + 1);

						cout << endl;
						cout << "Parking Ticket" << endl;
						parkingSpots[i]->write();
						cout << endl;

						countVehicle++;
					}
				}
			}
			else if (choice == 3)
				cout << "Parking cancelled" << endl;
		}

	}

	void Parking::returnVehicle() {

		char temp[10];
		bool value = false;
		bool check = false;
		cout << "Return Vehicle" << endl;
		cout << "Enter Licence Plate Number: ";

		do {
			cin.getline(temp, 20, '\n');
			if (strlen(temp) > 8 || strlen(temp) < 1)
				cout << "Invalid Licence Plate, try again: ";
			else
				value = true;
			cout << endl;
		} while (!value);

		for (unsigned int i = 0; i < strlen(temp); i++)
			temp[i] = toupper(temp[i]);

		for (int i = 0; i < noOfSpots && check == false; i++)
		{
			if (parkingSpots[i] != nullptr && *parkingSpots[i] == temp)
			{
				check = true;
				parkingSpots[i]->setCsv(false);
				cout << "Returning: " << endl;
				parkingSpots[i]->write();
				cout << endl;
				delete parkingSpots[i];
				parkingSpots[i] = nullptr;
				countVehicle--;
			}
			else if (i == (noOfSpots - 1))
				cout << "License plate " << temp << " Not found" << endl;
		}
	}

	void Parking::listParkVehicle() const {
		cout << "*** List of parked vehicles ***" << endl;

		for (int i = 0; i < noOfSpots; i++) {
			if (parkingSpots[i] != nullptr) {
				parkingSpots[i]->setCsv(false);
				cout << *parkingSpots[i];
				cout << "-------------------------------" << endl;
			}
		}
	}

	bool Parking::closeParking() {
		bool result = false;
		if (isEmpty()) {
			cout << "Closing Parking" << endl;
			result = true;
		}
		else {
			char getValue, input;
			bool run = false;
			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";

			do {
				cin >> getValue;
				input = cin.get();

				if (input != '\n')
					cin.ignore(2000, '\n');
				if ((toupper(getValue) != 'Y' && toupper(getValue) != 'N') || input != '\n')
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				else
					run = true;

			} while (!run);

			if (toupper(getValue) == 'N') {
				cout << "Aborted!" << endl;
				result = false;
			}
			else {
				cout << "Closing Parking" << endl;
				for (int i = 0; i < noOfSpots; i++) {
					if (parkingSpots[i] != nullptr) {
						cout << endl;
						cout << "Towing request" << endl;
						cout << "*********************" << endl;
						parkingSpots[i]->setCsv(false);
						parkingSpots[i]->write();

						delete parkingSpots[i];
						parkingSpots[i] = nullptr;
						countVehicle--;
					}
				}
				result = true;
			}
		}
		return result;
	}

	bool Parking::exitParkingApp() const {
		char rslt, option;
		bool result = false;

		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";

		do {
			cin >> option;
			rslt = cin.get();
			if (rslt != '\n')
				cin.ignore(2000, '\n');
			if (rslt == '\n' || (toupper(option) == 'N' && toupper(option) == 'Y'))
				result = true;
			else
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";

		} while (!result);
		return toupper(option) == 'Y';
	}

	bool Parking::loadDataFile() {
		bool result = false;
		bool val = false;
		if (!isEmpty()) {
			ifstream f;
			f.open(m_name);

			if (f || Parking::isEmpty()) {
				result = true;

				while (f.good() && result) {

					Vehicle* vehicle = nullptr;
					char character = '\0';
					f >> character;
					f.ignore();

					if (f.good()) {
						if (character == 'M') {
							vehicle = new Motorcycle();
							val = true;
						}
						else if (character == 'C') {
							vehicle = new Car();
							val = true;
						}

						if (val == true) {
							vehicle->setCsv(true);
							vehicle->read(f);
						}

						if (vehicle != nullptr && !(*vehicle == Vehicle())) {
							parkingSpots[vehicle->getParkingSpot() - 1] = vehicle;
							countVehicle++;
						}
						else {
							delete vehicle;
							vehicle = nullptr;
							result = false;
						}
					}
				}

			}
			else
				result = false;
		}
		return result;
	}

	void Parking::saveData() const {
		if (!isEmpty()) {
			std::ofstream out;
			out.open(m_name);
			if (out.good()) {
				for (int i = 0; i < noOfSpots; i++) {
					if (parkingSpots[i] != nullptr) {
						parkingSpots[i]->setCsv(true);
						parkingSpots[i]->write(out);
					}
				}
			}
			out.close();
		}
	}
}
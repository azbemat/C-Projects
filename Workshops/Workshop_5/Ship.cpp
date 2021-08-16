#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string.h>

#include "Ship.h"

using namespace std;

namespace sdds {

	Ship::Ship() {
		setEmpty();
	}

	void Ship::setEmpty() {
		shipType[0] = '\0';
		noOfEngines = 0;
	}

	Ship::Ship(const char* type, Engine eng[], int no) {
		if (type != nullptr && type[0] != '\0' && strlen(type) <= 6 && no > 0) {
			noOfEngines = no;
			strcpy(shipType, type);
			for (int i = 0; i < no; i++)
				engine[i] = eng[i];
		}
		else
			setEmpty();
	}

	bool Ship::empty() const {
		return noOfEngines == 0 || shipType[0] == '\0' ? true : false;
	}

	float Ship::calculatePower() const {
		float power = 0;
		double pow = 0;
		for (int i = 0; i < noOfEngines; i++)
			pow += engine[i].get();
		power = float(pow) * 5;
		return power;
	}

	void Ship::display() const {
		if (empty())
			cout << "No available data" << endl;
		else {
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << shipType << "-";
			cout.width(6);
			cout << calculatePower() << endl;
			for (int i = 0; i < noOfEngines; i++)
				engine[i].display();
		}
	}

	Ship& Ship::operator+=(Engine e) {
		if (noOfEngines < MAX && !empty()) {
			engine[noOfEngines] = e;
			noOfEngines++;
		}
		else
			cout << "The ship doesn't have a type! Engine cannot be added!" << endl;
		return *this;
	}

	bool operator==(const Ship& lhs, const Ship& rhs) {
		return lhs.calculatePower() == rhs.calculatePower() ? true : false;
	}

	bool operator<(const Ship& lftShip, double power) {
		return lftShip.calculatePower() < power ? true : false;
	}
}	
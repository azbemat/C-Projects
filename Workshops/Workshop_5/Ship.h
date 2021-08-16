#ifndef SDDS_SHIP_H__
#define SDDS_SHIP_H__

#include<iostream>

#include "Engine.h"

namespace sdds {
	const int MAX = 10;

	class Ship {
		Engine engine[MAX];
		char shipType[7];
		int noOfEngines;
		float distancePower = 0;

	public:
		Ship();
		Ship(const char* type, Engine eng[], int no);
		void setEmpty();
		bool empty() const;
		float calculatePower() const;
		void display() const;
		Ship& operator+=(Engine e);
		friend bool operator==(const Ship& lhs, const Ship& rhs);
	};

	bool operator<(const Ship& lftShip, double power);
}
#endif  // !SDDS_SHIP_H__
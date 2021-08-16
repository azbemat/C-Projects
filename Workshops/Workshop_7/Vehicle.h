#ifndef SDDS_VEHICLE_H__
#define SDDS_VEHICLE_H__

#include <iostream>

const int MIN_SPEED = 100;
const int MAX_SPEED = 140;

using namespace std;

namespace sdds {

	class Vehicle {
		int m_speed;
		int m_noOfSeats;

	public:
		Vehicle();
		Vehicle(int spd, int noofseats);
		void setEmpty();
		bool isValid() const;
		bool isEmpty() const;
		bool finetune();
		ostream& display(ostream& os) const;
		istream& input(istream& in);
	};
	ostream& operator<<(ostream& os, const Vehicle& v);
	istream& operator>>(istream& in, Vehicle& v);
}
#endif // !SDDS_VEHICLE_H__

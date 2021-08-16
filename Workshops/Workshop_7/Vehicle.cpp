#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#include "Vehicle.h"

using namespace std;

namespace sdds {

	Vehicle::Vehicle() {
		setEmpty();
	}

	Vehicle::Vehicle(int spd, int noofseats) {
		if (spd >= MIN_SPEED && noofseats > 0) {
			m_speed = spd;
			m_noOfSeats = noofseats;
		}else {
			setEmpty();
		}
	}

	void Vehicle::setEmpty() {
		m_speed = 0;
		m_noOfSeats = 0;
	}

	bool Vehicle::isValid() const {
		return (m_speed >= MIN_SPEED && m_noOfSeats > 0) ? true : false;
	}

	bool Vehicle::isEmpty() const {
		return (m_speed == 0 && m_noOfSeats == 0) ? true : false;
	}

	bool Vehicle::finetune() {
		bool rslt = false;
		if (m_speed > MAX_SPEED) {
			m_speed = MIN_SPEED;
			rslt = true;
		}else {
			cout << "The car cannot be tuned" << endl;
			rslt = false;
		}
		return rslt;
	}

	ostream& Vehicle::display(ostream& os) const {
		if (isEmpty()) 
			os << "This Car is not initiated" << endl;
		else if (isValid()) {
			os << "|" << m_speed << "|" << m_noOfSeats << endl;
			if (m_speed > MAX_SPEED)
				os << "Car has to be fine-tuned for speed limit" << endl;
		}
		return os;
	}

	istream& Vehicle::input(istream& in) {
		int tempSpeed;
		int tempNoOfSeats;

		cout << "Enter the Vehicle`s speed: ";
		in >> tempSpeed;

		cout << "Enter no of seats: ";
		in >> tempNoOfSeats;

		Vehicle temp(tempSpeed, tempNoOfSeats);
		if(temp.m_speed != 0)
			*this = temp;

		return in;
	}

	ostream& operator<<(ostream& os, const Vehicle& v) {
		v.display(os);
		return os;
	}

	istream& operator>>(istream& in, Vehicle& v) {
		v.input(in);
		return in;
	}

}
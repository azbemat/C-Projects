#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#include "Car.h"

using namespace std;

namespace sdds {

	Car::Car() {
		setEmpty();
	}

	Car::Car(const char* type, int year, int spd, int noofseats):Vehicle(spd, noofseats) {
		if (type != nullptr && type[0] != '\0' && year > MAX_YEAR) {
			strncpy(m_charType, type, MAX_CHAR + 1);
			m_regYear = year;
		}
		else {
			setEmpty();
		}
	}

	void Car::setEmpty() {
		Vehicle::setEmpty();
		m_charType[0] = '\0';
		m_regYear = 0;
	}

	bool Car::isEmpty() const {
		return (m_charType[0] == '\0' || m_regYear == 0 ) ? true : false;
	}

	void Car::finetune() {
		if (m_regYear < MAX_YEAR)
			cout << "Car cannot be tuned and has to be scraped" << endl;
		else {
			if (Vehicle::finetune())
				cout << "This car is finely tuned to default speed" << endl;
		}
	}

	ostream& Car::display(ostream& os) const {
		if (isEmpty())
			cout << "Car is not initiated yet" << endl;
		else {
			os.width(20);
			os.setf(ios::left);
			os << m_charType;
			os.unsetf(ios::left);
			os << m_regYear;
			Vehicle::display(os);
		}
		return os;
	}

	istream& Car::input(istream& in) {
		char tempType[MAX_CHAR];
		int tempYear;
		cout << "Enter the car type: ";
		in.getline(tempType, MAX_CHAR + 1);
		in.ignore(MAX_CHAR, '\n');
		cout << "Enter the car registration year: ";
		in >> tempYear;

		if (tempType != nullptr && tempType[0] != '\0' && tempYear > MAX_YEAR) {
			strcpy(m_charType, tempType);
			m_regYear = tempYear;
		}else {
			setEmpty();
		}
		Vehicle::input(in);	
		return in;
	}

	ostream& operator<<(ostream& os, const Car& C) {
		C.display(os);
		return os;
	}

	istream& operator>>(istream& in, Car& C) {
		C.input(in);
		return in;
	}

}
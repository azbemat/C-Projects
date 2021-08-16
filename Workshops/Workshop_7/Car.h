#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__

#include "Vehicle.h"

const int MAX_CHAR = 20;
const int MAX_YEAR = 2000;

namespace sdds {

	class Car : public Vehicle {
		char m_charType[MAX_CHAR + 1];
		int m_regYear;

	public:
		Car();
		Car(const char* type, int year, int spd, int noofseats);
		void setEmpty();
		void finetune();
		bool isEmpty() const;
		ostream& display(ostream& os) const;
		istream& input(istream& in);
	};
	ostream& operator<<(ostream& os, const Car& C);
	istream& operator>>(istream& in, Car& C);
}
#endif // !SDDS_CAR_H__

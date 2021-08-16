#ifndef SDDS_DOCTOR_H__
#define SDDS_DOCTOR_H__

#include "Employee.h"

const int MIN_W_HOURS = 6;
const int MAX_CHAR = 20;

using namespace std;

namespace sdds {

	class Doctor : public Employee {
		char m_type[MAX_CHAR];
		double m_salary;
		int m_whours;
		bool m_specialist;

	public:
		Doctor();
		Doctor(const char* type, double salary, int hours, bool specialist = false);
		void setEmpty();
		virtual void setSalary(double salary);
		virtual bool workHours();
		virtual void bonus();
		virtual ostream& display(ostream& os) const;

	};


}
#endif // ! SDDS_DOCTOR_H__

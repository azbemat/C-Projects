#ifndef SDDS_EMPLOYEE_H__
#define SDDS_EMPLOYEE_H__
#include <iostream>

using namespace std;

namespace sdds {

	class Employee {
	public:
		virtual void setSalary(double salary_) = 0;
		virtual void bonus() = 0;
		virtual bool workHours() = 0;
		virtual ostream& display(ostream& os) const = 0;
		virtual ~Employee(){}
	};

}
#endif // !SDDS_EMPLOYEE_H__

#ifndef SDDS_BASKET_H__
#define SDDS_BASKET_H__

#include <iostream>

using namespace std;

namespace sdds {

	class Basket{
		char* m_fruitName;
		int m_qty; 
		double m_price; 

	public:

		Basket();
		~Basket();
		void setEmpty();
		Basket(const char* name, int qty, double price);
		Basket(const Basket&);
		void setName(const char* name);
		void setQty(int qty);
		void setPrice(double price);
		bool isEmpty() const;
		bool addPrice(double);
		ostream& display(ostream& os) const;
		Basket& operator=(const Basket&);
		bool operator==(const Basket& src);
		bool operator!=(const Basket& src);
	};

	ostream& operator<<(ostream& os, const Basket& bsk);

}
#endif // !SDDS_BASKET_H__

/* ------------------------------------------------------
Final Project Milestone 6
Module: Menu
Filename: Menu.h
Version 1.0
Revision History
-----------------------------------------------------------
Date		Reason
2020/3/2	Preliminary release
2020/3/12	Updated
-----------------------------------------------------------
Name: Anas Bemat
ID: 165239187
mail: azbemat@myseneca.ca
------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__

#include <iostream>

using namespace std;

namespace sdds {

	const int MAX_NO_OF_ITEMS = 10;

	class MenuItem {

		char* menuItem;
		friend class Menu;

		MenuItem();
		~MenuItem();
		void setEmpty();
		bool isEmpty() const;
		MenuItem(const char* menuItem_);
		ostream& displayItem(ostream& os = cout) const;
		MenuItem(const MenuItem& src) = delete;
		MenuItem& operator=(const MenuItem& src) = delete;
	};

	class Menu {

		char* title;
		MenuItem* menuItemsPtr[MAX_NO_OF_ITEMS];
		int noOfItems;
		int indent;

	public:

		Menu();
		~Menu();
		void setEmpty();
		bool isEmpty() const;
		Menu(const char* title_, int no = 0);
		Menu(const Menu& src);
		Menu& operator=(const Menu& src);
		operator bool() const;
		ostream& display(ostream& os = cout) const;
		Menu& operator=(const char* title_);
		void add(const char* additem);
		Menu& operator<<(const char* insrt);
		int run() const;
		operator int() const;
		void deleteContent();
	};
}
#endif // !SDDS_MENU_H__

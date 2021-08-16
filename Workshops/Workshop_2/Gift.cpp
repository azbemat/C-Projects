#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

#include "Gift.h"

using namespace std;

namespace sdds {

	void gifting(char* desc) {

		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> desc;

	}

	void gifting(double& price) {

		cout << "Enter gift price: ";
		cin >> price;
		while (price < 0 || price > MAX_PRICE) {
			cout << "Gift price must be between 0 and " << MAX_PRICE << endl;
			cout << "Enter gift price: ";
			cin >> price;
		}

	}

	void gifting(int& units) {

		cout << "Enter gift units: ";
		cin >> units;
		while (units < 1) {
			cout << "Gift units must be at least 1" << endl;
			cout << "Enter gift units: ";
			cin >> units;
		}

	}

	void gifting(Gift& gift) {

		cout << "Preparing a gift..." << endl;
		gifting(gift.g_description);
		gifting(gift.g_price);
		gifting(gift.g_units);
		wrap(gift);

	}

	bool wrap(Gift& gift) {

		char temp[MAX_LENGTH + 1];
		bool result = true;

		if (gift.wrap_layers == 0) {

			cout << "Wrapping gifts..." << endl;

			cout << "Enter the number of wrapping layers for the Gift: ";
			cin >> gift.wrap_layers;
			while (gift.wrap_layers < 1) {
				cout << "Layers at minimum must be 1, try again." << endl;
				cout << "Enter the number of wrapping layers for the Gift: ";
				cin >> gift.wrap_layers;
			}

			//allocating dynamic memory for layers
			gift.wrap = new Wrapping[gift.wrap_layers];


			for (int i = 0; i < gift.wrap_layers; i++) {
				cout << "Enter wrapping pattern #" << i + 1 << ": ";
				cin >> temp;

				//allocating dynamic memory for pattern
				gift.wrap[i].pattern = new char[strlen(temp) + 1];
				strcpy(gift.wrap[i].pattern, temp);
			}
			result = true;

		}
		else {
			cout << "Gift is already wrapped!" << endl;
			result = false;
		}

		return result;

	}


	bool unwrap(Gift& gift) {

		bool result = true;

		if (gift.wrap_layers != 0) {

			cout << "Gift being unwrapped." << endl;

			for (int i = 0; i < gift.wrap_layers; i++)
				delete[]gift.wrap[i].pattern;

			gift.wrap = nullptr;
			gift.wrap_layers = 0;

			delete[] gift.wrap;
			gift.wrap = nullptr;

			result = true;

		}
		else {
			cout << "Gift isn't wrapped! Can't unwrap." << endl;
			result = false;
		}

		return result;

	}

	void display(const Gift& gift) {
		if (gift.wrap > 0) {
			cout << "Gift Details:" << endl;
			cout << "Description: " << gift.g_description << endl;
			cout << "Price: " << gift.g_price << endl;
			cout << "Units: " << gift.g_units << endl;
			cout << "Wrap Layers: " << gift.wrap_layers << endl;

			for (int i = 0; i < gift.wrap_layers; i++)
				cout << "Wrap #" << i + 1 << ": " << gift.wrap->pattern << endl;

		}
		else {
			cout << "Gift Details:" << endl;
			cout << "Description: " << gift.g_description << endl;
			cout << "Price: " << gift.g_price << endl;
			cout << "Units: " << gift.g_units << endl;
			cout << "Unwrapped" << endl;
		}

	}

}
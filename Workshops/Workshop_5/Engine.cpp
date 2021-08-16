#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string.h>

#include "Engine.h"

using namespace std;

namespace sdds
{
	Engine::Engine() {
		setEmpty();
	}

	void Engine::setEmpty() {
		engineType[0] = '\0';
		size = 0;
	}

	Engine::Engine(const char* type_, double Size) {
		if (type_ != nullptr && type_[0] != '\0' && Size > 0 && strlen(type_) <= 30) {
			strcpy(engineType, type_);
			size = Size;
		}
		else
			setEmpty();
	}

	double Engine::get() const {
		return size;
	}

	void Engine::display() const {
		cout << size << " liters - " << engineType << endl;
	}
}
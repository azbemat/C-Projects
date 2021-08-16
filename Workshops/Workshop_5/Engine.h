#ifndef SDDS_ENGINE_H__
#define SDDS_ENGINE_H__

namespace sdds {

	class Engine {
		char engineType[30];
		double size;

	public:
		Engine();
		Engine(const char* type_, double Size);
		void setEmpty();
		double get() const;
		void display() const;
	};
}
#endif  // !SDDS_ENGINE_H__
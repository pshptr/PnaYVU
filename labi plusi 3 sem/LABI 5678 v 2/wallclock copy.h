#pragma once
#include "clock.h"
#include "mehclock.h"

class WallClock : public MechClock {	//класс настенных часов
private:
	int pendulum;													//длина маятника
public:
	int class_name() { return 4; }									//идентификатор класса
	WallClock() : MechClock() {}									//конструктор по умолчанию
	//конструктор с параметрами
	WallClock(char* name, double cost, int weight, int pendulum)
		:MechClock(name, cost, weight) {
		this->pendulum = pendulum;
	}
	void setPendulum(int pendulum);	//изменить длину маятника
	int getPendulum();						//получить длину маятника
	void redact();

	//оператор ввода
	friend istream& operator>> (istream& in, WallClock& clock);
	//оператор вывода
	friend ostream& operator<< (ostream& out, WallClock& clock);

	void operator= (WallClock& clock);
};

//оператор ввода


//оператор вывода



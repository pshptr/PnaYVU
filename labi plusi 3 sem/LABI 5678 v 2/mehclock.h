#pragma once
#include "clock.h"

class MechClock : public Clock {	//класс механических часов
protected:
	double weight;											//вес часов
public:
	int class_name() { return 3; }							//идентификатор класса
	MechClock() : Clock() {	}								//конструктор по умолчанию
	//конструктор с параметрами
	MechClock(char* name, double cost, double weight) : Clock(name, cost)
	{
		this->weight = weight;								//вес часов
	}
	void setWeight(int weight);	//изменить вес
	int getWeight();					//получить вес

	friend istream& operator>> (istream& in, MechClock& clock);
	friend ostream& operator<< (ostream& out, MechClock& clock);

	void redact();

	void operator= (MechClock& clock);
};

//оператор ввода


//оператор вывода



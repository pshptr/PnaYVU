#pragma once
#include "clock.h"
#include "electro.h"

class FitClock : public ElectroClock {	//класс фитнес-часов
private:
	int speed;														//скорость
public:
	int class_name() { return 2; }									//идентификатор класса
	FitClock() : ElectroClock() {}									//конструктор по умолчанию
	//конструктор с параметрами
	FitClock(char* name, double cost, double charge, int speed) : ElectroClock(name, cost, charge)
	{
		this->speed = speed;										//скорость
	}
	void setSpeed(int speed);
	int getSpeed();								//получить скорость

	void  operator= (FitClock& clock);
	void redact();
	friend istream& operator>> (istream& in, FitClock& clock);
	friend ostream& operator<< (ostream& out, FitClock& clock);
};

//оператор ввода


//оператор вывода

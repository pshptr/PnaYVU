#pragma once
#include "clock.h"

class ElectroClock : public Clock {	//класс электронных часов
protected:
	double charge;											//зар€д батареи
public:
	int class_name() { return 1; }							//идентификатор класса
	ElectroClock() : Clock() {}								//конструктор по умолчанию								
	//конструктор с параметрами
	ElectroClock(char* name, double cost, double charge) : Clock(name, cost)
	{
		this->charge = charge;
	}
	void setCharge(int charge);	//изменить зар€д батареи
	double getCharge();					//получить зар€€д батареи
	void redact();

	//оператор ввода
	friend 	istream& operator>>(istream& in, ElectroClock& clock);
	//оператор вывода
	friend ostream& operator<<(ostream& out, ElectroClock& clock); 
	void operator= (ElectroClock& clock);
};



//оператор вывода



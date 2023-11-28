#pragma once
#include "clock.h"

class ElectroClock : public Clock {	//����� ����������� �����
protected:
	double charge;											//����� �������
public:
	int class_name() { return 1; }							//������������� ������
	ElectroClock() : Clock() {}								//����������� �� ���������								
	//����������� � �����������
	ElectroClock(char* name, double cost, double charge) : Clock(name, cost)
	{
		this->charge = charge;
	}
	void setCharge(int charge);	//�������� ����� �������
	double getCharge();					//�������� ������ �������
	void redact();

	//�������� �����
	friend 	istream& operator>>(istream& in, ElectroClock& clock);
	//�������� ������
	friend ostream& operator<<(ostream& out, ElectroClock& clock); 
	void operator= (ElectroClock& clock);
};



//�������� ������



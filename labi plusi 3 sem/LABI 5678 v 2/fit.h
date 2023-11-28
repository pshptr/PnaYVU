#pragma once
#include "clock.h"
#include "electro.h"

class FitClock : public ElectroClock {	//����� ������-�����
private:
	int speed;														//��������
public:
	int class_name() { return 2; }									//������������� ������
	FitClock() : ElectroClock() {}									//����������� �� ���������
	//����������� � �����������
	FitClock(char* name, double cost, double charge, int speed) : ElectroClock(name, cost, charge)
	{
		this->speed = speed;										//��������
	}
	void setSpeed(int speed);
	int getSpeed();								//�������� ��������

	void  operator= (FitClock& clock);
	void redact();
	friend istream& operator>> (istream& in, FitClock& clock);
	friend ostream& operator<< (ostream& out, FitClock& clock);
};

//�������� �����


//�������� ������

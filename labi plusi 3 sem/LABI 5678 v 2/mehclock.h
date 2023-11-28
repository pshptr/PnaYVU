#pragma once
#include "clock.h"

class MechClock : public Clock {	//����� ������������ �����
protected:
	double weight;											//��� �����
public:
	int class_name() { return 3; }							//������������� ������
	MechClock() : Clock() {	}								//����������� �� ���������
	//����������� � �����������
	MechClock(char* name, double cost, double weight) : Clock(name, cost)
	{
		this->weight = weight;								//��� �����
	}
	void setWeight(int weight);	//�������� ���
	int getWeight();					//�������� ���

	friend istream& operator>> (istream& in, MechClock& clock);
	friend ostream& operator<< (ostream& out, MechClock& clock);

	void redact();

	void operator= (MechClock& clock);
};

//�������� �����


//�������� ������



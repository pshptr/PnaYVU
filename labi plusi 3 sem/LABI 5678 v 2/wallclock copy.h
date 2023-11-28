#pragma once
#include "clock.h"
#include "mehclock.h"

class WallClock : public MechClock {	//����� ��������� �����
private:
	int pendulum;													//����� ��������
public:
	int class_name() { return 4; }									//������������� ������
	WallClock() : MechClock() {}									//����������� �� ���������
	//����������� � �����������
	WallClock(char* name, double cost, int weight, int pendulum)
		:MechClock(name, cost, weight) {
		this->pendulum = pendulum;
	}
	void setPendulum(int pendulum);	//�������� ����� ��������
	int getPendulum();						//�������� ����� ��������
	void redact();

	//�������� �����
	friend istream& operator>> (istream& in, WallClock& clock);
	//�������� ������
	friend ostream& operator<< (ostream& out, WallClock& clock);

	void operator= (WallClock& clock);
};

//�������� �����


//�������� ������



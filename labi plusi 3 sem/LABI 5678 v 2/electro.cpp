#include "electro.h"

void ElectroClock:: setCharge(int charge) { this->charge = charge; }	//�������� ����� �������
double ElectroClock::  getCharge() { return charge; }					//�������� ������ �������
void ElectroClock:: redact() {											//��������������
	system("cls");
	cout << *this;											//����� �����
	cout << "�������������?";
	if (_getch() != '1') return;							//����� ��������������
	bool more = true;										//���������� ��������������
	while (more) {
		system("cls");
		cout << "1 - �������� ��������" << endl
			<< "2 - �������� ���������" << endl
			<< "3 - �������� ����� ������������" << endl
			<< "0 - �������� ��������������" << endl;
		switch (_getch()) {									//����� ��������
		case '1':											//�������� ��������
			cout << "����� ��������:";
			char new_name[LEN];								//����� ��������
			rewind(stdin);							//������� ������
			cin.getline(new_name, LEN);			//���� ������
			this->setName(new_name);						//����� ��������
			break;
		case '2':											//�������� ���������
			cout << "����� ���������:";
			double new_cost;								//����� ����
			cin >> new_cost;								//���� ����� ����
			this->setCost(new_cost);						//����� ����
			break;
		case '3':											//�������� �����
			cout << "����� ����� ������������:";
			int new_charge;									//����� �����
			cin >> new_charge;								//���� ������
			this->setCharge(new_charge);					//����� ������
			break;
		case '0':											//����� ��������������
			more = false;
			break;
		}
	}
	cout << *this;
}

//�������� �����
istream& operator>>(istream& in, ElectroClock& clock) {
	cout << endl << "��������:";
	in >> clock.name;											//���� ��������
	cout << "���������:";
	in >> clock.cost;											//���� ���������
	cout << "����� �������:";
	in >> clock.charge;											//���� ������ �������
	return in;
}
//�������� ������
ostream& operator<<(ostream& out, ElectroClock& clock) {
	out << setw(LEN) << left << clock.name << setw(5) << left << clock.cost << setw(6) << left << clock.charge << endl;
	return out;
}
void ElectroClock:: operator= (ElectroClock& clock) {					//�������� ������������
	if (this == &clock) return;								//�������� �� ����������������
	strcpy_s(this->name, 20, clock.name);									//����� ������
	cost = clock.cost;										//����������� ���������
	charge = clock.charge;									//����������� ������ �������
}

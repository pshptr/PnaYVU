#include "mehclock.h"

void MechClock:: setWeight(int weight) { this->weight = weight; }	//�������� ���
int MechClock:: getWeight() { return weight; }						//�������� ���

 istream& operator>> (istream& in, MechClock& clock) {
	cout << endl << "��������:";
	in >> clock.name;											//���� ��������
	cout << "���������:";
	in >> clock.cost;											//���� ���������
	cout << "���:";
	in >> clock.weight;											//���� ����
	return in;
}
 ostream& operator<< (ostream& out, MechClock& clock) {
	out << setw(LEN) << left << clock.name << setw(5) << left << clock.cost << clock.weight << endl;
	return out;
}

void MechClock:: redact() {											//��������������
	system("cls");
	cout << *this;										//����� ����������
	cout << "�������������?";
	if (_getch() != '1') return;						//����� ��������������
	bool more = true;									//���������� ��������������
	while (more) {
		system("cls");
		cout << "1 - �������� ��������" << endl
			<< "2 - �������� ���������" << endl
			<< "3 - �������� ���" << endl
			<< "0 - �������� ��������������" << endl;
		switch (_getch()) {									//����� ��������
		case '1':											//�������� ��������
			cout << "����� ��������:";
			char new_name[LEN];								//����� ��������
			rewind(stdin);							//������� ������
			cin.getline(new_name, LEN);			//���� ������ ��������
			this->setName(new_name);						//����� ��������
			break;
		case '2':											//�������� ���������
			cout << "����� ���������:";
			double new_cost;								//����� ����
			cin >> new_cost;								//���� ����� ����
			this->setCost(new_cost);						//����� ����
			break;
		case '3':											//�������� ���
			cout << "����� ���:";
			int new_weight;									//����� ���
			cin >> new_weight;								//���� ������ ����
			this->setWeight(new_weight);					//����� ����
			break;
		case '0':											//����� ��������������
			more = false;
			break;
		}
	}
	cout << *this;
}

void MechClock:: operator= (MechClock& clock) {						//�������� ������������
	if (this == &clock) return;								//������� �� �������������yb t										//����� ������
	strcpy_s(this->name, 20, clock.name);
	cost = clock.cost;										//����������� ���������
	weight = clock.weight;									//����������� ����
}

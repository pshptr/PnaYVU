#include "wallclock.h"

void WallClock:: setPendulum(int pendulum) { this->pendulum = pendulum; }	//�������� ����� ��������
int WallClock::getPendulum() { return pendulum; }							//�������� ����� ��������
void WallClock:: redact() {													//�������������� 
	system("cls");
	cout << *this;												//����� ����������
	cout << "�������������?1 - �� , ����� - ���";
	if (_getch() != '1') return;								//����� ��������������
	bool more = true;											//���������� ��������������
	while (more) {
		system("cls");
		cout << "1 - �������� ��������" << endl
			<< "2 - �������� ���������" << endl
			<< "3 - �������� ���" << endl
			<< "4 - �������� ����� ��������" << endl
			<< "0 - �������� ��������������" << endl;
		switch (_getch()) {										//����� ��������
		case '1':												//�������� ��������
			cout << "����� ��������:";
			char new_name[LEN];									//����� ��������
			rewind(stdin);								//������� ������
			cin.getline(new_name, LEN);				//���� ������ ��������
			this->setName(new_name);							//����� ��������
			break;
		case '2':												//�������� ���������
			cout << "����� ���������:";
			double new_cost;									//����� ����
			cin >> new_cost;									//���� ����� ����
			this->setCost(new_cost);							//����� ����
			break;
		case '3':												//�������� ���
			cout << "����� ���:";
			int new_weight;										//����� ���
			cin >> new_weight;									//���� ������ ����
			this->setWeight(new_weight);						//����� ����
			break;
		case '4':												//�������� �������
			cout << "����� ����� �������:";
			int new_pendulum;									//����� ����� ��������
			cin >> new_pendulum;								//���� ����� ������
			this->setPendulum(new_pendulum);					//����� ����� ��������
			break;
		case '0':												///����� ��������������
			more = false;
			break;
		}
	}
	cout << *this;
}

//�������� �����
istream& operator>> (istream& in, WallClock& clock) {
	cout << endl << "��������:";
	in >> clock.name;													//���� ��������
	cout << "���������:";
	in >> clock.cost;													//���� ���������
	cout << "���:";
	in >> clock.weight;													//���� ����
	cout << "����� ��������:";
	in >> clock.pendulum;												//���� ����� ��������
	return in;
}
//�������� ������
ostream& operator<< (ostream& out, WallClock& clock) {
	out << setw(LEN) << left << clock.name << setw(5) << left << clock.cost << setw(6) << left << clock.weight << clock.pendulum << endl;
	return out;
}

void WallClock:: operator= (WallClock& clock) {								//�������� ������������
	if (this == &clock) return;										//�������� �� ����������������
	strcpy_s(this->name, 20, clock.name);
	cost = clock.cost;												//����������� ���������
	weight = clock.weight;											//����������� ����
	pendulum = clock.pendulum;										//����������� ���� ��������
}

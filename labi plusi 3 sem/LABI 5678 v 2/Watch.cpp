#include"Watch.h"
#include<iostream>
using namespace std;
Watch::Watch()
{
	automatic = 1;
}
void Watch::input()
{
	rewind(stdin);
	char autom;
	bool loop;
	cout << "���� �������������� ?" << endl << "1-��" << endl << "2-���" << endl;
	do
	{
		loop = 1;
		cin >> autom;
		switch (autom)
		{
		case '1':
			this->automatic = 1;
			break;
		case '2':
			this->automatic = 0;
			break;
		default:
			cout << "������� �� ������ ��������, ��������� ����";
			rewind(stdin);
			loop = 0;
			break;

		}
	} while (loop == 0);
	Mechanic::input();
	Clock::input();


}
void Watch::output()
{
	cout << "������������ ����� :" << endl;
	if (automatic == true)
	{
		cout << "��������������" << endl;
	}
	else cout << "�� ��������������" << endl;
	Mechanic::output();
	Clock::output();
}
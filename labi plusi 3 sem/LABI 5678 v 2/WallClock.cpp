#include"WallClock.h"
#include<iostream>
#include"ExpVvod.h"
using namespace std;
void WallClock::input()
{
	int a;
	bool loop,b;
	cout << "���� �� � ����� ������� " << endl << "1-��" << endl << "2-���" << endl;
	do
	{
		loop = 1;
		b = 1;
		while (b)
		{
			try
			{
				if (!(cin >> a)||a<0||a>2)throw Exp_vvod(123, "������������ ����");
				b = 0;
			}
			catch (Exp_vvod& ex)
			{
				ex.Show();
				cin.clear();
				cin.ignore(10, '\n');
			}
		}
		switch (a)
		{
		case 1:
			this->mayatnic = 1;
			break;
		case 2:
			this->mayatnic = 0;
			break;
		default:
			cout << "������� �� ������ �������� " << endl;
			rewind(stdin);
			loop = 0;
			break;
		}
	} while (loop == 0);
	Mechanic::input();
	Clock::input();
}
void  WallClock::output()
{
	cout << "������������ ����� :" << endl;
	Mechanic::output();
	Clock::output();
	if (this->mayatnic == 1)
	{
		cout << "������� ��������: �� " << endl;
	}
	else 	cout << "������� ��������: ��� " << endl;

}
WallClock::WallClock()
{
	mayatnic = 1;
}

bool WallClock::Getmayatnic()
{
	return mayatnic;
}

void WallClock::SetMayatnic(bool xm)
{
	mayatnic = xm;
}

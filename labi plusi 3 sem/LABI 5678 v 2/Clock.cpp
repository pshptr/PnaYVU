#include<iostream>
#include"Clock.h"
#include"ExpVvod.h"
using namespace std;
Clock::Clock()
{
	Brend[0] = ' ';
	Time = 0;
}
char* Clock::GetBrend()
{
	return Brend;
}
int Clock::GetTime()
{
	return Time;
}
void Clock::SetTime(int valuex)
{
	Time = valuex;
}
void Clock::SetBrend(char* Brendvalue)
{
	strcpy_s(Brend, 255, Brendvalue);
}
void Clock::input()
{
	bool a;
	cout << "������� ����� �����" << endl;
	a = 1;
	while (a)
	{
		try
		{
			if (!(cin >> this->Brend))throw Exp_vvod(123, "������� ������ ����� �����");
			a = 0;
		}
		catch (Exp_vvod& ex)
		{
			ex.Show();
			cin.clear();
			cin.ignore(10, '\n');
		}
	}
	cout << "������������ �����" << endl;
	a = 1;
	while (a)
	{
		try
		{
			if (!(cin >> this->Time))throw Exp_vvod(123, "������� ������ ����� �����");
			a = 0;
		}
		catch (Exp_vvod& ex)
		{
			ex.Show();
			cin.clear();
			cin.ignore(10, '\n');
		}
	}
}
void Clock::output()
{
	cout << "�����:" << endl << this->Brend << endl;
	cout << "�����" << endl << this->Time << endl;
}
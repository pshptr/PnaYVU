#include"FitnesTracker.h"
#include<iostream>
#include"ExpVvod.h"
using namespace std;
int FitnesTracker::Getdistance()
{
	return distans[1];
}
void FitnesTracker::Setdistance(int xdistance[])
{
	distans[0] = xdistance[0];
	distans[1] = xdistance[1];
}
FitnesTracker::FitnesTracker()
{
	for (int i = 0; i < 2; i++)
	{
		distans[i] = 0;
	}
}
void FitnesTracker::input()
{
	rewind(stdin);
	Clock::input();
	bool a=1;
	cout << "����� ������������ ��������� �� ������� ������ ������";
	while (a)
	{
		try
		{
			if (!(cin >> this->distans[0]))throw Exp_vvod(123, "������� ������ ����� �����");
			a = 0;
		}
		catch (Exp_vvod& ex)
		{
			ex.Show();
			cin.clear();
			cin.ignore(10, '\n');
		}
	}
	a = 1;
	cout << "����� ����������� ��������� �� ������� ������ ������";
	a = 1;
	while (a)
	{
		try
		{
			if (!(cin >> this->distans[1]))throw Exp_vvod(123, "������� ������ ����� �����");
			a = 0;
		}
		catch (Exp_vvod& ex)
		{
			ex.Show();
			cin.clear();
			cin.ignore(10, '\n');
		}
	}
	Electronic::input();
}
void  FitnesTracker::output()
{
	cout << "������������ ����� :" << endl;
	Clock::output();
	Electronic::output();
	cout << "������������ ��������� �� ������� ������ ������  :" << this->distans[0] << endl;
	cout << "����������� ��������� �� ������� ������ ������  :" << this->distans[1] << endl;
}
#include"Electronic.h"
#include<iostream>
#include"ExpVvod.h"
using namespace std;
Electronic::Electronic()
{
	zar = 0;
}

int Electronic::GetZar()
{
	return zar;
}

void Electronic::SetZar(int xzar)
{
	zar = xzar;
}

void Electronic::input()
{
	bool a;
	cout << "����� ����� �����";
	a = 1;
	while (a)
	{
		try
		{
			if (!(cin >> this->zar))throw Exp_vvod(123, "������� ������ ����� �����");
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
void Electronic::output()
{
	cout << "�����:" << endl << this->zar << endl;
}
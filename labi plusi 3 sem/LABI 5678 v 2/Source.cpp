#include <iostream>  
#include <string> 
#include"Clock.h"
#include"Electronic.h"
#include"Mechanic.h"
#include"FitnesTracker.h"
#include"WallClock.h"
#include"Watch.h"
#include"ExpVvod.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	bool loop;
	int k;
	int  tip;
	WallClock clock1,cl;
	Watch clock2;
	FitnesTracker clock3;
	cout << " � ��� ���� ��� ���� �����, ����� ���������� � ��� " << endl;
	cout << "��������� ���������� � ������ �����:" << endl;
    clock1.input();
	cout << "��������� ���������� � ������ �����:" << endl;
	clock2.input();	
	cout << "��������� ���������� � ������� �����:" << endl;
	clock3.input();
	system("cls");
	k = 0;
	bool a ;
	do
	{
		cout << " ���������� � ����� ����� �� ������ �������� ?" << endl << "1-WallClock" << endl << "2-Watch" << endl << "3-FitnesTracker" << endl << "4-��������� ���������"<<endl;
		rewind(stdin);
		a = 1;
		while (a)
		{
			try
			{
				if (!(cin >> tip)|| tip<0||tip>4)throw Exp_vvod(123, "������������ ���");
				a = 0;
			}
			catch (Exp_vvod& ex)
			{
				ex.Show();
				cin.clear();
				cin.ignore(10, '\n');
			}
		}
		loop = 1;
		switch (tip)
		{
		case 1:
			clock1.output();
			break;
		case 2:
			clock2.output();
			break;
		case 3:
			clock3.output();
			break;
		case 4:
			k = 1;
			break;
		default:
			cout << "������� ���� ����� �� ����������, ������� ��� ���" << endl;
			rewind(stdin);
			loop = 0;
		}
	} while (loop == 0||k!=1);


}
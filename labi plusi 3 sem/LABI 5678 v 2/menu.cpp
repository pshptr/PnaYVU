#include"List.h"
#include"ExpVvod.h"
#include "menu.h"

void input(int& in)
{
	
	if (!(cin >> in))
	{
		throw Exp_vvod(123, "������� ������ ����� �����");
	};
	if (in < 0 || in>16)
	{
		throw Exp_vvod(122, "������������ ����( ��� ���������� ���������)");
	}
}
void insert(int& kol)
{
	if (!(cin >> kol))
	{
		throw Exp_vvod(123, "������� ������ ����� �����");
	};
	if (kol < 0)
	{
		throw Exp_vvod(121, "�� ������� ������������� �����");

	}
}
void inputloop(int& loop, List<WallClock> obj)
{
	try
	{
		if(!(cin>>loop)||loop>obj.GetSize()) throw Exp_vvod(123, "������� �������� ��� � ������");
	}
	catch (Exp_vvod& p)
	{
		p.Show();
	}
}
void menu(List<WallClock> obj)
{
	char c[20],t[20];
	strcpy_s(c, 20, "Binary.dat");
	strcpy_s(t, 20, "Text.txt");
		File f(c);
		f.Open();
		File ft(t);
		WallClock data;
		int kol, index;
		int in;
		bool choose = 1, spis = 0, vvod;
		do
		{
			cout << "������� ��� �� ������ �������:" << endl << "1-������� ����(����������� ������)" << endl
				<< "2-����������� ���������� ������" << endl << "3-�������� ������� � ������ ������"
				<< endl << "4-�������� ������� �  �����  ������" << endl << "5-������� ������� � ������ ������"
				<< endl << "6-������� ������� � ����� ������" << endl << "7-������� ������� ������ �� �������"
				<< endl << "8-������ ������� ������ ������" << endl << "9-������� ������" << endl << "11-�������� ������� �� �������"
				<< endl <<"12-��������� ������ � �������� ����"<<endl<<"13-��������� �� ��������� ����� "<<endl <<"14-��������� ������ �� ���������� �����"
				<<endl<<"15-�������� ���� � ��������� ����"<<endl<<"0-��������� ���������" << endl;
			try
			{
				input(in);
			}
			catch (Exp_vvod& er)
			{
				er.Show();
				cin.clear();
				cin.ignore(10, '\n');
				in = 15;
			}

			switch (in)
			{
			case 0:
				choose = 0;
				break;
			case 1:
				if (spis == 0)
				{
					cout << "������� ���������� ��������� ������" << endl;
					try
					{
						insert(kol);
					}
					catch (Exp_vvod& error)
					{
						error.Show();
						cin.clear();
						cin.ignore(10, '\n');
						break;
					}
					for (int i = 0; i < kol; i++)
					{
						vvod = 1;
						cout << "������� ������  � " << i << " ������ ������" << endl;
						while (vvod)
						{
							try
							{
								data.input();
								//inp(data);
								vvod = 0;
							}
							catch (Exp_vvod& error)
							{
								error.Show();
								cin.clear();
								cin.ignore(10, '\n');

							}
						}

						obj.push_back(data);
					}
					cout << "������ ������� ������" << endl;
					spis = 1;
					break;
				}
				else
				{
					cout << "������ ��� ����������, ������ ��� ������� ����� �������� ������������" << endl;
					break;
				}
			case 2:
				if (spis == 0)
				{
					cout << "������ ��� �� ������ " << endl;
					break;
				}
				else
				{
					try
					{
						for (int i = 0; i < obj.GetSize(); i++)
						{
							if (i > obj.GetSize())throw Exp_cout(12, "����� �� �������");
							obj[i].output();
						}
					}
					catch (Exp_cout& ex)
					{
						ex.show1();
					}

					break;
				}
			case 3:
				if (spis == 0)
				{
					cout << "������ ��� �� ������ " << endl;
					break;
				}
				else
				{
					cout << "������� ������ � ����������� ������ ������";
					vvod = 1;
					while (vvod)
					{
						try
						{
							data.input();
							vvod = 0;
						}
						catch (Exp_vvod& error)
						{
							error.Show();
							cin.clear();
							cin.ignore(10, '\n');

						}
					}
					obj.push_front(data);
					break;
				}
			case 4:
				if (spis == 0)
				{
					cout << "������ ��� �� ������ " << endl;
					break;
				}
				else
				{
					cout << "������� ������ � ����������� ������ ������";
					vvod = 1;
					while (vvod)
					{
						try
						{
							data.input();
							vvod = 0;
						}
						catch (Exp_vvod& error)
						{
							error.Show();
							cin.clear();
							cin.ignore(10, '\n');

						}
					}
					obj.push_back(data);
					break;
				}
			case 5:
				if (spis == 0)
				{
					cout << "������ ��� �� ������ " << endl;
					break;
				}
				else
				{
					obj.pop_front();
					cout << "������� ������" << endl;
					break;
				}
			case 6:
				if (spis == 0)
				{
					cout << "������ ��� �� ������ " << endl;
					break;
				}
				else
				{

					obj.popback();
					cout << "������� ������" << endl;
					break;
				}
			case 7:
				if (spis == 0)
				{
					cout << "������ ��� �� ������ " << endl;
					break;
				}
				else
				{
					cout << "������� ������" << endl;
					try
					{
						insert(index);
					}
					catch (Exp_vvod& error)
					{
						error.Show();
						cin.clear();
						cin.ignore(10, '\n');

					}
					obj.removeAt(index);
					break;

				}
			case 8:
				if (spis == 0)
				{
					cout << "������ ��� �� ������ " << endl;
					break;
				}
				else
				{
					cout << "������ ������:  " << endl << obj.GetSize();
					break;
				}
			case 9:
				if (spis == 0)
				{
					cout << "������ ��� �� ������ " << endl;
					break;
				}
				else
				{
					cout << "������ ������� ������" << endl;
					spis = 0;
					obj.clear();
					break;

				}
			case 11:
				if (spis == 0)
				{
					cout << "������ ��� �� ������ " << endl;
					break;
				}
				else
				{
					cout << "������� �����";
					vvod = 1;
					while (vvod)
					{
						try
						{
							insert(index);
							vvod = 0;
						}
						catch (Exp_vvod& error)
						{
							error.Show();
							cin.clear();
							cin.ignore(10, '\n');

						}
					}
					cout << "������� ���������� �������� ������";
					vvod = 1;
					while (vvod)
					{
						try
						{
							data.input();
							vvod = 0;
						}
						catch (Exp_vvod& error)
						{
							error.Show();
							cin.clear();
							cin.ignore(10, '\n');

						}
					}
					obj.insert(data, index);
					break;
				}
			case 12:
				if (obj.GetSize() == 0)
				{
					cout << "���� ������" << endl;
					break;
				}
				f.Add(obj);
				break;
			case 13:
				obj.clear();
				f.Read(obj);
				if (obj.GetSize() == 0)
				{
					cout << "���� ������" << endl;
					break;
				}
				 for(int k=0;k<obj.GetSize();k++)
					obj[k].output();
				 break;
			case 14:
				ft.OpenText();
				obj.clear();
				ft.Readtext(obj);
				if (obj.GetSize() == 0)
				{
					cout << "���� ������"<<endl;
					break;
				}
				for (int k = 0; k < obj.GetSize(); k++)
					obj[k].output();
				ft.CloseText();
				break;
			case 15:
				if (obj.GetSize() == 0)
				{
					cout << "���� ������"<<endl;
					break;
				};
				ft.OpenText();
				ft.Addtext(obj);
				ft.CloseText();
				break;
			default:
				break;
			}
			system("pause");
			system("cls");
		} while (choose);
	
}



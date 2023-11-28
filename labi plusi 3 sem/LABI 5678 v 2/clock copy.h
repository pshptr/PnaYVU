#pragma once
#include <iostream>
#include <iomanip>
#include "conio.h"
#include <locale.h>
#define LEN 20								//����� ������
#define MAS_LEN 5							//������ �������
using namespace std;

//bool str_compare(char*, char*);				//������� ��������� �����

class Clock {		//����� ������� �����
protected:
	char name[20];							//�������� �����
	double cost;							//��������� �����
public:
	virtual int class_name() { return 0; }	//������������� ������
	Clock() {								//����������� �� ���������
		name[0] = '\0';
		cost = 0;
	}
	Clock(char* name, double cost) {		//����������� � �����������
		strcpy_s(this->name, 20, name);
		//str_copy(name, this->name);//�������� �����
		this->cost = cost;						//���������
	}
	//����� ���������
	void setCost(double cost);
	void setName(char* name);
	double getCost();			//��������� ���������
	char* getName();

	virtual void redact();
	//��������  �����
	friend istream& operator>>(istream& in, Clock& clock); 
	
	//�������� ������
     friend ostream& operator<<(ostream& out, Clock& clock);

	 virtual void operator= (Clock& clock);
};

////�������� �����
//istream& operator>>(istream& in, Clock& clock) {
//	cout << endl << "��������:";
//	in >> clock.name;						//����� ��������
//	cout << "���������:";
//	in >> clock.cost;						//���� ���������
//	return in;
//}

////�������� ������
//ostream& operator<<(ostream& out, const Clock clock) 

////������� ����������� ������
//void str_copy(char* first, char* second) {
//	int i = 0;
//	for (i = 0; first[i] != '\0'; i++)		//����������� ����������� ��������
//		second[i] = first[i];
//	second[i] = '\0';						//����� ������
//}

//������ ��������� �����
//bool str_compare(char* str1, char* str2) {
//	int i = 0;
//	//������������ ��������� �����
//	while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0') i++;
//	if (str1[i] == '\0' && str2[i] == '\0') return true;	//��� ������ ��������
//	else return false;						//����� ������ �� �����
//}


#pragma once
#include <iostream>
#include <iomanip>
#include "conio.h"
#include <locale.h>
#define LEN 20								//длина строки
#define MAS_LEN 5							//размер массива
using namespace std;

//bool str_compare(char*, char*);				//функция сравнения строк

class Clock {		//класс обычных часов
protected:
	char name[20];							//название часов
	double cost;							//стоимость часов
public:
	virtual int class_name() { return 0; }	//идентификатор класса
	Clock() {								//конструктор по умолчанию
		name[0] = '\0';
		cost = 0;
	}
	Clock(char* name, double cost) {		//конструктор с параметрами
		strcpy_s(this->name, 20, name);
		//str_copy(name, this->name);//название часов
		this->cost = cost;						//стоимость
	}
	//смена стоимости
	void setCost(double cost);
	void setName(char* name);
	double getCost();			//получение стоимости
	char* getName();

	virtual void redact();
	//оператор  ввода
	friend istream& operator>>(istream& in, Clock& clock); 
	
	//оператор вывода
     friend ostream& operator<<(ostream& out, Clock& clock);

	 virtual void operator= (Clock& clock);
};

////оператор ввода
//istream& operator>>(istream& in, Clock& clock) {
//	cout << endl << "Название:";
//	in >> clock.name;						//ввода названия
//	cout << "Стоимость:";
//	in >> clock.cost;						//ввод стоимости
//	return in;
//}

////оператор вывода
//ostream& operator<<(ostream& out, const Clock clock) 

////функция копирования строки
//void str_copy(char* first, char* second) {
//	int i = 0;
//	for (i = 0; first[i] != '\0'; i++)		//циклическое копирование символов
//		second[i] = first[i];
//	second[i] = '\0';						//конец строки
//}

//фнкция сравнения строк
//bool str_compare(char* str1, char* str2) {
//	int i = 0;
//	//посимвольное сравнения строк
//	while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0') i++;
//	if (str1[i] == '\0' && str2[i] == '\0') return true;	//обе строки окончены
//	else return false;						//иначе строки не равны
//}


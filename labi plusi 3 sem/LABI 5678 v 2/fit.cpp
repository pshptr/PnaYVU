#include "fit.h"

void FitClock::  setSpeed(int speed) {										//изменить скорость
	this->speed = speed;
}
int FitClock:: getSpeed() { return speed; }								//получить скорость

void FitClock:: operator= (FitClock& clock) {								//оператор присваивани€
	if (this == &clock) return;										//проверка на самоприсваивание
	strcpy_s(this->name, 20, clock.name);													//конец строки
	cost = clock.cost;												//копирование стоимости
	charge = clock.charge;											//копирование зар€да батареи
	speed = clock.speed;											//копирование скорости
}
void FitClock:: redact() {													//редактирование часов
	system("cls");
	cout << *this;													//вывод информации о часах
	cout << "–едактировать?";
	if (_getch() != '1') return;									//отказ редактировани€
	bool more = true;												//продолжать редактирование
	while (more) {
		system("cls");
		cout << "1 - изменить название" << endl
			<< "2 - изменить стоимость" << endl
			<< "3 - изменить зар€д аккумул€тора" << endl
			<< "4 - изменить количество шагов в минуту" << endl
			<< "0 - окончить редактирование" << endl;
		switch (_getch()) {											//выбор действи€
		case '1':													//изменить название
			cout << "Ќовое название:";
			char new_name[LEN];										//новое название
			rewind(stdin);									//очистка буфера
			cin.getline(new_name, LEN);					//ввод нового названи€
			this->setName(new_name);								//смена названи€
			break;
		case '2':													//изменить стоимость
			cout << "Ќова€ стоимость:";
			double new_cost;										//нова€ цена
			cin >> new_cost;										//ввол новой цены
			this->setCost(new_cost);								//смена цены
			break;
		case '3':													//изменить зар€д
			cout << "Ќовый зар€д аккумул€тора:";
			int new_charge;											//новый зар€д
			cin >> new_charge;										//ввод нового зар€да
			this->setCharge(new_charge);							//смена зар€да
			break;
		case '4':													//изменить скорость
			cout << "Ќовое количество шагов в минуту:";
			int new_speed;											//нова€ скорость 
			cin >> new_speed;										//ввод новойс корости
			this->setSpeed(new_speed);								//смена скорости
			break;
		case '0':													//конец редактировани€
			more = false;
			break;
		}
	}
	cout << *this;
}
istream& operator>> (istream& in, FitClock& clock) {
	cout << endl << "Ќазвание:";
	in >> clock.name;												//ввод названи€
	cout << "—тоимость:";
	in >> clock.cost;												//ввод стоимости
	cout << "«ар€д батареи:";
	in >> clock.charge;												//ввод зар€да батареи
	cout << "—корость(шаг/мин):";
	in >> clock.speed;												//ввод скорости
	//steps = ...
	return in;
};
ostream& operator<< (ostream& out, FitClock& clock)
{
	out << setw(LEN) << left << clock.name << setw(5) << left << clock.cost << setw(6) << left << clock.charge << clock.speed << endl;
	return out;
}


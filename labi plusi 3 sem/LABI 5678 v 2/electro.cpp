#include "electro.h"

void ElectroClock:: setCharge(int charge) { this->charge = charge; }	//изменить заряд батареи
double ElectroClock::  getCharge() { return charge; }					//получить заряяд батареи
void ElectroClock:: redact() {											//редактирование
	system("cls");
	cout << *this;											//вывод часов
	cout << "Редактировать?";
	if (_getch() != '1') return;							//отказ редактирования
	bool more = true;										//продолжать редактирование
	while (more) {
		system("cls");
		cout << "1 - изменить название" << endl
			<< "2 - изменить стоимость" << endl
			<< "3 - изменить заряд аккумулятора" << endl
			<< "0 - окончить редактирование" << endl;
		switch (_getch()) {									//выбор действия
		case '1':											//изменить название
			cout << "Новое название:";
			char new_name[LEN];								//новое название
			rewind(stdin);							//очистка буфера
			cin.getline(new_name, LEN);			//ввод строки
			this->setName(new_name);						//смена названия
			break;
		case '2':											//изменить стоимость
			cout << "Новая стоимость:";
			double new_cost;								//новая цена
			cin >> new_cost;								//ввод новой цены
			this->setCost(new_cost);						//смена цены
			break;
		case '3':											//изменить заряд
			cout << "Новый заряд аккумулятора:";
			int new_charge;									//новый заряд
			cin >> new_charge;								//ввод заряда
			this->setCharge(new_charge);					//смена заряда
			break;
		case '0':											//конец редактирования
			more = false;
			break;
		}
	}
	cout << *this;
}

//оператор ввода
istream& operator>>(istream& in, ElectroClock& clock) {
	cout << endl << "Название:";
	in >> clock.name;											//ввод названия
	cout << "Стоимость:";
	in >> clock.cost;											//ввод стоимости
	cout << "Заряд батареи:";
	in >> clock.charge;											//ввод заряда батареи
	return in;
}
//оператор вывода
ostream& operator<<(ostream& out, ElectroClock& clock) {
	out << setw(LEN) << left << clock.name << setw(5) << left << clock.cost << setw(6) << left << clock.charge << endl;
	return out;
}
void ElectroClock:: operator= (ElectroClock& clock) {					//оператор присваивания
	if (this == &clock) return;								//проверка на самоприсваивание
	strcpy_s(this->name, 20, clock.name);									//конец строки
	cost = clock.cost;										//копирование стоимости
	charge = clock.charge;									//копирование заряда батареи
}

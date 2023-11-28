#include "wallclock.h"

void WallClock:: setPendulum(int pendulum) { this->pendulum = pendulum; }	//изменить длину ма€тника
int WallClock::getPendulum() { return pendulum; }							//получить длину ма€тника
void WallClock:: redact() {													//редактирование 
	system("cls");
	cout << *this;												//вывод информации
	cout << "–едактировать?1 - да , иначе - нет";
	if (_getch() != '1') return;								//отказ редактировани€
	bool more = true;											//продолжать редактирование
	while (more) {
		system("cls");
		cout << "1 - изменить название" << endl
			<< "2 - изменить стоимость" << endl
			<< "3 - изменить вес" << endl
			<< "4 - изменить длину ма€тника" << endl
			<< "0 - окончить редактирование" << endl;
		switch (_getch()) {										//выбор действи€
		case '1':												//изменить название
			cout << "Ќовое название:";
			char new_name[LEN];									//новое название
			rewind(stdin);								//очистка буфера
			cin.getline(new_name, LEN);				//ввод нового названи€
			this->setName(new_name);							//смена названи€
			break;
		case '2':												//изменить стоимость
			cout << "нова€ стоимость:";
			double new_cost;									//нова€ цена
			cin >> new_cost;									//ввод новой цены
			this->setCost(new_cost);							//смена цены
			break;
		case '3':												//изменить вес
			cout << "Ќовый вес:";
			int new_weight;										//новый вес
			cin >> new_weight;									//ввод нового веса
			this->setWeight(new_weight);						//смена веса
			break;
		case '4':												//изменить ма€тник
			cout << "Ќова€ длина м€тника:";
			int new_pendulum;									//нова€ длина ма€тника
			cin >> new_pendulum;								//ввод новой длиныы
			this->setPendulum(new_pendulum);					//смена длины ма€тника
			break;
		case '0':												///конец редактировани€
			more = false;
			break;
		}
	}
	cout << *this;
}

//оператор ввода
istream& operator>> (istream& in, WallClock& clock) {
	cout << endl << "Ќазвание:";
	in >> clock.name;													//ввод названи€
	cout << "—тоимость:";
	in >> clock.cost;													//ввод стоимости
	cout << "¬ес:";
	in >> clock.weight;													//ввод веса
	cout << "ƒлина ма€тника:";
	in >> clock.pendulum;												//ввод длины ма€тника
	return in;
}
//оператор вывода
ostream& operator<< (ostream& out, WallClock& clock) {
	out << setw(LEN) << left << clock.name << setw(5) << left << clock.cost << setw(6) << left << clock.weight << clock.pendulum << endl;
	return out;
}

void WallClock:: operator= (WallClock& clock) {								//оператор присваивани€
	if (this == &clock) return;										//проверка на самоприсваивание
	strcpy_s(this->name, 20, clock.name);
	cost = clock.cost;												//копирование стоимости
	weight = clock.weight;											//копирование веса
	pendulum = clock.pendulum;										//копирование длин ма€тника
}

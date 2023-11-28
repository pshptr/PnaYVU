#include "mehclock.h"

void MechClock:: setWeight(int weight) { this->weight = weight; }	//изменить вес
int MechClock:: getWeight() { return weight; }						//получить вес

 istream& operator>> (istream& in, MechClock& clock) {
	cout << endl << "Ќазвание:";
	in >> clock.name;											//ввод названи€
	cout << "—тоимость:";
	in >> clock.cost;											//ввод стоимости
	cout << "¬ес:";
	in >> clock.weight;											//ввод веса
	return in;
}
 ostream& operator<< (ostream& out, MechClock& clock) {
	out << setw(LEN) << left << clock.name << setw(5) << left << clock.cost << clock.weight << endl;
	return out;
}

void MechClock:: redact() {											//редактирование
	system("cls");
	cout << *this;										//вывод информации
	cout << "–едактировать?";
	if (_getch() != '1') return;						//отказ редактировани€
	bool more = true;									//продолжать редактирование
	while (more) {
		system("cls");
		cout << "1 - изменить название" << endl
			<< "2 - изменить стоимость" << endl
			<< "3 - изменить вес" << endl
			<< "0 - окончить редактирование" << endl;
		switch (_getch()) {									//выбор действи€
		case '1':											//изменить название
			cout << "новое название:";
			char new_name[LEN];								//новое название
			rewind(stdin);							//очистка буфера
			cin.getline(new_name, LEN);			//ввод нового названи€
			this->setName(new_name);						//смена названи€
			break;
		case '2':											//изменить стоимость
			cout << "Ќова€ стоимость:";
			double new_cost;								//нова€ цена
			cin >> new_cost;								//ввод новой цены
			this->setCost(new_cost);						//смена цены
			break;
		case '3':											//изменить вес
			cout << "Ќовый вес:";
			int new_weight;									//новый вес
			cin >> new_weight;								//ввод нового веса
			this->setWeight(new_weight);					//смена веса
			break;
		case '0':											//конец редактировани€
			more = false;
			break;
		}
	}
	cout << *this;
}

void MechClock:: operator= (MechClock& clock) {						//оператор присваивани€
	if (this == &clock) return;								//провека на савоприсваиваyb t										//конец строки
	strcpy_s(this->name, 20, clock.name);
	cost = clock.cost;										//копирование стоимости
	weight = clock.weight;									//копирование веса
}

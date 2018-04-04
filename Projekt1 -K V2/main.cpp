#include <iostream>
#include <climits>
#include <vector>
#include "Liczba.h"
using  namespace std;

Liczba wczytajLiczbe() {
	unsigned long long pierwsza[N], n;
	char znak;
	///////
	/*cin >> znak;
	while (znak != '+' && znak != '-') {
		cout << "Podaj + lub -" << endl;
		cin >> znak;
	}
	for (int i = N-1; i >= 0; --i) {
		while (!(cin >> n)) {
			cout << "Blad podaj jeszcze raz!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		pierwsza[i] = n;
	}*/
	//////
	bool rep = true;
	while (rep) {
		cin >> znak;
		if (znak != '+' && znak != '-') {
			cout << "Blad, podaj jeszcze raz!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		for (int i = N - 1; i >= 0; --i) {
			if (!(cin >> n)) {
				cout << "Blad, podaj jeszcze raz!" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				rep=true;
				break;
			}
			pierwsza[i] = n;
			rep = false;
		}
		
	}
	Liczba li(pierwsza);
	if (znak == '-') {
		Liczba test;
		test.minus = true;
		if (test == li) return Liczba();
		li.minus = true;
	}
	return li;
}

int main() {
	string wczytane, znak;
	int opcja, num1, num2;
	long long liczba;
	Liczba l1, l2;
	while (true) {
		cout << "Operacje na " << N << " bitach." << endl;
		cout << "MENU\tWybierz jeden z numerow:" << endl;
		cout << "1. Dodaj liczby" << endl;
		cout << "2. Odejmij liczby" << endl;
		cout << "3. Pomnoz liczby" << endl;
		cout << "4. Podziel liczby" << endl;
		cout << "5. Porownaj liczby" << endl;
		cout << "0. Zamknij" << endl;

		while (!(cin >> opcja)) {
			cout << "Blad podaj jeszcze raz!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
		if (opcja == 1) { //dodanie
			cout << "Dodawanie" << endl;
			cout << "Podaj pierwsza liczbe. ";
			l1 = wczytajLiczbe();
			cout << "Podaj druga liczbe. ";
			l2 = wczytajLiczbe();
			cout << l1 << " + (" << l2 << ") = " << l1 + l2 << endl;
		}
		else if (opcja == 2) { //odjecie
			cout << "Odejmowanie" << endl;
			cout << "Podaj pierwsza liczbe. ";
			l1 = wczytajLiczbe();
			cout << "Podaj druga liczbe. ";
			l2 = wczytajLiczbe();
			cout << l1 << " + (" << l2 << ") = " << l1 - l2 << endl;
		}
		else if (opcja == 3) { //monozenie
			cout << "Mnozenie" << endl;
			cout << "Podaj pierwsza liczbe. ";
			l1 = wczytajLiczbe();
			cout << "Podaj druga liczbe. ";
			l2 = wczytajLiczbe();
			cout << l1 << " + (" << l2 << ") = " << l1 * l2 << endl;
		}
		else if (opcja == 4) { //dzielenie
			cout << "Dzielenie" << endl;
			cout << "Podaj pierwsza liczbe. ";
			l1 = wczytajLiczbe();
			cout << "Podaj druga liczbe. ";
			l2 = wczytajLiczbe();
			cout << l1 << " + (" << l2 << ") = " << l1 / l2 << endl;
		}
		else if (opcja == 5) { //porowananie
			cout << "Porownywanie" << endl;
			cout << "Podaj pierwsza liczbe. ";
			l1 = wczytajLiczbe();
			cout << "Podaj druga liczbe. ";
			l2 = wczytajLiczbe();
			cout << l1;
			if (l1 > l2)
				cout << " > ";
			else if (l1 < l2)
				cout << " < ";
			else if (l1 == l2)
				cout << " == ";
			cout << l2 << endl;
		}
		else if (opcja == 0) { //zamknij program
			break;
		}
		else { //blad wprowadzania
			cout << "Wprowadz poprawny numer opcji!!" << endl;
		}
	}
	//system("pause");
	return 0;
}
//
// Created by Krzy on 22.03.2018.
//

#include "Liczba.h"
#include <climits>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

const string maxullstring = to_string(ULLONG_MAX);
const unsigned long long int maxull = ULLONG_MAX;

Liczba::Liczba() {
	for (int i = 0; i < N; ++i)
		pole[i] = 0;
	minus = false;
}
Liczba::Liczba(long long int w) {
	minus = w < 0;
	for (int i = 0; i < N; ++i) //zerowanie tablicy
		pole[i] = 0;
	pole[0] = static_cast<unsigned long long int>(w);
}
Liczba::Liczba(string napis) {

}
Liczba::Liczba(unsigned long long int *tablica) {
	this->minus = false;
	for (int i = 0; i < N; i++) 
		this->pole[i] = tablica[i];
}
Liczba &Liczba::operator=(const Liczba &p) {
	this->minus = p.minus;
	for (int i = 0; i < N; i++)
		this->pole[i] = p.pole[i];
	return *this;
}

///operatory arytmatyczne
Liczba operator+(const Liczba &l, const Liczba &p) {
	Liczba tmp;
	unsigned long long carry = 0, suma = 0;
	if ((!l.minus && !p.minus) || (l.minus && p.minus)) { //obydwie dodatnie lub ujemne
		tmp.minus = l.minus;
		for (int i = 0; i < N; ++i) {
			suma = l.pole[i] + p.pole[i];
			suma += carry;
			if (suma < max(l.pole[i], p.pole[i]))
				carry = 1;
			else
				carry = 0;
			//suma+=carry;
			tmp.pole[i] = suma;
		}
	}
	else if (!l.minus && p.minus) { //lewa dodatnia, prawa minus
		Liczba pzast = p;
		pzast.minus = false;
		tmp = l - p;
	}
	else if (l.minus && !p.minus) { //lewa minus, prawa dodatnia
		Liczba lzast = l;
		lzast.minus = false;
		tmp = p - l;
	}

	return tmp;
}
Liczba operator-(const Liczba &l, const Liczba &p) {
	Liczba tmp;
	unsigned long long tab[N];
	//cout << "odejm" << endl;
	if ((!l.minus && !p.minus && l.modul() == p.modul()) || (l.minus && p.minus && l.modul() == p.modul()) || (l.modul() == p.modul() && l.modul() == tmp)) {
		return tmp;
	}
	else if ((!l.minus && !p.minus && l.modul() > p.modul()) || (l.minus && p.minus && l.modul() > p.modul())) {
		//cout << "++ ml>mp || -- ml>mp" << endl;
		tmp.minus = l.minus;
		int c = 0;
		for (int i = 0; i < N; ++i) {
			tab[i] = l.pole[i] - p.pole[i] + c;
			if (l.pole[i] <= p.pole[i] && p.pole[i]!=0) {
				tab[i] += ULLONG_MAX+1;
				c = -1;
			}
			else
				c = 0;
		}
		for (int i = 0; i < N; ++i) {
			tmp.pole[i] = tab[i];
		}
		return tmp;
	}
	else if (!l.minus && !p.minus && l.modul() < p.modul()) {
		//cout << "++, ml < mp" << endl;
		tmp = p - l;
		tmp.minus = true;
		return tmp;
	}
	else if (l.minus && p.minus && l.modul() < p.modul()) {
		//cout << "-- ml<mp" << endl;
		Liczba pzast = p;
		pzast.minus = false;
		tmp = pzast + l;
		tmp.minus = false;
		return tmp;
	}
	else if (l.minus && !p.minus) {
		//cout << "-+" << endl;
		Liczba lzast = l;
		lzast.minus = false;
		tmp = lzast + p;
		tmp.minus = true;
		return tmp;
	}
	else if (!l.minus && p.minus) {
		//cout << "+-" << endl;
		Liczba pzast = p;
		pzast.minus = false;
		tmp = l + pzast;
		return tmp;
	}
}
Liczba operator*(const Liczba &l, const Liczba &p) {
	return Liczba();
}
Liczba operator/(const Liczba &l, const Liczba &p) {
	Liczba tmp;
	vector <unsigned long long> tab;
	Liczba dzielnik = p.modul();
	Liczba dzielna = l.modul();
	if (dzielnik == tmp) {
		cout << "Nie mozna dzielic przez 0!!!!!" << endl;
		return tmp;
	}
	if (l.liczbaZnaczacych() < p.liczbaZnaczacych())
		return tmp;
	dzielnik = dzielnik << (dzielna.liczbaZnaczacych() - dzielnik.liczbaZnaczacych());
	int iter = dzielna.liczbaZnaczacych() - 1;
	unsigned long long ilerazy;
	while (true) {
		if (dzielna > dzielnik || dzielna == dzielnik) {
			ilerazy = dzielna.pole[iter] / dzielnik.pole[iter];
			tab.push_back(ilerazy);
			dzielna = dzielna - dzielnik;
			dzielnik = dzielnik >> 1;
		}
		else {
			tab.push_back(0);
			dzielnik = dzielnik >> 1;
		}
		iter--;
		if (dzielnik < p.modul())
			break;
	}
	reverse(tab.begin(), tab.end());
	for (int i = 0; i < tab.size(); i++) {
		tmp.pole[i] = tab[i];
	}
	/////////
	if (l.minus != p.minus)
		tmp.minus = true;
	else
		tmp.minus = false;
	return tmp;
}

///operatory porownywania
bool operator>(const Liczba &l, const Liczba &p) {
	if (l.minus && !p.minus)
		return false;

	for (int i = N - 1; i >= 0; i--) {
		if (l.pole[i] > p.pole[i])
			return true;
		else if (l.pole[i] < p.pole[i])
			return false;
	}
	return false;
}
bool operator<(const Liczba &l, const Liczba &p) {
	if (!l.minus && p.minus)
		return false;
	for (int i = N - 1; i >= 0; i--) {
		if (l.pole[i] < p.pole[i])
			return true;
		else if (l.pole[i] > p.pole[i])
			return false;
	}
	return false;
}
bool operator==(const Liczba &l, const Liczba &p) {
	if (l.minus != p.minus) return false;
	for (int i = N - 1; i >= 0; --i) {
		if (l.pole[i] != p.pole[i])
			return false;
	}
	return true;
}
ostream &operator<<(ostream &out, const Liczba &p) {
	if (p.minus)
		out << "- ";
	else
		out << "+ ";
	for(int i=N-1; i>=0; i--){
	out << to_string(p.pole[i]) << " ";
	}
	//out << p.pole[1] << " " << p.pole[0];
	return  out;
}
Liczba operator<<(const Liczba & l, int ilosc)
{
	Liczba tmp;
	for (int i = N - 1 - ilosc; i >= 0; i--) {
		tmp.pole[i + ilosc] = l.pole[i];
	}
	return tmp;
}
Liczba operator >> (const Liczba & l, int ilosc)
{
	Liczba tmp;
	for (int i = 0; i < N - ilosc; i++) {
		tmp.pole[i] = l.pole[i + ilosc];
	}
	return tmp;
}
Liczba Liczba::modul()  const{
	Liczba tmp = *this;
	tmp.minus = false;
	return  tmp;
}

int Liczba::liczbaZnaczacych() const
{
	int ilosc = 0;
	for (int i = N - 1; i >= 0; i--, ilosc++) {
		if (this->pole[i] != 0)
			break;
	}
	return N - ilosc;
}

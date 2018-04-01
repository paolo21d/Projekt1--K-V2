//
// Created by Krzy on 22.03.2018.
//

#include "Liczba.h"
#include <climits>
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

}
Liczba &Liczba::operator=(const Liczba &p) {
	//return <#initializer#>;
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
	else if (!l.minus && p.minus) { //lewa dodatnia, prawa ujemna
		Liczba pzast = p;
		pzast.minus = false;
		tmp = l - p;
	}
	else if (l.minus && !p.minus) { //lewa ujemna, prawa dodatnia
		Liczba lzast = l;
		lzast.minus = false;
		tmp = p - l;
	}

	return tmp;
}
Liczba operator-(const Liczba &l, const Liczba &p) {
	return Liczba();
}
Liczba operator*(const Liczba &l, const Liczba &p) {
	return Liczba();
}
Liczba operator/(const Liczba &l, const Liczba &p) {
	return Liczba();
}

///operatory porownywania
bool operator>(const Liczba &l, const Liczba &p) {
	if (l.minus && !p.minus)
		return  false;
	for (int i = N - 1; i >= 0; i--) {
		if (l.pole[i]<p.pole[i])
			return false;
	}
	return true;
}
bool operator<(const Liczba &l, const Liczba &p) {
	if (!l.minus && p.minus)
		return  false;
	for (int i = N - 1; i >= 0; i--) {
		if (l.pole[i]>p.pole[i])
			return false;
	}
	return true;
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
	/*for(int i=N-1; i>=0; i--){
	out << to_string(p.pole[i]) << " ";
	}*/
	out << p.pole[1] << " " << p.pole[0];
	return  out;
}
Liczba Liczba::modul() {
	Liczba tmp = *this;
	tmp.minus = false;
	return  tmp;
}
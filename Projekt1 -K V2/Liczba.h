//
// Created by Krzy on 22.03.2018.
//

#ifndef KRZYSIEK_LICZBA_H
#define KRZYSIEK_LICZBA_H
#define N 4
#include <iostream>
#include <string>

class Liczba {
public:
	unsigned long long int pole[N];
	bool minus;
public:
	Liczba();
	Liczba(long long w);
	Liczba(unsigned long long tablica[N]);
	Liczba &operator=(const Liczba &p);

	Liczba modul() const;

	friend Liczba operator+(const Liczba &l, const Liczba &p);
	friend Liczba operator-(const Liczba &l, const Liczba &p);
	friend Liczba operator*(const Liczba &l, const Liczba &p);
	friend Liczba operator/(const Liczba &l, const Liczba &p);

	friend bool operator>(const Liczba &l, const Liczba &p);
	friend bool operator<(const Liczba &l, const Liczba &p);
	friend bool operator==(const Liczba &l, const Liczba &p);

	friend std::ostream &operator<<(std::ostream &out, const Liczba &p);

	friend Liczba operator<< (const Liczba &l, int ilosc);
	friend Liczba operator>> (const Liczba &l, int ilosc);

	friend Liczba mnozNaturalne(const Liczba &l, unsigned long long nat);
	int liczbaZnaczacych() const;

};


#endif //KRZYSIEK_LICZBA_H
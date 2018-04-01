#include <iostream>
#include <climits>
#include "Liczba.h"
using  namespace std;
int main() {
	//std::cout << ULLONG_MAX+ULLONG_MAX << std::endl;
	Liczba l(ULLONG_MAX), p(ULLONG_MAX);
	Liczba suma = l + p;
	//cout<<suma.pole[1]<<" "<<suma.pole[0];
	//cout<<suma;
	return 0;
}
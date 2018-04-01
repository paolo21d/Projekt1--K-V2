#include <iostream>
#include <climits>
#include "Liczba.h"
using  namespace std;
int main() {
	//std::cout << ULLONG_MAX+ULLONG_MAX << std::endl;
	Liczba l(LLONG_MAX), p(LLONG_MAX);
	Liczba suma;
	/*for (int i = 0; i < 400; i++)
		suma = suma + l;
	*/
	Liczba s1(l + l + l + l + l + l + l + l + l + l);
	suma = (s1 )/ Liczba(2);
	//cout<<suma.pole[1]<<" "<<suma.pole[0];
	cout<<s1<<" ::: "<<suma;
	//cout << suma;
	system("pause");
	return 0;
}
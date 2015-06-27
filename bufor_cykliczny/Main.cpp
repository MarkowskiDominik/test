#define _SCL_SECURE_NO_WARNINGS

#include <cstdlib>
#include <iostream>
#include "Buffor.h"

using namespace std;

int main()
{
	cout << boolalpha;

	cout << "\nkonstruktor domyslny\n";
	Buffor<int> bufor1;
	cout << bufor1.get_size() << " " << bufor1.get_count() << " " << bufor1.empty() << " " << bufor1.full();
	cout << "\nkonstruktor z rozmiarem\n";
	Buffor<int> bufor2(3);
	cout << bufor2.get_size() << " " << bufor2.get_count() << " " << bufor2.empty() << " " << bufor2.full();
	cout << "\nkonstruktor kopiujacy\n";
	Buffor<int> bufor3(bufor2);
	cout << bufor3.get_size() << " " << bufor3.get_count() << " " << bufor3.empty() << " " << bufor3.full();
	cout << "\nkonstruktor z lista inicjalizacyjna\n";
	Buffor<int> bufor4{ 1, 2, 3, 4 };
	cout << bufor4.get_size() << " " << bufor4.get_count() << " " << bufor4.empty() << " " << bufor4.full();
	cout << "\nkonstruktor z przenoszacy\n";
	Buffor<int> bufor5(std::move(bufor4));
	cout << bufor5.get_size() << " " << bufor5.get_count() << " " << bufor5.empty() << " " << bufor5.full();
	
	
	system("PAUSE");
	return 0;
}
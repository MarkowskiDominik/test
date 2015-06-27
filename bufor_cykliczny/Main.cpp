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
	
	
	system("PAUSE");
	return 0;
}
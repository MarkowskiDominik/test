#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <memory> 
#include <chrono>
#include <functional>
#include <iomanip>

using namespace std;
using namespace std::chrono; 
using namespace std::placeholders;

class A
{
	string ap = "a-";
	string xp = "xa-";
public:
	string a = "a";
	string x = "xa";

	A(){ cout << "konstruktor A\n"; }
	~A(){ cout << "destruktor A\n"; }

	void func1(){ cout << "funkcja A\n"; }
	void virtual func2(){ cout << "funkcja wirtualna A\n"; }

	string get_a1(){ return a; }
	string virtual get_a2(){ return a; }

	string get_ap1(){ return ap; }
	string virtual get_ap2(){ return ap; }

	string get_x1(){ return x; }
	string virtual get_x2(){ return x; }

	string get_xp1(){ return xp; }
	string virtual get_xp2(){ return xp; }
};

class B : public A
{
	string bp = "b-";
	string xp = "xb-";
public:
	string b = "b";
	string x = "xb";

	B(){ cout << "konstruktor B\n"; }
	~B(){ cout << "destruktor B\n"; }

	void func1(){ cout << "funkcja B\n"; }
	void virtual func2(){ cout << "funkcja wirtualna B\n"; }

	string get_b1(){ return b; }
	string virtual get_b2(){ return b; }

	string get_bp1(){ return bp; }
	string virtual get_bp2(){ return bp; }

	string get_x1(){ return x; }
	string virtual get_x2(){ return x; }

	string get_xp1(){ return xp; }
	string virtual get_xp2(){ return xp; }
};

class C : public B
{
	string cp = "c-";
	string xp = "xc-";
public:
	string c = "c";
	string x = "xc";

	C(){ cout << "konstruktor C\n"; }
	~C(){ cout << "destruktor C\n"; }

	void func1(){ cout << "funkcja C\n"; }
	void virtual func2(){ cout << "funkcja wirtualna C\n"; }

	string get_c1(){ return c; }
	string virtual get_c2(){ return c; }

	string get_cp1(){ return cp; }
	string virtual get_cp2(){ return cp; }

	string get_x1(){ return x; }
	string virtual get_x2(){ return x; }

	string get_xp1(){ return xp; }
	string virtual get_xp2(){ return xp; }
};

int count(int howMany){
	auto counter = 0;
	while (howMany-->0)
	{
		for (int i = 0; i<1000; i++)
			if (counter % 2 == 0)
				counter++;
			else
				counter--;
	}
	return counter;
}

void f(int n1, int n2, int n3, const int& n4, int n5)
{
	cout << n1 << " " << n2 << " " << n3 << " " << n4 << " " << n5 << endl;
}

shared_ptr<string> pNico(new string("nico"), [](string *p)
{
	cout << "delete " << *p << endl;
	delete p;
});

int main()
{
	/*
	cout << "zaawansowany test dziedziczenia\n";

	cout << "\n\tklasa A\n";
	A* a = new A();
	a->func1();
	a->func2();
	cout << a->get_a1() << endl;
	cout << a->get_a2() << endl;
	cout << a->get_ap1() << endl;
	cout << a->get_ap2() << endl;
	cout << a->get_x1() << endl;
	cout << a->get_x2() << endl;
	cout << a->get_xp1() << endl;
	cout << a->get_xp2() << endl;
	a->~A();

	cout << "\n\tklasa B\n";
	B* b = new B();
	b->func1();
	b->func2();
	cout << b->get_b1() << endl;
	cout << b->get_b2() << endl;
	cout << b->get_bp1() << endl;
	cout << b->get_bp2() << endl;
	cout << b->get_x1() << endl;
	cout << b->get_x2() << endl;
	cout << b->get_xp1() << endl;
	cout << b->get_xp2() << endl;
	b->~B();

	cout << "\n\tklasa C\n";
	C* c = new C();
	c->func1();
	c->func2();
	cout << c->get_c1() << endl;
	cout << c->get_c2() << endl;
	cout << c->get_cp1() << endl;
	cout << c->get_cp2() << endl;
	cout << c->get_x1() << endl;
	cout << c->get_x2() << endl;
	cout << c->get_xp1() << endl;
	cout << c->get_xp2() << endl;
	c->~C();
	
	cout << "\n\twskaznik A, klasa B\n";
	A* a_b = new B();
	a_b->func1();
	a_b->func2();
	cout << a_b->get_a1() << endl;
	cout << a_b->get_a2() << endl;
	cout << a_b->get_ap1() << endl;
	cout << a_b->get_ap2() << endl;
	cout << a_b->get_x1() << endl;
	cout << a_b->get_x2() << endl;
	cout << a_b->get_xp1() << endl;
	cout << a_b->get_xp2() << endl;
	a_b->~A();

	cout << "\n\twskaznik A, klasa C\n";
	A* a_c = new C();
	a_c->func1();
	a_c->func2();
	cout << a_c->get_a1() << endl;
	cout << a_c->get_a2() << endl;
	cout << a_c->get_ap1() << endl;
	cout << a_c->get_ap2() << endl;
	cout << a_c->get_x1() << endl;
	cout << a_c->get_x2() << endl;
	cout << a_c->get_xp1() << endl;
	cout << a_c->get_xp2() << endl;
	a_c->~A();

	cout << "\n\twskaznik B, klasa C\n";
	B* b_c = new C();
	b_c->func1();
	b_c->func2();
	cout << b_c->get_a1() << endl;
	cout << b_c->get_a2() << endl;
	cout << b_c->get_ap1() << endl;
	cout << b_c->get_ap2() << endl;
	cout << b_c->get_b1() << endl;
	cout << b_c->get_b2() << endl;
	cout << b_c->get_bp1() << endl;
	cout << b_c->get_bp2() << endl;
	cout << b_c->get_x1() << endl;
	cout << b_c->get_x2() << endl;
	cout << b_c->get_xp1() << endl;
	cout << b_c->get_xp2() << endl;
	b_c->~B();

	auto t0 = high_resolution_clock::now();
	int n = 10000;
	n = count(n);
	auto t1 = high_resolution_clock::now();
	cout << "for n=" << n << " time=" << duration_cast<milliseconds>(t1 - t0).count() << " ms\n";
	cout << "data: " << __DATE__ << endl;
	cout << "czas: " << __TIME__ << endl;
	cout << "plik: " << __FILE__ << endl;
	cout << "linia: " << __LINE__ << endl;
	//cout << "funkcja: " << __FUNC__ << endl;

	int tab[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (auto x : tab) cout << x << ", ";
	cout << endl;

	n = 7;
	auto f1 = std::bind(f, _2, _1, 42, std::cref(n), n);
	f1(5, 8, 1001); // 5 jest zwi¹zane z _1, 8 jest zwi¹zane z _2
	*/

	// dwa wspóldzielone wskaŸnikireprezentuj¹ce dwa imiona
	shared_ptr<string> pNico(new string("nico"));
	shared_ptr<string> pJutta(new string("jutta"));
	// popraw zapis imion wielk¹ liter¹
	(*pNico)[0] = 'N';
	pJutta->replace(0, 1, "J");
	// umieœæ wskaŸniki w kontenerze (wielokrotnie)
	vector<shared_ptr<string>> whoMadeCoffee;
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pNico);
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pNico);

	// wypisz wszystkie elementy
	for (auto ptr : whoMadeCoffee) {
		cout << *ptr << " ";
	}
	cout << endl;
	// jeszcze raz zmieñ pisowniê jednego z imion
	*pNico = "Nicolai";
	// ponownie wypisz wszystkie elementy
	for (auto ptr : whoMadeCoffee) {
		cout << *ptr << " ";
	}
	cout << endl;
	// wypisz wewnêtrzne dane wskaŸnika
	cout << "use_count: " << whoMadeCoffee[0].use_count() << endl;

	pNico = nullptr; // usuwamy wi¹zanie dla lokalnej kopii wskaŸnika
	whoMadeCoffee.resize(2); //usuwamy wskaŸniki na "nico" z tabeli
	cout << "po resize" << endl;
	whoMadeCoffee[0] = nullptr;
	whoMadeCoffee[1] = nullptr;
	cout << "use_count: " << pNico.use_count() << endl;
	cout << "use_count: " << pJutta.use_count() << endl;


	bool bVal = true;
	cout << bVal << endl;
	cout << boolalpha << bVal << endl;
	int iVal = -23;
	string str = "abc";
	cout << '"' << iVal << '"' << endl;
	cout << '"' << setw(6) << iVal << '"' << endl;
	cout << '"' << setw(1) << iVal << '"' << endl;
	cout << '"' << setw(6) << setfill('*') << iVal << '"' << endl;
	cout << '"' << setw(6) << iVal << '"' << endl;
	cout << '"' << str << '"' << endl;
	cout << '"' << setw(6) << str << '"' << endl;
	cout << '"' << setw(1) << str << '"' << endl;
	cout << '"' << setw(6) << setfill('*') << str << '"' << endl;
	cout << '"' << setw(6) << str << '"' << endl;
	cout << setfill(' ');
	cout << "left, right, internal" << endl;
	cout << '"' << left << setw(6) << iVal << '"' << endl;
	cout << '"' << right << setw(6) << iVal << '"' << endl;
	cout << '"' << internal << setw(6) << iVal << '"' << endl;
	cout << '"' << left << setw(6) << str << '"' << endl;
	cout << '"' << right << setw(6) << str << '"' << endl;
	cout << '"' << internal << setw(6) << str << '"' << endl;
	cout << '"' << oct << iVal << '"' << endl;
	cout << "iVal=" << iVal << endl;
	iVal = 129;
	cout << '"' << oct << iVal << '"' << endl;
	cout << '"' << dec << iVal << '"' << endl;
	cout << '"' << hex << iVal << '"' << endl;
	double fVal = 123.456;
	cout << "double:" << endl;
	cout << '"' << fVal << '"' << endl;
	cout << '"' << setw(8) << fVal << '"' << endl;
	cout << '"' << setprecision(10) << fVal << '"' << endl;
	// liczba cyfr znacz¹cych
	cout << '"' << setprecision(4) << fVal << '"' << endl;
	// liczba cyfr znacz¹cych
	cout << '"' << setprecision(1) << fVal << '"' << endl;
	
	vector<char> v;
	v.resize(50);
	strcpy(v.data(), "witaj swiecie");
	printf("%s\n", v.data());
	printf("%s\n", &v[0]);


	system("PAUSE");
	return 0;
}
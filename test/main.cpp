#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

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

int main()
{
	cout << "zaawansowany test dziedziczenia\n";
	/*
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
	*/
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

	cout << "test gita";
	system("PAUSE");
	return 0;
}
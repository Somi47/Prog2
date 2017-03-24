#include <iostream>

using namespace std;

class A
{
	int i_adat;
public:
	A( int i = 0 ) : i_adat( i ) { cout << "\tA ctor i_adat=" << i_adat << endl; }
	A( const A &other ) { i_adat = other.i_adat; cout << "\tA copy" << endl; }
	virtual ~A() { cout << "\tA dtor i_adat=" << i_adat << endl; }
};

class C
{
public:
	C() { cout << "\tC ctor" << endl; }
	~C() { cout << "\tC dtor" << endl; }
};

class B : public A
{
	float f_adat;
	C c_adat;
public:
	B( int i = 0, float f = 0 ) : A( i ), f_adat( f ) { cout << "\tB ctor f_adat=" << f_adat << endl; }
	B( const B &other ) : A( other ) { f_adat = other.f_adat; cout << "\tB copy" << endl; }
	~B() { cout << "\tB dtor f_adat=" << f_adat << endl; }
};


/// Trükkös makró
#define _(x)  std::cout << #x << std::endl; x

int main() {
	_( A a2 = 2; )
	_( A a50 = '2'; )
	_( A a1 = true; )
	_( return 0; )
}
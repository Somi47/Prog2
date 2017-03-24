#include <iostream>

using namespace std;

class A
{
public:
	int i;
	A( int asd ) { cout << "A ctor\n"; i = asd; };
	A( const A& a ) { cout << "A copy\n"; i = a.i; };
	~A() { cout << "A dtor\n"; };
};

class B
{
public:
	A a;
	B() : a( 0 ) { cout << "B ctor\n"; };
	B( const B& b ) : a( 0 ) { cout << "B copy\n"; a = b.a; };
	~B() { cout << "B dtor\n"; };
};

int main( int argc, char** argv )
{
	B b1;
	B b2 = b1;

	return 0;
}

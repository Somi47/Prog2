/**
 * Ohmikus ellenállást megvalósitó osztály megvalósítása
 */
#include "resistor.h"

double Resistor::defR = 127;

Resistor::Resistor()
	: R( defR )
{
}

Resistor::Resistor( double r )
	: R( r )
{
}

void Resistor::setDef( double r )
{
	defR = r;
}

Resistor Resistor::operator+( const Resistor& r ) const
{
	if( R < 0 )
		throw "WGGAW5";

	if( r.R < 0 )
		throw "WGGAW5";

	return Resistor( R + r.R );
}

Resistor Resistor::operator%( const Resistor& r ) const
{
	if( R < 0 )
		throw "WGGAW5";

	if( r.R < 0 )
		throw "WGGAW5";

	if( R + r.R <= 0 )
		throw "WGGAW5";

	return Resistor( (R * r.R) / (R + r.R)  );
}

Resistor operator*( int n, const Resistor& r )
{
	if( n <= 0 )
		throw "WGGAW5";

	if( r.getR() <= 0 )
		throw "WGGAW5";

	return n * r.getR();
}
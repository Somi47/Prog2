#include "potmeter.h"


/**
 *  Itt valósítsa meg a SimPoti osztály tagfüggvényit!
 */

SimPoti::SimPoti( double r )
	: R( r )
	, pos( 50 )
{
}

int SimPoti::getPos() const
{
	return pos;
}

Resistor SimPoti::getRes() const
{
	Resistor R1( R * pos / 100 );
	Resistor R2( R * ( 100 - pos ) / 100 );

	return R1 % R2;
}

int SimPoti::operator++()
{
	if( pos >= 99 )
		return pos;

	return ++pos;
}

int SimPoti::operator--()
{
	if( pos <= 1 )
		return pos;

	return --pos;
}
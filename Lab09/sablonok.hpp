#pragma once
#include <iostream>

template< typename T >
class nagyobbfunct
{
public:
	bool operator()( T cmpleft, T cmpright ) { return cmpleft > cmpright; }
};

template< typename T >
class nagyobb_mint
{
	T value;
public:
	nagyobb_mint( T v ) : value( v ) {}
	bool operator()( T cmpwith ) { return cmpwith > value; }
};

template< typename T >
void printEach( T beg, T end, std::ostream &out = std::cout, const char *endstr = NULL )
{
	if( endstr == NULL )
		endstr = "";

	while( beg != end )
	{
		T next = beg;
		if( ++next == end )
			break;

		out << *beg << endstr;
		++beg;
	}

	out << *beg << std::endl;
}

template< typename T >
int szamol_ha_negativ( T beg, T end )
{
	int iSum = 0;

	while( beg != end )
	{
		if( *beg < 0 )
			++iSum;

		++beg;
	}

	return iSum;
}

template< typename T, typename funkt >
T kivalaszt( T beg, T end, funkt func )
{
	while( beg != end )
	{
		T next = beg;
		if( func( *(beg), *(++next) ) )
			return beg;

		++beg;
	}

	return end;
}


template< typename T, typename predi >
int szamol_ha( T beg, T end, predi func )
{
	int iSum = 0;

	while( beg != end )
	{
		if( func( *beg ) )
			++iSum;

		++beg;
	}

	return iSum;
}
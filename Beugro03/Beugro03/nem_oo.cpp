#include <string.h>
#include <math.h>
#include <iostream>
#include "nem_oo.h"


namespace sajat
{

int atoi(const char *p, int base)
{
	int iLenght     = strlen( p );
	int iValueTotal = 0;
	int iDigit      = 1;

	for( int i = iLenght - 1; i >= 0; --i )
	{
		char cActual = p[i];
		int iValueActual;
		/**/ if( cActual >= '0' && cActual <= '9' )
		{
			iValueActual = cActual - '0';
		}
		else if( cActual >= 'a' && cActual <= 'z' )
		{
			iValueActual = cActual - 'a' + 9;
		}
		else if( cActual >= 'A' && cActual <= 'Z' )
		{
			iValueActual = cActual - 'A' + 9;
		}
		else
		{
			std::cout <<  cActual << " character has unknown value. Value 0 is used instead." << std::endl;
			iValueActual = 0;
		}

		iValueTotal = iValueActual * iDigit;
		iDigit = iDigit * base;
	}

	return iValueTotal;
}

char *strcat( const char *p1, const char *p2 )
{
	int iLength1   = strlen( p1 );
	int iLength2   = strlen( p2 );
	int iLengthNew = iLength1 + iLength2 + 1;

	char *strNew = new char[iLengthNew];
	int iPosInNew = 0;
	for( int i = 0; i < iLength1; ++i )
	{
		strNew[iPosInNew] = p1[i];
		++iPosInNew;
	}

	for( int i = 0; i < iLength2; ++i )
	{
		strNew[iPosInNew] = p2[i];
		++iPosInNew;
	}

	strNew[iPosInNew] = '\0';
	return strNew;
}

void swap( int& r1, int& r2 )
{
	int tmp = r1;
	r1 = r2;
	r2 = tmp;
}

char *unique( char *first, char *last )
{
	char *iterator      = first;
	char *iteratorInNew = first;
	while( iterator <= last )
	{
		if( *iteratorInNew != *iterator )
		{
			*iteratorInNew = *iterator;
			++iteratorInNew;
		}

		++iterator;
	}

	return iteratorInNew;
}

};
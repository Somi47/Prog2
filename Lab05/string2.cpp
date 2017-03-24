/**
 *
 * \file string2.cpp
 *
 * Itt kell megvalósítania a hiányzó tagfüggvényeket.
 * Segítségül megadtuk a C-ben megírt változatban (string1.c) használt függvényneveket.
 *
 * Ha valamit INLINE-ként valósít meg, akkor annak a .h-ba kell kerülnie,
 * akár kívül akár osztályon belül definiálja. (Az inline függvényeknek minden
 * fordítási egységben elérhetőknek kell lenniük)
 * *
 * A teszteléskor ne felejtse el beállítani a header állományban az ELKESZULT makrót.
 * A VC saját memóriafogyás ellenőrzője csak debug módban (Debug->Start) működik!
 *
 */

#ifdef _MSC_VER
// MSC ne adjon figyelmeztető üzenetet a C sztringkezelő függvényeire
  #define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>             // Kiíratáshoz
#include <cstring>              // Sztringműveletekhez

#include "memtrace.h"           // a standard headerek után kell lennie
#include "string2.h"



/// Konstruktor: egy char karakterből (createStrFromChar)

String::String( char c )
{
	len = 1;
	pData = new char[ 2 ];
	pData[ 0 ] = c;
	pData[ 1 ] = '\0';
}

/// Destruktor (disposeString)

String::~String()
{
	delete[] pData;
}

/// Konstruktor: egy nullával lezárt char sorozatból (createStringFromCharStr)

String::String( const char *pOther )
{
	len = strlen( pOther );
	pData = new char[ len + 1 ];

	for( int i = 0; i < len; ++i )
	{
		pData[ i ] = pOther[ i ];
	}

	pData[ len ] = '\0';
}

/// Másoló konstruktor

String::String( const String &other )
{
	len = other.len;
	pData = new char[ len + 1 ];

	for( int i = 0; i < len; ++i )
	{
		pData[ i ] = other.pData[ i ];
	}

	pData[ len ] = '\0';
}


/// operator=
String &String::operator=( const String &other )
{
	if( &other == this )
		return *this;

	len = other.len;
	delete[] pData;
	pData = new char[ len + 1 ];

	for( int i = 0; i < len; ++i )
	{
		pData[ i ] = other.pData[ i ];
	}

	pData[ len ] = '\0';

	return *this;
}

/// [] operátorok: egy megadott indexű elem REFERENCIÁJÁVAL térnek vissza.
/// indexhiba esetén dobjon egy const char * típusú hibát!
char &String::operator[]( int iPos )
{
	if( iPos >= len )
		throw "WGGAW5";

	return pData[ iPos ];
}

const char String::operator[]( int iPos ) const
{
	if( iPos >= len )
		throw "WGGAW5";

	return pData[ iPos ];
}
/// + operátorok, ami két sztringet ad össze (concatString)
String String::operator+( const String &right ) const
{
	String created;
	created.len = len + right.len;
	delete[] created.pData;
	created.pData = new char[ created.len + 1 ];

	int iPosInCreated = 0;
	for( int i = 0; i < len; ++i )
	{
		created.pData[ iPosInCreated ] = pData[ i ];
		++iPosInCreated;
	}

	for( int i = 0; i < right.len; ++i )
	{
		created.pData[ iPosInCreated ] = right.pData[ i ];
		++iPosInCreated;
	}

	created.pData[ created.len ] = '\0';

	return created;
}

String operator+( const char &c, const String &right )
{
	return String( c ) + right;
}

/// << operator, ami kiír az ostream-re

std::ostream &operator<<( std::ostream &stream, const String &str )
{
	stream << str.c_str();
	return stream;
}

/// >> operátor, ami beolvas az istreamről egy szót

std::istream &operator>>( std::istream &stream, String &str )
{
	char c[1024];
	if( !( stream >> c ) )
		return stream;

	int iRealBeg = 0;
	while( iswspace( c[ iRealBeg ] ) )
		++iRealBeg;

	int iRealEnd = strlen( c );
	while( iswspace( c[ iRealEnd ] ) )
		--iRealEnd;

	c[ iRealEnd + 1 ] = '\0';

	str = String( c + iRealBeg );

	return stream;
}
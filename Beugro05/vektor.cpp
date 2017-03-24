#include "vektor.h"

size_t Vektor::defSize = 12;
double Vektor::defValue = 52;

Vektor::Vektor( const Vektor& other )
{
	nElements  = other.nElements;

	pVec = new double[ nElements ];
	for( size_t iPos = 0; iPos < nElements; ++iPos )
		pVec[ iPos ] = other.pVec[ iPos ];
}

Vektor::~Vektor()
{
	delete[] pVec;
}

Vektor& Vektor::operator=( const Vektor& other )
{
	if( nElements != other.nElements )
	{
		nElements = other.nElements;
		delete[] pVec;
		pVec = new double[ nElements ];
	}

	for( size_t iPos = 0; iPos < nElements; ++iPos )
		pVec[ iPos ] = other.pVec[ iPos ];

	return *this;
}

double& Vektor::operator[]( size_t idx )
{
	if( idx >= nElements )
		throw "WGGAW5";

	return pVec[ idx ];
}

const double& Vektor::operator[]( size_t idx ) const
{
	if( idx >= nElements )
		throw "WGGAW5";

	return pVec[idx];
}

Vektor operator*( double val, const Vektor& vec )
{
	Vektor vektorCopy( vec );

	for( size_t i = 0; i < vektorCopy.size(); i++ )
		vektorCopy[ i ] *= val;

	return vektorCopy;
}

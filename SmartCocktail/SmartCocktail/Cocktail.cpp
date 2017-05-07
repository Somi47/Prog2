#include "Cocktail.h"
#include "Ingredient.h"
#include "Liquid.h"
#include "Alcohol.h"
#include "Solid.h"
#include <string.h>
#include <iostream>
#include <sstream>
#include <stdexcept>

Cocktail::Cocktail()
	: m_strName( "No Name Set" )
{
}

Cocktail::Cocktail( const Cocktail &other )
	: m_strName( other.m_strName )
{
	m_arrIngredients.ReserveTotal( other.m_arrIngredients.GetReserved() );

	for( int i = 0; i < other.m_arrIngredients.GetCount(); ++i )
	{
		m_arrIngredients[ i ] = other.m_arrIngredients[ i ]->Clone();
	}
}

Cocktail::~Cocktail()
{
	for( int i = 0; i < m_arrIngredients.GetCount(); ++i )
	{
		delete m_arrIngredients[ i ];
	}
}

void Cocktail::SetName( const std::string &strName )
{
	m_strName = strName;
}

std::string Cocktail::GetName() const
{
	return m_strName;
}

void Cocktail::AddIngredient( Ingredient *pIngredient )
{
	m_arrIngredients.InsertLast( pIngredient );
}

void Cocktail::DelIngredient( int iPos )
{
	if( iPos >= 0 && iPos < m_arrIngredients.GetCount() )
	{
		delete m_arrIngredients[ iPos ];
		m_arrIngredients.RemovePosition( iPos );
	}
}

Ingredient *Cocktail::GetIngredient( int iPos )
{
	if( iPos >= m_arrIngredients.GetCount() )
		return NULL;

	return m_arrIngredients.GetPosition( iPos );
}

int Cocktail::GetIngredientCount()
{
	return m_arrIngredients.GetCount();
}

double Cocktail::GetAlcoholPercent() const
{
	int    iTotalVolumeInML   = 0;
	double dAlcoholVolumeInML = 0;
	for( int i = 0; i < m_arrIngredients.GetCount(); ++i )
	{
		Ingredient *pIngredient = m_arrIngredients[ i ];
		if( strcmp( pIngredient->GetUnit().c_str(), "cl" ) != 0 )
			continue;

		iTotalVolumeInML   += pIngredient->GetQuantity();
		dAlcoholVolumeInML += pIngredient->GetQuantity() * pIngredient->GetAlcoholPercent();
	}

	return dAlcoholVolumeInML / iTotalVolumeInML;
}

void Cocktail::WriteData( std::ostream &os ) const
{
	os << m_strName << std::endl;

	for (int i = 0; i < m_arrIngredients.GetCount(); ++i)
	{
		m_arrIngredients[i]->WriteData( os );
	}

	os << "COCKTAIL_END";
}

void Cocktail::ReadData( std::istream &is )
{
	std::getline( is, m_strName );

	std::string strData;
	while( std::getline( is, strData ) )
	{
		if( strcmp( strData.c_str(), "COCKTAIL_END" ) == 0 )
			break;

		/**/ if( strcmp( strData.c_str(), "LIQUID" ) == 0 )
			m_arrIngredients.InsertLast( new Liquid() );
		else if( strcmp( strData.c_str(), "ALCOHOL" ) == 0 )
			m_arrIngredients.InsertLast( new Alcohol() );
		else if( strcmp( strData.c_str(), "SOLID" ) == 0 )
			m_arrIngredients.InsertLast( new Solid() );
		else
			throw std::runtime_error( "Not valid data stream" );

		m_arrIngredients.GetPosition( m_arrIngredients.GetCount() - 1 )->ReadData( is );
	}


}
#include "Cocktail.h"
#include "Ingredient.h"

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
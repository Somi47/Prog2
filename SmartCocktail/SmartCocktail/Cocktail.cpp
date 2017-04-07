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

std::string Cocktail::GetDataString()
{
	std::string strData = m_strName;
	strData += "\n";

	for (int i = 0; i < m_arrIngredients.GetCount(); ++i)
	{
		strData += m_arrIngredients[i]->GetDataString();
		strData += INGREDIENT_SEPARATOR;
	}

	return strData;
}